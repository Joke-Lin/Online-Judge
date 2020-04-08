#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
// #define LOCAL

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int num1[1005], num2[1005], k;
    long long num;  // 注意一开始就溢出 艹
    scanf("%lld %d", &num, &k);
    int len = 0;
    while(num != 0) {
        num1[len++] = num%10;
        num /= 10;
    }
    int steps = 0;
    while(steps < k) {
        // 判断是否是回文
        bool flag = true;
        for(int i = 0;i < len/2;i++) {
            if(num1[i] != num1[len-1-i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            break;
        }
        // 反转 相加
        steps++;
        int carry = 0;
        for(int i = 0;i < len;i++) {
            int temp = num1[i] + num1[len-1-i] + carry;
            num2[i] = temp%10;
            carry = temp/10;
        }
        if(carry != 0) {
            num2[len++] = carry;
        }
        memcpy(num1, num2, sizeof(num2)); // num1 = num2
    }
    for(int i = len-1;i >= 0;i--) {
        printf("%d", num1[i]);
    }
    printf("\n%d", steps);
    return 0;
}