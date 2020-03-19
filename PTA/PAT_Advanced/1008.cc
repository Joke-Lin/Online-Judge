#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    int last = 0, t = 0;
    for(int i = 0;i < n;i++) {
        int cur; scanf("%d", &cur);
        if(cur > last) {
            t += 6*(cur-last);
        }
        else if(cur < last) {
            t += 4*(last-cur);
        }
        t += 5;
        last = cur;
    }
    printf("%d", t);
    return 0;
}