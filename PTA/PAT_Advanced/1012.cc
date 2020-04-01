#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#define LOCAL

using namespace std;

const int maxn = 2001;

struct Stu {
    int id;
    int score[4]; // A C M E 对应的分数
}stu[maxn];

const int maxn_ = 1e6;

bool is_exist[maxn_];   // 判断是否存在
int best_rank[maxn_];   // 记录对应的最好成绩
int best_rank_type[maxn_];  // 记录最好成绩对应的学科

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    // 初始化
    memset(is_exist, 0, sizeof(is_exist));
    memset(best_rank, 0x3f, sizeof(best_rank));

    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++) {
        scanf("%d %d %d %d",&stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3 + 0.5; // 四舍五入
        is_exist[stu[i].id] = true; // 标记为存在
    }
    // 四个分数排序 按 A C M E 的顺序
    // 相同的情况后不能覆盖前（优先级）
    for(int i = 0;i < 4;i++) {
        sort(stu, stu+n, [i](Stu &a, Stu &b){ return a.score[i] > b.score[i]; });
        if(best_rank[stu[0].id] != 0) {
            best_rank[stu[0].id] = 0;
            best_rank_type[stu[0].id] = i;
        }
        int last_rank = 0;
        // 注意处理并列。。
        for(int j = 1;j < n;j++) {
            if(stu[j-1].score[i] != stu[j].score[i]) {
                last_rank = j;
            }
            if(best_rank[stu[j].id] > last_rank) {
                best_rank[stu[j].id] = last_rank;
                best_rank_type[stu[j].id] = i;
            }
        }
    }
    const char type[] = {'A', 'C', 'M', 'E'};
    for(int i = 0;i < m;i++) {
        int id; scanf("%d", &id);
        if(is_exist[id]) {
            printf("%d %c\n", best_rank[id] + 1, type[best_rank_type[id]]);
        }
        else {
            printf("N/A\n");
        }
    }
    return 0;
}