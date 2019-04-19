#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
 
using namespace std;
 
typedef long long LL;
 
const LL maxn = 1000000 + 5;
LL n, m, r, a[maxn], c[maxn];
vector <LL> g[maxn];
 
void getInt(LL &x) {
    x = 0; char ch = getchar(); LL sgn = 1;
    while (ch > '9' || ch < '0') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    x *= sgn;
}
void getInt(LL &x, LL &y) { getInt(x); getInt(y); }
void getInt(LL &x, LL &y, LL &z) { getInt(x); getInt(y); getInt(z); }
 
inline LL lowbit(LL x) {
    return x & (-x);
}
 
void add(LL pos, LL k) {
    while (pos <= n) {
        c[pos] += k;
        pos += lowbit(pos);
    }
}
 
LL sum(LL pos) {
    LL ret = 0;
    while (pos >= 1) {
        ret += c[pos];
        pos -= lowbit(pos);
    }
    return ret;
}
 
bool vis[maxn];
LL order[maxn], p = 0, sz[maxn], np[maxn];
void dfsInit() {
    for (LL i = 1; i <= n; ++i) sz[i] = 1;
}
LL dfs(LL u) {
    vis[u] = 1;
    for (auto v: g[u]) {
        if (!vis[v]) 
            sz[u] += dfs(v);
    }
    order[++p] = u;
    return sz[u];
}
void getNp() {
    for (LL i = 1; i <= n; ++i) {
        np[order[i]] = i;
    }
}
 
int main() {
    getInt(n, m, r);
    for (LL i = 1; i <= n; ++i) getInt(a[i]);
    LL tu, tv;
    for (LL i = 1; i <= n - 1; ++i) {
        getInt(tu, tv);
        g[tu].push_back(tv);
        g[tv].push_back(tu);
    }
    
    dfsInit();
    sz[r] = dfs(r);
    getNp();
    for(int i = 1;i <= n;i++) {
        cout << order[i] << " : " << sz[i] <<  " : " << np[i] << endl;
    }
    for (LL i = 1; i <= n; ++i) add(i, a[order[i]]);
    LL opt, opa, opx;
    for (LL i = 1; i <= m; ++i) {
        getInt(opt);
        switch(opt) {
            case 1: {
                getInt(opa, opx);
                add(np[opa], opx);
            } break;
            case 2: {
                getInt(opa);
                LL qsz = sz[opa];
				cout <<" shit: " <<  np[opa] << " " << qsz << endl;
                printf("%lld\n", sum(np[opa]) - sum(np[opa] - qsz));
            }
        }
    }
    return 0;
}