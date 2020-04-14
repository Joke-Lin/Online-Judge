#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

const int maxn = 2*1e5 + 1, INF = 0x3f3f3f3f;
int a[maxn], b[maxn];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", a+i);
    }
    scanf("%d", &m);
    for(int i = 0;i < m;i++) {
        scanf("%d", b+i);
    }
    int mid_pos = (n+m+1)>>1, cnt = 0, index_a = 0, index_b = 0, mid_value;
    while(cnt++ < mid_pos) {
        int a_v = index_a < n ? a[index_a] : INF;
        int b_v = index_b < m ? b[index_b] : INF;
        if(a_v < b_v) {
            index_a++;
        } else {
            index_b++;
        }
        mid_value = min(a_v, b_v);
    }
    printf("%d", mid_value);
    return 0;
}