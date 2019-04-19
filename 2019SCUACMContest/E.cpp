#include <iostream>
#include <string>
#include <vector>
#include <map>
// http://www.cfzhao.com/2018/11/23/libreoj-144-dfs%E5%BA%8F1/
using namespace std;
typedef long long LL;

const LL maxn = 1000000 + 5;
int n,m,r;
int weight_begin[maxn] = {0}; // 初始权值
vector<LL> graph[maxn];
LL C[maxn] = {0};   // BIT 辅助数组
LL posInBit[maxn] = {0}; // 节点号到BIT的映射
LL order[maxn] = {0};   // 与 上相反
LL sonNum[maxn] = {0};  // 包括自己的子节点数
bool isVis[maxn];
LL index = 0;   // DFS 序列 编号


inline LL lowbit(LL x) {
    return x & (-x);
}
// BIT
LL sum(LL x) {
    LL res = 0;
    while(x >= 1) {
        res += C[x]; x -= lowbit(x);
    }
    return res;
}

void add(LL x, LL value) {
    while(x <= n) {
        C[x] += value; x += lowbit(x);
    }
}

bool init() {
    for(LL i = 1;i <= n;i++) {
        isVis[i] = false;
        sonNum[i] = 1;
        C[i] = 0;
    }
}

LL dfs(LL u) {
    isVis[u] = true;
    for(LL i = 0;i < graph[u].size();i++) {
        if(!isVis[graph[u][i]]) sonNum[u] += dfs(graph[u][i]);
    }
    order[++index] = u;
    return sonNum[u];
}


int main()
{
    scanf("%d%d%d",&n,&m,&r);
    for(int i = 1;i <= n;i++) scanf("%d",weight_begin + i);
    for(int i = 1;i < n;i++) {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    init();
    sonNum[r] = dfs(r);
    for(LL i = 1;i <= n;i++) {
        posInBit[order[i]] = i;
    }
    for(LL i = 1;i <= n;i++) add(i,weight_begin[order[i]]);
    int y, delt;
    for(LL i = 1;i <= m;i++) {
        int cmd; scanf("%d",&cmd);
        if(cmd == 1) {
            scanf("%d%d", &y, &delt);
            add(posInBit[y],delt);
        }
        else {
            scanf("%d",&y);
            printf("%lld\n",sum(posInBit[y]) - sum(posInBit[y] - sonNum[y]));
        }
    }
    return 0;
}