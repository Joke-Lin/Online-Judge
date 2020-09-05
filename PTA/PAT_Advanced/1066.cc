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

struct node {
    int val;
    node *left;
    node *right;
};

// 获取高度
int treeHeight(node *root) {
    if(root == NULL) {
        return 0;
    } else {
        return max(treeHeight(root->left),treeHeight(root->right)) + 1;
    }
}

// 返回高度差
int treeGetBalanceFactor(node *root) {
    if(root == NULL)
        return 0;
    else
        return treeHeight(root->left) - treeHeight(root->right);
}

// 单右旋 返回新的ROOT节点
node* treeRotateRight(node* root) {
    node* left = root->left;
    
    root->left = left->right; // 将将要被抛弃的节点连接为旋转后的 root 的左孩子
    left->right = root; // 调换父子关系
    // 这里高度就不更新了，用到的时候直接递归获取
    return left;
}

// 单左旋 返回新的ROOT节点
node* treeRotateLeft(node* root) {
    node* right = root->right;

    root->right = right->left;
    right->left = root;

    return right;
}

node* treeRebalance(node* root) {
    int factor = treeGetBalanceFactor(root);
    if(factor > 1 && treeGetBalanceFactor(root->left) > 0) // LL
        return treeRotateRight(root);
    else if(factor > 1 && treeGetBalanceFactor(root->left) <= 0) { //LR
        root->left = treeRotateLeft(root->left);
        return treeRotateRight(root);
    } else if(factor < -1 && treeGetBalanceFactor(root->right) <= 0) // RR
        return treeRotateLeft(root);
    else if((factor < -1 && treeGetBalanceFactor(root->right) > 0)) { // RL
        root->right = treeRotateRight(root->right);
        return treeRotateLeft(root);
    } else { // Nothing happened.
        return root;
    }
}

void insert(node **root_ptr, int val) {
    node *root = *root_ptr;
    if(root == NULL) {
        node *new_node = new node{val,NULL, NULL};
        *root_ptr = new_node;
    }
    else if(root->val == val) {
        return;
    }
    else {
        if(root->val < val) {
            insert(&(root->right), val);
        }
        else {
            insert(&(root->left), val);
        }
    }
    *root_ptr = treeRebalance(*root_ptr);
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    node* root = NULL;  
    int n; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        int val; scanf("%d", &val);
        insert(&root, val);
    }
    printf("%d", root->val);
    return 0;
}