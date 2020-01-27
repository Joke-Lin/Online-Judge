#include <iostream>
#include <cstdio>
#include <memory.h>

#define LOCAL

using namespace std;
long long r,y,g;  // 1：红灯 2：黄灯 3：绿灯

long long stayTime(long long state, long long timeTo, long long timeLast) { // 参数 状态，
    long long timeTemp;
    if(state == 1) timeTemp = r-timeTo;
    else if(state == 2) timeTemp = r+y+g - timeTo;
    else if(state == 3) timeTemp = r+g - timeTo;
    long long timeNow = (timeLast+timeTemp) % (r+g+y);
    if(timeNow < r) return r-timeNow;
    else if(timeNow >= r && timeNow < r+g) return 0;
    else if(timeNow >= r+g) return r+y+g - timeNow + r;
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    scanf("%lld%lld%lld",&r,&y,&g);
    long long res = 0;
    long long n; scanf("%lld",&n);
    for(long long i = 0;i < n;i++) {
        long long kind, clocks; scanf("%lld%lld",&kind,&clocks);
        if(kind == 0) {
            res += clocks;
            continue;
        }
        long long tempTime = stayTime(kind,clocks,res);
        res += tempTime;
    }
    printf("%lld",res);
    return 0;
}