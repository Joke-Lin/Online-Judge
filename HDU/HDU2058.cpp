#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#define LOCAL

using namespace std;
typedef long long ll;
int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    ll n,m;
    while(scanf("%lld%lld",&n,&m),n+m) //n打酱油的？？？？
    {
        ll max_len = sqrt((double)m*2);//从1开始等差数列求和j-i最长必须是从1开始获得
        for(ll len = max_len;len >= 1;len--)
        {
            if((2*m) % len == 0)//解必须是整数
            {
                if((2*m/len - len + 1)%2 == 0)
                {
                    printf("[%lld,%lld]\n",(2*m/len - len + 1)/2,(2*m/len - len + 1)/2+len-1);//求和公式求解
                }
            }
        }
        printf("\n");
    }
    return 0;
}