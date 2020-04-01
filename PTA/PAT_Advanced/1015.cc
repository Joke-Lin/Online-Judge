#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <cmath>
#define LOCAL

using namespace std;

const int maxn = 1001;

bool isPrime(int n) {
    if(n < 2) {
        return false;
    }
    int sq = sqrt(n);
    for(int i = 2;i <= sq;i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int num, radix;
    while(true) {
        scanf("%d", &num);
        if(num < 0) {
            break;
        }
        scanf("%d", &radix);
        bool flag = true;
        if(!isPrime(num)) {
            flag = false;
        }
        // 计算对应的数值相反
        else {
            int num_re = 0;
            while(num != 0) {
                num_re = num_re*radix + num % radix;
                num = num / radix;
            }
            if(!isPrime(num_re)) {
                flag = false;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}