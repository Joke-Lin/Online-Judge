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
const int maxn = 1e4+2;
char str1[maxn], str2[maxn];
bool flag[300];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(flag, 0, sizeof(flag));
    fgets(str1, maxn, stdin);
    fgets(str2, maxn, stdin);
    int len  = strlen(str2);
    for(int i = 0;i < len;i++) {
        flag[str2[i]] = true;
    }
    len  = strlen(str1);
    for(int i = 0;i < len;i++) {
        if(!flag[str1[i]]) {
            printf("%c", str1[i]);
        }
    }

    return 0;
}