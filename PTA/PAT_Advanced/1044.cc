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

const int maxn = 1e5+1;
int n, m;
int sums[maxn];

int divide(int st) {
    int ed = n, mid, tar = m+sums[st-1];
    while(st < ed) {
        mid = (st + ed) >> 1;
        if(sums[mid] >= tar) {
            ed = mid;
        }
        else {
            st = mid+1;
        }
    }
    return ed;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    sums[0] = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= n;i++) {
        int mid; scanf("%d", &mid);
        sums[i] = sums[i-1] + mid;
    }
    int min_m = sums[n];
    vector<pair<int, int>> res;
    for(int i = 1;i <= n;i++) {
        int tar_pos = divide(i);
        int temp = sums[tar_pos]-sums[i-1];
        if(temp > min_m) {
            continue;
        }
        if(temp >= m) {
            if(temp < min_m) {
                res.clear();
                min_m = temp;
            }
            res.push_back({i, tar_pos});
        }
    }
    for(auto v : res) {
        printf("%d-%d\n", v.first, v.second);
    }
    return 0;
}