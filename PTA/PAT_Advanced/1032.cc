#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#define LOCAL

using namespace std;

map<int, int> link;
const int maxn = 1e5;
int st_1, st_2, ed_1, ed_2, n;
map<int, int> prev_1, prev_2;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    scanf("%d %d %d", &st_1, &st_2, &n);
    // 防止有两个字符串完全一样的情况。。
    prev_1[st_1] = -1;
    prev_2[st_2] = -2;
    for(int i = 0;i < n;i++) {
        int cur, next;
        char v;
        scanf("%d %c %d", &cur, &v, &next);
        link[cur] = next;
    }
    int cur = st_1;
    // 条件为link[cur].next != -1会TE 可能不会有-1结尾
    while(link.count(link[cur])) {
        prev_1[link[cur]] = cur;
        cur = link[cur];
    }
    ed_1 = cur;
    cur = st_2;
    while(link.count(link[cur])) {
        prev_2[link[cur]] = cur;
        cur = link[cur];
    }
    ed_2 = cur;
    if(ed_1 != ed_2) {
        printf("-1");
    } else {
        while(true) {
            if(prev_1[cur] != prev_2[cur]) {
                break;
            }
            cur = prev_1[cur];
        }
        printf("%05d", cur);
    }
    return 0;
}