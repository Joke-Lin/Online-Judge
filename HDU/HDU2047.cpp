#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main()
{
    long long dp[50];
    dp[0] = 0;
    dp[1] = 3;
    dp[2] = 8;
    for(int i = 3;i<=40;i++) dp[i] = 2*(dp[i-1]+dp[i-2]);
    //最后一位有三种可能
    //EOF E F 是肯定可以的
    //对O单独讨论 XXXE/O/F~O 两种
    //所以有上式
    int n;
    while(~scanf("%d",&n)) printf("%lld\n",dp[n]);
    system("pause");
    return 0;
}