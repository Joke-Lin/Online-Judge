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
#include <set>
#include <stack>
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

const int maxn = 1001;
int weight[maxn];
int init_order[maxn];
int ranks[maxn];
int mid[maxn];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m, v; scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++) {
        scanf("%d", weight+i);
    }
    for(int i = 0;i < n;i++) {
        scanf("%d", init_order+i);
    }
    int t = n;
    while(true) {
        int g = t/m + ((t%m) != 0);
        // SEE(g);
        for(int i = 0;i < g;i++) {
            int ed = min(t, (i+1)*m);
            int max_index = init_order[i*m];
            // 找出最大的
            for(int j = i*m;j < ed;j++) {
                if(weight[init_order[j]] > weight[max_index]) {
                    max_index = init_order[j];
                }
            }
            // 失败的名词都一样
            for(int j = i*m;j < ed;j++) {
                if(init_order[j] != max_index) {
                    ranks[init_order[j]] = g+1;
                }
                else {
                    // mid[i] = max_index;
                }
            }
            init_order[i] = max_index;
        }
        t = g;
        if(g == 1) {
            ranks[init_order[0]] = 1;
            break;
        }
    }
    for(int i = 0;i < n;i++) {
        printf("%d%s", ranks[i], i == n-1 ? "" : " ");
    }
    return 0;
}