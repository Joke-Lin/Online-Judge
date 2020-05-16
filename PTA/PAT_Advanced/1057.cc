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
#define LOWBIT(x) ((x)&(-(x)))

using namespace std;

const int maxn = 1e5+10;

int nums[maxn];

// 表示值x的数量加1
void add(int x, int v) {
    while(x < maxn) {
        nums[x] += v;   
        x += LOWBIT(x);
    }
}

// 获取<x的所有个数
int getsum(int x) {
    int res = 0;
    while(x >= 1) {
        res += nums[x];
        x -= LOWBIT(x);
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(nums, 0, sizeof(nums));
    stack<int> s;
    int n; scanf("%d", &n);
    char cmd[15];
    while(n--) {
        scanf("%s", cmd);
        if(cmd[1] == 'o') {
            if(s.empty()) {
                printf("Invalid\n");
            }
            else {
                int x = s.top(); s.pop();
                add(x, -1); // 减少一个了
                printf("%d\n", x);
            }
        }
        else if(cmd[1] == 'e') {
            if(s.empty()) {
                printf("Invalid\n");
            }
            else {
                int tar = (s.size() + 1) >> 1;
                int left = 1, right = maxn-1, mid;
                while(left < right) {
                    mid = (left + right) >> 1;
                    if(getsum(mid) < tar) {
                        left = mid+1;
                    }
                    else {
                        right = mid;
                    }
                }
                printf("%d\n", right);
            }
        }
        else if(cmd[1] == 'u') {
            int x; scanf("%d", &x);
            s.push(x);
            add(x, 1);
        }
    }
    return 0;
}