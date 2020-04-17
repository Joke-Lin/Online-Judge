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

const int maxn = 1001;
bool dp[maxn][maxn];


int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(dp, 0, sizeof(dp));
    char s[maxn];
    fgets(s, maxn, stdin);
    int len = strlen(s);
    for(int i = 0;i < len;i++) {
        dp[i][i] = true;
    }
    int res = 1;
    for(int i = 1;i < len;i++) {
        if(s[i] == s[i-1]) {
            dp[i][i-1] = true;
            res = max(res, 2);
        }
        for(int j = i-2;j >= 0;j--) {
            if(dp[i-1][j+1] && s[i] == s[j]) {
                dp[i][j] = true;
                res = max(res, i - j + 1);
            }
        }
    }
    printf("%d", res);
    return 0;
}