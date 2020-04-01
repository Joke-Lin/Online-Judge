#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

const int maxn = 1001;

vector<int> G[maxn];    // 邻接表
bool visited[maxn];     // 检查是否遍历完

// DFS 遍历连接图 获得连通分量
void dfs(int root) {
    visited[root] = true;
    for(int i = 0;i < G[root].size();i++) {
        if(!visited[G[root][i]]) {
            dfs(G[root][i]);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    for(int i = 0;i < m;i++) {
        int st, to; scanf("%d %d", &st, &to);
        G[st].push_back(to);
        G[to].push_back(st);
    }
    for(int i = 0;i < k;i++) {
        memset(visited, 0, sizeof(visited));
        int e; scanf("%d", &e);
        visited[e] = true;  // 将此点标记为访问过，则不会进入和e相关的路径中
        int count = 0;
        for(int j = 1;j <= n;j++) {
            if(!visited[j]) {
                dfs(j);
                count++;
            }
        }
        printf("%d\n", count - 1);
    }
    return 0;
}