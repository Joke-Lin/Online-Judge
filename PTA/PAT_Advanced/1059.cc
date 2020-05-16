#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <set>
#include <stack>
//#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    long int n; scanf("%ld", &n);
    printf("%ld=", n);
    int sqr = sqrt(n);
    map<int, int> m;
    if(n == 1) {
        m[1] = 1;
    }
    for(int i = 2;i <= sqr;) {
        // 一个因子
        if(n % i == 0) {
            m[i]++;
            n = n/i;
            sqr = sqrt(n);
        }
        else {
            i++;
        }
    }
    if(n != 1) {
        m[n]++;
    }
    int len = m.size();
    int i = 0;
    for(auto v : m) {
        if(v.second != 1) {
            printf("%d^%d", v.first, v.second);
        }
        else {
            printf("%d", v.first);
        }
        if(i != len - 1) {
            printf("*");
        }
        i++;
    }
    return 0;
}