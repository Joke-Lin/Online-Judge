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
#define LOCAL

using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int counts[10];
    memset(counts, 0, sizeof(counts));
    char num_str[30] = ""; scanf("%s", num_str);
    for(int i = 0;i < strlen(num_str);i++) {
        counts[num_str[i]-'0']++;
    }
    int carry = 0, temp;
    int nums[25], index = 0;
    bool flag = true;
    for(int i = strlen(num_str)-1;i >= 0;i--) {
        temp = (num_str[i] - '0') * 2 + carry;
        counts[temp%10]--;
        carry = temp/10;
        nums[index++] = temp%10;
    }
    if(carry != 0) {
        flag = false;
        nums[index++] = carry;
    }
    if(flag) {
        for(int i = 0;i < 10;i++) {
            if(counts[i] != 0) {
                flag = false;
                break;
            }
        }
    }
    printf("%s\n", flag ? "Yes" : "No");
    for(int i = index-1;i >= 0;i--) {
        printf("%d", nums[i]);
    }
    return 0;
}