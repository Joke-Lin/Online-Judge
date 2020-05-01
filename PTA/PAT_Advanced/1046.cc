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
int n, dist[100010], dist_0[100010];


int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", dist+i);
    }
    int sum_dist = 0;
    dist_0[0] = 0;
    for(int i = 0;i < n;i++) {
        dist_0[i+1] = sum_dist + dist[i];
        sum_dist += dist[i];
    }
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        int a, b; scanf("%d %d", &a, &b);
        int delt = abs(dist_0[a-1] - dist_0[b-1]);
        printf("%d\n", min(delt, sum_dist-delt));
    }
    return 0;
}