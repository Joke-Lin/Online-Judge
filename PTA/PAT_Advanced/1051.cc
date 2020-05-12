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

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int m, n, k; scanf("%d %d %d", &m, &n, &k);
    while(k--) {
        stack<int> s;
        int maxn = 0;
        bool flag = true;
        for(int i = 0;i < n;i++) {
            int v; scanf("%d", &v);
            if(!flag) {
                continue;
            }
            if(v > maxn) {
                for(int j = maxn+1;j <= v;j++) {
                    s.push(j);
                }
                if(s.size() > m) {
                    flag = false;
                }
                maxn = v;
                s.pop();
            }
            else {
                if(v != s.top()) {
                    flag = false;
                }
                else {
                    s.pop();
                }
            }
        }
        if(flag) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}