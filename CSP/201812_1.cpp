#include <iostream>
#include <cstdio>
#include <memory.h>

#define LOCAL

using namespace std;
int r,y,g;  // 1：红灯 2：黄灯 3：绿灯

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    scanf("%d%d%d",&r,&y,&g);
    int res = 0;
    int n; scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        int kind, clocks; scanf("%d%d",&kind,&clocks);
        if(kind == 0) res += clocks;
        else if(kind == 1) res += clocks;
        else if(kind == 2) res += clocks + r;
    }
    printf("%d",res);
    return 0;
}