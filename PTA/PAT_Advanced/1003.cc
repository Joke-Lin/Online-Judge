#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

#define LOCAL
#define INF 0x3f3f3f3f
const int maxn = 501;

using namespace std;

typedef pair<int,int> P;    // P.first 为 起始点到 P.second 的最短路
struct edge {int to, cost;};
vector<edge> G[maxn];   // 存储图的邻接矩阵
int d[maxn];    // 对应点的最短路
int team_num[maxn]; // 每个城市对应点的救援队数量
int road_sum[maxn]; // 最短路数量
int team_sum[maxn]; // 节点最大权值和


int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m, s, t; scanf("%d %d %d %d", &n, &m, &s, &t);
    fill(d, d+maxn, INF); d[s] = 0;
    fill(road_sum, road_sum+maxn, 0);   // 开始全部为 0
    road_sum[s] = 1;    // 起点到自己有1条路
    for(int i = 0;i < n;i++) {
        scanf("%d", team_num+i);
        team_sum[i] = team_num[i];  // 都可以自己到自己，所以和team_num一样
    }
    // 读入图数据
    int t_s, t_t, t_cost;
    for(int i = 0;i < m;i++) {
        scanf("%d %d %d", &t_s, &t_t, &t_cost);
        G[t_s].push_back(edge{t_t, t_cost});
        G[t_t].push_back(edge{t_s, t_cost});
    }
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        P t = que.top(); que.pop();
        if(d[t.second] < t.first) {
            continue;
        }
        for(int i = 0;i < G[t.second].size();i++) {
            edge e = G[t.second][i];
            if(d[e.to] > d[t.second] + e.cost) {
                team_sum[e.to] = team_sum[t.second] + team_num[e.to];
                road_sum[e.to] = road_sum[t.second];
                d[e.to] = d[t.second] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
            else if(d[e.to] == d[t.second] + e.cost) {
                road_sum[e.to] += road_sum[t.second];
                if(team_sum[e.to] < team_sum[t.second] + team_num[e.to]) {
                    team_sum[e.to] = team_sum[t.second] + team_num[e.to];
                }
            }
        }
    }
    printf("%d %d", road_sum[t], team_sum[t]);
    return 0;
}