#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;
const int maxn = 55;

int main()
{
    long long dp[maxn];
    dp[1] = 1,dp[2]=2;
    for(int i = 3;i <= 50;i++) dp[i] = dp[i-2]+dp[i-1];
    //分剩余两个没填和1个没填讨论 注意情况重复的情况
    int n;
    while(~scanf("%d",&n)) printf("%lld\n",dp[n]);
    system("pause");
    return 0;
}