#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

const int maxn = 1001;

float A[maxn] = {0};
float Res[2*maxn] = {0};

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m, p;
    float num;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d %f", &p, &num);
        A[p] = num;
    }
    scanf("%d", &m);
    for(int i = 0;i < m;i++) {
        scanf("%d %f", &p, &num);
        for(int j = 0;j < maxn;j++) {
            Res[j+p] += A[j]*num;
        }
    }
    int all = 0;
    for(int i = 0;i < 2*maxn;i++) {
        if(Res[i] != 0) {
            all++;
        }
    }
    printf("%d", all);
    for(int i = 2*maxn-1;i >= 0;i--) {
        if(Res[i] != 0) {
            printf(" %d %.1f", i, Res[i]);
        }
    }
    return 0;
}