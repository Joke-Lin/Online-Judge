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

int nums[100010];
int nums_pos[100010];   // 保存对应数的位置

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", nums+i);
        nums_pos[nums[i]] = i;
    }
    int res = 0;
    while(true) {
        bool flag = true;
        if(nums_pos[0] != 0) {

        }
        if(!flag) {
            break;
        }
    }
    return 0;
}