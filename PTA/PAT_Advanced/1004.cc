#include <cstdio>
#include <vector>
#include <algorithm>
#define LOCAL

using namespace std;

const int maxn = 101;
vector<int> G[maxn];
bool visited[maxn] = {0};
int layer_num[maxn] = {0}, max_layer = 0;

// 避免A，B 都有子节点C 所以引入 visited 如果是普通的多叉树 则不需要
void bfs(int root, int layer = 0) {
    max_layer = max(max_layer, layer);
    if(visited[root]) {
        return;
    }
    visited[root] = true;
    if(G[root].size() == 0) {
        layer_num[layer]++;
        return;
    }
    for(int i = 0;i < G[root].size();i++) {
        bfs(G[root][i], layer+1);
    }
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0;i < m;i++) {
        int root, child_num; scanf("%d %d", &root, &child_num);
        for(int j = 0;j < child_num;j++) {
            int child; scanf("%d", &child);
            G[root].push_back(child);
        }
    }
    bfs(1);
    for(int i = 0;i <= max_layer;i++) {
        printf("%d", layer_num[i]);
        if(i != max_layer) {
            printf(" ");
        }
    }
    return 0;
}