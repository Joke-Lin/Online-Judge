#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

const int maxn = 10000 + 1;
int nums[maxn];
int d[maxn];    // 以i结尾的最大值
int f[maxn];    // 以i结尾最大值的前缀

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int m; scanf("%d", &m);
    for(int i = 0;i < m;i++) {
        scanf("%d", nums + i);
    }
    int max_index = 0;
    d[0] = nums[0];
    f[0] = 0;
    for(int i = 1;i < m;i++) {
        if(d[i-1] < 0) {
            d[i] = nums[i];
            f[i] = i;
        }
        else {
            d[i] = d[i-1] + nums[i];
            f[i] = f[i-1];
        }
        if(d[i] > d[max_index]) {
            max_index = i;
        }
    }
    // 输出的是最大值 和此序列的首尾元素 。。。 开始看错了。。后面还看错
    if(d[max_index] >= 0) {
        printf("%d %d %d", d[max_index], nums[f[max_index]], nums[max_index]);
    }
    else {
        printf("%d %d %d",0, d[0], d[m-1]);
    }
    return 0;
}