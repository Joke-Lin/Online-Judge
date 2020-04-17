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

using namespace std;

const int maxn = 1e5 + 1;
int nums_count[maxn];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(nums_count, 0, sizeof(nums_count));
    vector<int> order;
    int n, v; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &v);
        nums_count[v]++;
        order.push_back(v);
    }
    for(auto i : order) {
        if(nums_count[i] == 1) {
            printf("%d", i);
            return 0;
        }
    }
    printf("None");
    return 0;
}