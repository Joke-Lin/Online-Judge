#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    long long dp[52][52];//i->j的路径数
    memset(dp,0,sizeof(dp));
    for(int i = 1;i <= 50;i++)
    {
        dp[i][i+1] = 1;
        dp[i][i+2] = 2;
    }
    for(int i = 1;i <= 50;i++)//start
    {
        for(int j = i+1;j <= 50;j++)//end
        {
            if(dp[i][j]) continue;
            dp[i][j] = dp[i][j-1]+dp[i][j-2];
        }
    }
    int T;scanf("%d",&T);
    while(T--)
    {
        int st,ed; scanf("%d%d",&st,&ed);
        printf("%lld\n",dp[st][ed]);
    }
    system("pause");
    return 0;
}