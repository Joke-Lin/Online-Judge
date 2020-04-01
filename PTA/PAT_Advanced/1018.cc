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

const int maxn = 502;
const int INF = 0x3f3f3f3f;

typedef pair<int,int> P;    // P.first 为 起始点到 P.second 的最短路
struct edge {int to, cost;};// 边
vector<edge> G[maxn];       // 存储图的邻接矩阵
int weight[maxn];           // 每个站点的权值
int d[maxn];                // 对应点的最短路
vector<int> prev_node[maxn];        // 最短路的树结构
vector<vector<int>> shortest_paths; // 起始点到问题点的所有最短路

// DFS 获取路径
void dfs(int root, vector<int> temp = {}) {
    temp.push_back(root);
    if(prev_node[root].size() == 0) {
        shortest_paths.push_back(temp);
        return;
    }
    for(int i = 0;i < prev_node[root].size();i++) {
        dfs(prev_node[root][i], temp);
    }
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(d, 0x3f, sizeof(d));
    int c_max, n, problem, m; scanf("%d %d %d %d", &c_max, &n, &problem, &m);
    int temp;
    weight[0] = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d", &temp);
        weight[i] = c_max/2 - temp; // 正 表示carry 负 表示 back
    }
    int st, ed, cost;
    for(int i = 0;i < m;i++) {
        scanf("%d %d %d", &st, &ed, &cost);
        G[st].push_back({ed, cost});
        G[ed].push_back({st, cost});
    }
    priority_queue<P, vector<P>, greater<P>> que;
    d[0] = 0;
    que.push({0, 0});
    while(!que.empty()) {
        P t = que.top(); que.pop();
        if(d[t.second] < t.first) {
            continue;
        }
        for(int i = 0;i < G[t.second].size();i++) {
            edge e = G[t.second][i];
            if(d[e.to] > d[t.second] + e.cost) {
                prev_node[e.to] = {t.second};
                d[e.to] = d[t.second] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
            else if(d[e.to] == d[t.second] + e.cost) {
                prev_node[e.to].push_back(t.second);    // 添加前置节点
            }
        }
    }
    dfs(problem);
    int min_carry = INF, min_back = INF, min_index = 0;
    for(int i = 0;i < shortest_paths.size();i++) {
        int carry = 0, back = 0;
        for(int j = shortest_paths[i].size() - 2;j >= 0;j--) {
            // 坑点 必须按照路径的前进 方向改变对于数值，即后面节点的多余不能给前面节点使用
            int need = weight[shortest_paths[i][j]];
            if(need > 0) {
                carry += back - need > 0 ? 0 : need - back;
                back = back - need > 0 ? back - need : 0;
            }
            else {
                back += -need;
            }
        }
        if(carry < min_carry) {
            min_carry = carry;
            min_back = back;
            min_index = i;
        }
        else if(carry == min_carry && back < min_back) {
            min_back = back;
            min_index = i;
        }
    }
    printf("%d ", min_carry);
    for(int i = shortest_paths[min_index].size() - 1; i >= 0;i--) {
        printf("%d", shortest_paths[min_index][i]);
        if(i != 0) {
            printf("->");
        }
    }
    printf(" %d", min_back);
    return 0;
}