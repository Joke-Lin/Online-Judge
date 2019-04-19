#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef pair<int,int> P; // First 最短距离 Second 顶点编号
struct edge{ int to,cost; };

const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
int n,m;
vector<edge> G[maxn];
int family[5];

vector<int> dj(int s) {
    vector<int> res(n+1, INF);
    priority_queue<P,vector<P>,greater<P> > que;
    res[s] = 0;
    que.push(P(0, s));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(res[v] < p.first) continue;
        for(int i = 0;i < G[v].size();i++) {
            edge e = G[v][i];
            if(res[e.to] > res[v] + e.cost) {
                res[e.to] = res[v] + e.cost;
                que.push(P(res[e.to],e.to));
            }
        }
    }
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i < 5;i++) scanf("%d",family + i);
    sort(family,family+5);
    for(int i = 0;i < m;i++) {
        int from, to, cost; scanf("%d%d%d", &from, &to, &cost);
        G[from].push_back({to,cost});
        G[to].push_back({from,cost});
    }
    map<int, vector<int>> resDj;
    resDj.insert(make_pair(1,dj(1)));
    for(int i = 0;i < 5;i++) {
        resDj.insert(make_pair(family[i],dj(family[i])));
    }
    int res = INF;
    do {
        int temp = resDj[1][family[0]];
        for(int i = 0;i < 4;i++) {
            temp += resDj[family[i]][family[i+1]];
        }
        res = min(res,temp);
    } while(next_permutation(family,family+5));
    printf("%d\n", res);
    return 0;
}