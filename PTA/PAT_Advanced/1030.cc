#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
#define LOCAL

using namespace std;
typedef pair<int, int> P;
struct edge {int to, distance, cost;};

const int maxn = 502;
vector<edge> Map[maxn];
int prev_node[maxn], min_dis[maxn], weigth[maxn];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(min_dis, 0x3f, sizeof(min_dis));
    int n, m, st, ed; scanf("%d %d %d %d", &n, &m, &st, &ed);
    for(int i = 0;i < m;i++) {
        int s, t, dis, cost; scanf("%d %d %d %d", &s, &t, &dis, &cost);
        Map[s].push_back({t, dis, cost});
        Map[t].push_back({s, dis, cost});
    }
    min_dis[st] = 0;
    weigth[st] = 0;
    prev_node[st] = -1;
    priority_queue<P, vector<P>, greater<P> > que; que.push({0, st});
    while(!que.empty()) {
        P top = que.top(); que.pop();
        if(min_dis[top.second] < top.first) {
            continue;
        }
        for(int i = 0;i < Map[top.second].size();i++) {
            edge e = Map[top.second][i];
            if(min_dis[e.to] > min_dis[top.second] + e.distance) {
                min_dis[e.to] = min_dis[top.second] + e.distance;
                weigth[e.to] = weigth[top.second] + e.cost;
                prev_node[e.to] = top.second;
                que.push({min_dis[e.to], e.to});
            }
            else if(min_dis[e.to] == min_dis[top.second] + e.distance) {
                if(weigth[e.to] > weigth[top.second] + e.cost) {
                    weigth[e.to] = weigth[top.second] + e.cost;
                    prev_node[e.to] = top.second;
                }
            }
        }
    }
    vector<int> path;
    int next = ed;
    while(next != -1) {
        path.push_back(next);
        next = prev_node[next];
    }
    for(int i = path.size()-1;i >= 0;i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d", min_dis[ed], weigth[ed]);
    return 0;
}