#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#define LOCAL

using namespace std;

const int maxn = 1e4+2;

vector<int> G[maxn];    // 邻接表
bool visited[maxn];     // 检查是否遍历完
int max_height = 0;
set<int> res;

// DFS 遍历连接图 获得连通分量
void dfs(int root) {
    visited[root] = true;
    for(int i = 0;i < G[root].size();i++) {
        if(!visited[G[root][i]]) {
            dfs(G[root][i]);
        }
    }
}

void getDeepest(int root, set<int> &height_set, int heights = 0) {
    visited[root] = true;
    bool flag = true;
    for(int i = 0;i < G[root].size();i++) {
        if(!visited[G[root][i]]) {
            flag = false;
            getDeepest(G[root][i], height_set, heights+1);
        }
    }
    // 叶节点
    if(flag) {
        if(max_height == heights) {
            height_set.insert(root);
        }
        else if(max_height < heights) {
            height_set.clear();
            height_set.insert(root);
            max_height = heights;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    for(int i = 0;i < n-1;i++) {
        int a, b; scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memset(visited, 0, sizeof(visited));
    int components = 0;
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            dfs(i);
            components++;
        }
    }
    if(components > 1) {
        printf("Error: %d components", components);
    }
    else {
        set<int> st_points, ed_points;
        memset(visited, 0, sizeof(visited));
        getDeepest(1, st_points);
        memset(visited, 0, sizeof(visited));
        getDeepest(*st_points.begin(), ed_points);
        for(auto i : ed_points) {
            st_points.insert(i);
        }
        for(auto i : st_points) {
            printf("%d\n", i);
        }
    }
    return 0;
}