#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iterator>
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

typedef unsigned long long llu;

bool isGreater(bool s_a, llu a, bool s_b, llu b) {
    // 正 负
    if(s_a && !s_b) {
        return true;
    }
    // 负 正
    if(!s_a && s_b) {
        return false;
    }
    // 负 负
    if(!s_a && !s_b) {
        return a < b;
    }
    return a > b;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    char str[3][50];    // 保存为字符串 区别正负数
    bool s[3];          // 0 非负数 1 负数 符号位保存
    llu nums[3];        // 保存数值
    int n; scanf("%d", &n);
    for(int i = 1;i <= n;i++) {
        scanf("%s %s %s", str[0], str[1], str[2]);
        for(int k = 0;k < 3;k++) {
            s[k] = str[k][0] == '-' ? false : true;
            char *buffer = str[k][0] == '-' ? str[k]+1 : str[k];
            sscanf(buffer, "%llu", &nums[k]);
        }
        bool flag;  // 结果的符号
        llu res;    // 存放结果
        // 正 负
        if(s[0] && !s[1]) {
            flag = nums[0] >= nums[1];  // a >= b true
            res = flag ? nums[0] - nums[1] : nums[1] - nums[0];
            flag = isGreater(flag, res, s[2], nums[2]);
        }
        // 负 正
        else if(!s[0] && s[1]) {
            flag = nums[1] >= nums[0];  // a >= b true
            res = flag ? nums[1] - nums[0] : nums[0] - nums[1];
            flag = isGreater(flag, res, s[2], nums[2]);
        }
        // 负 负
        else if(!s[0] && !s[1]) {
            flag = false;
            res = nums[0] + nums[1];
            flag = isGreater(flag, res, s[2], nums[2]);
            // 必然是小于溢出，溢出则必定是小于
            if(res < nums[0]) {
                flag = false;
            }
        }
        else {
            flag = true;
            res = nums[0] + nums[1];
            flag = isGreater(flag, res, s[2], nums[2]);
            if(res < nums[0]) {
                flag = true;
            }
        }
        printf("Case #%d: %s\n", i, flag ? "true" : "false");
    }

    return 0;
}