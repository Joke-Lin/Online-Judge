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
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

int n;
int pre_order[1001];
bool is_mirror = false;
vector<int> post_order;

void getTree(int st, int ed) {
    // 避免只有一半的树 比如5 4 3，此时的ed是大于st的
    if(st > ed) {
        return;
    }
    int r = st+1, l = ed;
    if(!is_mirror) {
        while(r <= ed && pre_order[r] < pre_order[st]) r++; // 最后的r是大于l的 因为++，真正的位置是循环结束的r-1
        while(l > st && pre_order[l] >= pre_order[st]) l--;
    }
    else {
        while(r <= ed && pre_order[r] >= pre_order[st]) r++;
        while(l > st && pre_order[l] < pre_order[st]) l--;
    }
    if(r - l != 1) {
        return;
    }
    // 刚刚好为后续遍历
    getTree(st+1, l);   //  左边
    getTree(r, ed);     // 右边
    post_order.push_back(pre_order[st]);    // 根结点
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", pre_order+i);
    }
    getTree(0, n-1);
    bool flag = false;
    if(post_order.size() == n) {
        flag = true;
    } else {
        post_order.clear();
        is_mirror = true;
        getTree(0, n-1);
    }
    if(post_order.size() == n) {
        printf("YES\n");
        for(int i = 0;i < post_order.size();i++) {
            printf("%d", post_order[i]);
            if(i != post_order.size() - 1) {
                printf(" ");
            }
        }
    }
    else {
        printf("NO");
    }
    return 0;
    
}