#include <iostream>
#include <cstdio>
#include <memory.h>

#define LOCAL
const int maxn = 1010;

using namespace std;

int store[maxn];
int storeNew[maxn];

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%d",store+i);
    }
    storeNew[0] = (store[0]+store[1]) / 2;
    storeNew[n-1] = (store[n-2]+store[n-1]) / 2;
    for(int i = 1;i < n-1;i++) {
        storeNew[i] = (store[i-1] + store[i] + store[i+1])/3;
    }
    for(int i = 0;i < n;i++) {
        printf("%d ",storeNew[i]);
    }
    return 0;
}