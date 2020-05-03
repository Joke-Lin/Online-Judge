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
//#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;
typedef long long ll;

// 获取某个数1个个数
int calOnes(int num) {
    int res = 0;
    while(num) {
        if(num % 10 == 1) {
            res++;
        }
        num = num/10;
    }
    return res;
}

ll getOnes(int num) {
    if(num < 10) {
        return 1;
    }
    char num_str[30];
    sprintf(num_str, "%d", num);
    ll table[30]; // 存储信息表 位数-数量表
    memset(table, 0, sizeof(table));
    // 初始化1位的情况
    table[0] = num_str[0]-'0', table[1] = 1;
    int lens = strlen(num_str);
    int up_pos = calOnes(table[0]); // 记录N位的1的个数，以获取其在哪一列
    int temp_sum = table[0];    // N位对应的值
    for(int i = 2;i <= lens;i++) {  // 位数遍历
        int cur_num = num_str[i-1] - '0';   // 当前的对应位的值
        temp_sum = temp_sum*10 + cur_num;
        int temp = 0;   // 保存含有1的数字总和
        // 从后往前压缩数组（滚动数组）
        for(int cur = i;cur >= 1;cur--) {   // 获取对应1的个数的数量
            int prev = cur-1;
            // 对应prev，cur两列的数值
            int a = up_pos == prev ? table[prev] - (cur_num == 0) : table[prev];
            int b = up_pos == cur ? (table[cur] - 1)*9 + (cur_num == 0 ? 1 : cur_num) : table[cur]*9;
            table[cur] = a+b;
            temp += table[cur];
        }
        table[0] = temp_sum - temp + 1; // 不包含1 的数量
        up_pos = calOnes(temp_sum);
    }
    ll res = 0;
    for(int i = 1;i <= lens;i++) {
        res += i*table[i];
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; 
    scanf("%d", &n);
    printf("%d", getOnes(n));
    return 0;
}