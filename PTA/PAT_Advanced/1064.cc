#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iterator>
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

int Tree[1010][2];
int vals[1010];
int nodes[1010];

int layers;

void midorder(int root, int &tar) {
    // 遍历左边
    if(Tree[root][0] != -1) {
        midorder(Tree[root][0], tar);
    }
    nodes[root] = vals[tar++];
    // 遍历右边
    if(Tree[root][1] != -1) {
        midorder(Tree[root][1], tar);
    }
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(Tree, -1, sizeof(Tree));
    int n; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", vals + i);
    }
    int l, r;
    // 构建树结构
    for(int i = 0;i < n;i++) {
        l = 2*i+1, r = 2*i+2;
        if(l < n) {
            Tree[i][0] = l;
        }
        if(r < n) {
            Tree[i][1] = r;
        }
    }
    sort(vals, vals+n);
    int cnt = 0;
    // 通过中序遍历
    midorder(0, cnt);
    //层序遍历
    queue<int> q;
    q.push(0);
    cnt = 0; 
    while(!q.empty()) {
        int r = q.front(); q.pop();
        cnt++;
        printf("%d%s", nodes[r], cnt == n ? "" : " ");
        if(Tree[r][0] != -1) {
            q.push(Tree[r][0]);
        }
        if(Tree[r][1] != -1) {
            q.push(Tree[r][1]);
        }
    }
    return 0;
}
