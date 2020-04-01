#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#define LOCAL

using namespace std;

const int maxn = 1001;

struct Customer {
    int win_index;
    int end_time;
    bool operator < (const Customer& other) const {
        // 同时离开 选择编号小的
        return end_time != other.end_time ? end_time > other.end_time : win_index > other.win_index;
    }
}customers[maxn];

int cost_time[maxn];    // 用户的花费时间
int end_time[maxn];     // 每个用户的结束时间
int win_cur_time[21];   // 当前窗口等待区清空的最晚时间

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(win_cur_time, 0, sizeof(win_cur_time));
    memset(end_time, 0xff, sizeof(end_time));
    int n, m, k, q; scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 0;i < k;i++) {
        scanf("%d", cost_time+i);
    }
    priority_queue<Customer> que;
    for(int i = 0;i < k && i < n*m;i++) {
        win_cur_time[i%n] += cost_time[i];
        end_time[i] = win_cur_time[i%n];
        que.push({i%n, end_time[i]});
    }
    for(int i = n*m;i < k;i++) {
        Customer temp = que.top(); que.pop();   // 获取最早离开的
        win_cur_time[temp.win_index] += cost_time[i];
        end_time[i] = win_cur_time[temp.win_index];
        temp.end_time = end_time[i];
        que.push(temp);
    }
    int tar;
    for(int i = 0;i < q;i++) {
        scanf("%d", &tar);
        int mins = end_time[tar-1];
        if(mins - cost_time[tar-1] >= 540) {
            printf("Sorry\n");
        }
        else {
            printf("%02d:%02d\n", 8+mins/60, mins%60);
        }
    }
    return 0;
}