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

const int maxn = 31;
int postorder[maxn];
int inorder[maxn];

struct Node {
    int val;
    Node *left = NULL, *right = NULL;
};

Node* getTree(int post_i, int l, int r) {
    if(l > r) {
        return NULL;
    }
    Node *t_root = new Node();
    int mid = -1;
    for(int i = l;i <= r;i++) {
        if(inorder[i] == postorder[post_i]) {
            mid = i;
        }
    }
    t_root->val = inorder[mid];
    t_root->right = getTree(post_i-1, mid+1, r);
    t_root->left = getTree(post_i - (r - mid) - 1, l, mid-1);
    return t_root;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", postorder + i);
    }
    for(int i = 0;i < n;i++) {
        scanf("%d", inorder + i);
    }
    Node *root = getTree(n-1, 0, n-1);
    printf("%d", root->val);
    // 层序遍历
    queue<Node*> que;
    que.push(root->left);
    que.push(root->right);
    while(!que.empty()) {
        Node *t = que.front(); que.pop();
        if(t == NULL) {
            continue;
        }
        printf(" %d",t->val);
        que.push(t->left);
        que.push(t->right);
    }
    return 0;
}