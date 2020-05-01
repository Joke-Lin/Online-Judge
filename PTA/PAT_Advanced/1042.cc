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
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

const int maxn = 55;
int src_order[maxn];
int mid_order[maxn];
int pre_order[maxn];
char type[] = {'S', 'H', 'C', 'D'};

void print(int n) {
    n--;
    if(n == 52) {
        printf("J1");
    }
    else if(n == 53) {
        printf("J2");
    }
    else {
        printf("%c%d", type[n/13], n%13 + 1);
    }
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    for(int i = 1;i <= 54;i++) {
        src_order[i] = i;
        scanf("%d", pre_order+i);
    }
    while(n--) {
        for(int i = 1;i <= 54;i++) {
            mid_order[pre_order[i]] = src_order[i];
        }
        memcpy(src_order, mid_order, sizeof(src_order));
    }
    for(int i = 1;i <= 54;i++) {
        print(src_order[i]);
        if(i != 54) {
            printf(" ");
        }
    }
    return 0;
}