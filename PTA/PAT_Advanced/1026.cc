#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define LOCAL

using namespace std;
typedef pair<int, int> P;

struct Player {
    int arrival;
    int served;
    int isvip;
    bool operator < (const Player& another) {
        return arrival < another.arrival;
    }
};

const int maxn = 110, INF = 0x3f3f3f3f;
vector<Player> players; // 存储玩家
P tables[maxn]; // 桌子 first：释放时间 second：是否VIP
const int clock_8 = 8*3600, clock_21 = 21*3600;
int table_count[maxn];  // 计数
bool is_served[10001];  // 玩家是否被服务 针对VIP优先处理
int k, m, n;

void print_time(int sec) {
    int h = sec/3600;
    int m = (sec%3600)/60;
    int s = sec%60;
    printf("%02d:%02d:%02d", h, m, s);
}
// 打印 以及更新对应的数据
void push_serverd_player(int index, int table_pos, int served_time) {
    print_time(players[index].arrival); cout << " "; print_time(served_time); cout << " ";
    int wait = (served_time - players[index].arrival + 30)/60;
    printf("%d\n", wait);
    is_served[index] = true;
    table_count[table_pos]++;
    tables[table_pos].first = served_time + players[index].served;
}

// 返回VIP和非VIP的最小下标
P getMinTableIndex() {
    int index1 = -1, index2 = -1;
    for(int i = 0;i < k;i++) {
        if(tables[i].second) {
            if(index2 == -1 || tables[i].first < tables[index2].first) {
                index2 = i;
            }
        }
        else {
            if(index1 == -1 || tables[i].first < tables[index1].first) {
                index1 = i;
            }
        }
    }
    return {index1, index2};
}

// 处理没有人等待的情况 VIP的话要先看是否有空闲的VIP
void no_wait(int index) {
    // 获取空闲VIP和普通的最小下标
    int index1 = INF, index2 = INF;
    for(int i = 0;i < k;i++) {
        if(tables[i].second) {
            if(index2 == INF && tables[i].first < players[index].arrival) {
                index2 = i;
            }
        }
        else {
            if(index1 == INF && tables[i].first < players[index].arrival) {
                index1 = i;
            }
        }
    }
    int tar;
    if(players[index].isvip) {
        tar = index2 == INF ? index1 : index2;
    }
    else {
        tar = min(index1, index2);
    }
    push_serverd_player(index, tar, players[index].arrival);
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(table_count, 0, sizeof(table_count));
    memset(is_served, 0, sizeof(is_served));
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        int hh, mm, ss, p, tag;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p, &tag);
        int sec = hh*3600 + mm*60 + ss;
        p = p > 120 ? 120*60 : p*60;
        if(sec >= clock_21) {
            continue;
        }
        players.push_back({sec, p, tag});
    }
    sort(players.begin(), players.end());
    scanf("%d %d", &k, &m);
    for(int i = 0;i < k;i++) {
        tables[i] = {clock_8, 0};
    }
    // 防止全部都是普通或者VIP 导致获取下标函数返回没有意义的值
    tables[k++] = {clock_21, 0};
    tables[k++] = {clock_21, 1};
    for(int i = 0;i < m;i++) {
        int vip_pos; scanf("%d", &vip_pos);
        tables[vip_pos-1].second = 1;
    }
    int index = 0, len = players.size();
    while(index < len) {
        if(is_served[index]) {
            index++;
            continue;
        }
        Player p = players[index];
        P min_index = getMinTableIndex();
        // 后面的都不用处理了
        if(tables[min_index.first].first >= clock_21 && tables[min_index.second].first >= clock_21) {
            break;
        }
        int table_empty_time;
        // 普通的先空 意味着没有VIP位置 那么直接给等待的下一个
        if(tables[min_index.first].first < tables[min_index.second].first) {
            table_empty_time = tables[min_index.first].first;
            // 有人在等待
            if(p.arrival <= table_empty_time) {
                push_serverd_player(index, min_index.first, table_empty_time);
            }
            // 没人等
            else {
                no_wait(index);
            }
            index++;
        }
        // 存在空的VIP 位置 注意VIP普通同时为空
        else {
            table_empty_time = tables[min_index.second].first;
            // 寻找是否有等待的VIP 有则先给他位置 否则给下一个人
            int vip_pos = -1;
            for(int i = index;i < len;i++) {
                // Error 8:最后一个测试点卡。。已经处理的VIP 跳过
                if(is_served[i]) {
                    continue;
                }
                if(players[i].arrival <= table_empty_time) {
                    if(players[i].isvip) {
                        vip_pos = i;
                        break;
                    }
                }
                else {
                    break;
                }
            }
            // 有VIP在等
            if(vip_pos != -1) {
                // printf("index:%d vip:%d\n", index, vip_pos);
                push_serverd_player(vip_pos, min_index.second, table_empty_time);
            }
            // 没有VIP在等
            else {
                // 但有普通人等
                if(p.arrival <= table_empty_time) {
                    // 普通人也可以选择VIP的位置 看哪个小选哪个
                    int tar_pos = tables[min_index.first].first == tables[min_index.second].first ? min(min_index.second, min_index.first) : min_index.second;
                    push_serverd_player(index, tar_pos, table_empty_time);
                }
                // 没人等
                else {
                    no_wait(index);
                }
                index++;
            }
        }
    }
    for(int i = 0;i < k-2;i++) {
        printf("%d",table_count[i]);
        if(i != k-3) {
            printf(" ");
        }
    }
    return 0;
}