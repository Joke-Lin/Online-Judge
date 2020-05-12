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

const int maxn = 102;

vector<int> tree[maxn];
int w[maxn];

int n, m, s;

void search(int root, int tar, vector<int> &path) {
    // 大于目标值 直接返回 剪枝
    if(w[root] > tar) {
        return;
    }
    path.push_back(w[root]);
    // 遍历到叶节点
    if(tree[root].size() == 0) {
        if(w[root] == tar) {
            int len = path.size();
            for(int i = 0;i < len;i++) {
                printf("%d%s", path[i], i == len - 1 ? "\n" : " ");
            }
        }
        path.pop_back();
        return;
    }
    int len = tree[root].size();
    tar = tar - w[root];
    for(int i = 0;i < len;i++) {
        search(tree[root][i], tar, path);
    }
    path.pop_back();
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0;i < n;i++) {
        scanf("%d", w+i);
    }
    for(int i = 0;i < m;i++) {
        int st, num, v; scanf("%d %d", &st, &num);
        for(int j = 0;j < num;j++) {
            scanf("%d", &v);
            tree[st].push_back(v);
        }
    }
    // 从大到小排序
    for(int i = 0;i < maxn;i++) {
        sort(tree[i].begin(), tree[i].end(), [](int a, int b) {return w[a] > w[b];});
    }
    vector<int> mid;
    search(0, s, mid);
    return 0;
}