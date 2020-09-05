#include <cstdio>
#include <cstdlib>
#include <cstring>

#include<algorithm>

#define LOCAL

const int maxn = 1e5+1;
const int INF = (1 << 31) - 1;
int nums[maxn], big[maxn], small[maxn];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", nums+i);
    }
    big[0] = nums[0], small[n-1] = nums[n-1];
    for(int i = 1, j = n-2;i < n;i++,j--) {
        big[i] = nums[i] > big[i-1] ? nums[i] : big[i-1];
        small[j] = nums[j] < small[j+1] ? nums[j] : small[j+1];
    }
    int res[maxn], sum = 0;
    for(int i = 0;i < n;i++) {
        int t_max = i == 0 ? 0 : big[i-1];
        int t_min = i == n-1 ? INF: small[i+1];
        if(t_max <= nums[i] && t_min >= nums[i]) {
            res[sum++] = nums[i];
        }
    }
    printf("%d%s", sum, sum == 0 ? "\n\n" : "\n");
    if(sum == 0) return 0;
    printf("%d", res[0]);
    for(int i = 1;i < sum;i++) {
        printf(" %d", res[i]);
    }
    return 0;
}