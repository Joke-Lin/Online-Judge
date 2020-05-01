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
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10001;
int nums[maxn];
int order[201];
int dp[maxn];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m, k;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0;i < m;i++) {
        scanf("%d", order+i);
    }
    scanf("%d", &k);
    for(int i = 0;i < k;i++) {
        scanf("%d", nums+i);
    }
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= k;j++) {
            if(nums[j-1] == order[i-1]) {
                dp[j] = dp[j-1] + 1;
            }
            else {
                dp[j] = max(dp[j-1], dp[j]);
            }
            res = max(res, dp[j]);
        }
    }
    printf("%d", res);
    return 0;
}