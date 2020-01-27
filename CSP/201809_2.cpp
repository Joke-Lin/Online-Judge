#include <iostream>
#include <cstdio>
#include <memory.h>

#define LOCAL

using namespace std;

int Time1[1000010];
int Time2[1000010];

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    memset(Time1,0,sizeof(Time1));
    memset(Time2,0,sizeof(Time2));
    int n; scanf("%d",&n);
    int a,b;
    int maxTime = 0;
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a > maxTime) maxTime = a;
        if(b > maxTime) maxTime = b;
        for(int j = a;j < b;j++) Time1[j] = 1;
    }
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a > maxTime) maxTime = a;
        if(b > maxTime) maxTime = b;
        for(int j = a;j < b;j++) Time2[j] = 1;
    }
    int res = 0;
    for(int i = 1;i <= maxTime;i++)
    {
        if(Time1[i] == 1 && Time2[i] == 1) res += 1;
    }
    printf("%d",res);
    return 0;
}