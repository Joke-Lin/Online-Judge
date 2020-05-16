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
    int m, n, v;
    scanf("%d %d", &m, &n);
    map<int, int> M;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf("%d", &v);
            M[v]++;
        }
    }
    int delta = (n*m) >> 1;
    for(auto k : M) {
        if(k.second > delta) {
            printf("%d", k.first);
            break;
        }
    }
    return 0;
}