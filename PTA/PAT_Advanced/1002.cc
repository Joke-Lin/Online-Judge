#include<cstdio>
#define LOCAL

using namespace std;

const int maxn = 1001;
float ploy[maxn] = {0};

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int ex; 
    float coe; 
    for(int i = 0;i < 2;i++) {
        int k; scanf("%d", &k);
        for(int i = 0;i < k;i++) {
            scanf("%d %f", &ex, &coe);
            ploy[ex] += coe;
        }
    }
    int num = 0;
    for(int i = 0;i < maxn;i++) {
        if(ploy[i] != 0) {
            num++;
        }
    }
    printf("%d", num);
    for(int i = maxn-1;i >= 0;i--) {
        if(ploy[i] != 0) {
            printf(" %d %.1f", i, ploy[i]);
        }
    }
    return 0;
}