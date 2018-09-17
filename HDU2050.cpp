// http://www.cnblogs.com/YJinpeng/p/5962352.html
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
typedef long long ll;

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",2*n*n+1-n);
    }
    system("pause");
    return 0;
}