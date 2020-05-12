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

typedef pair<int, int> Node;
Node G[100010];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, v, addr, next, st;
    scanf("%d %d", &n, &st);
    bool is_empty = true;
    for(int i = 0;i < n;i++) {
        scanf("%d %d %d", &addr, &v, &next);
        if(addr == st) {
            is_empty = false;
        }
        G[addr] = {v, next};
    }
    if(is_empty) {
        printf("0 -1");
        return 0;
    }
    vector<int> list;
    while(true) {
        list.push_back(st);
        if(G[st].second == -1) {
            break;
        }
        st = G[st].second;
    }
    sort(list.begin(), list.end(), [](int &a, int &b)->bool{return G[a].first < G[b].first;});
    int len = list.size();
    printf("%d %05d\n", len, list[0]);
    for(int i = 0;i < len;i++) {
        if(i != len - 1) {
            printf("%05d %d %05d\n", list[i], G[list[i]].first, list[i+1]);
        }
        else {
            printf("%05d %d -1\n", list[i], G[list[i]].first);
        }
    }
    return 0;
}