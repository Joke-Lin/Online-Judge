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

int nums[100010];

int divide(int r, int l, int tar) {
    while(r <= l) {
        int mid = (r+l) >> 1;
        if(nums[mid] == tar) {
            return mid;
        }
        else if(nums[mid] < tar) {
            r = mid+1;
        }
        else {
            l = mid-1;
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++) {
        scanf("%d", nums+i);
    }
    sort(nums, nums+n);
    for(int i = 0;i < n-1;i++) {
        if(nums[i] > m/2) {
            printf("No Solution");
            return 0;
        }
        int pos = divide(i+1, n-1, m-nums[i]);
        if(pos != -1) {
            printf("%d %d", nums[i], nums[pos]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}