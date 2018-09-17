#include<stdio.h>

int main()
{
	long long dp[52];
    dp[0] = 0,dp[1] = 3,dp[2] = 6,dp[3] = 6;
    //要求第i个的方法 如果已知i-1 i-2 的话
    //对dp[i-1] 比如首位为AB 那么第i个只能填C 即一种情况
    //对dp[i-2] 比如A*B 那么有三种AB CB AC 以为在dp[i-1]中已经讨论了CB这种所以只有两种
    //可得 dp[i] = dp[i-1]+dp[i-2] dp[3]比较特殊:)
    for(int i = 4;i <= 50;i++) dp[i] = dp[i-1]+2*dp[i-2];
    int n;
    while(~scanf("%d",&n)) printf("%lld\n",dp[n]);
	return 0;
}