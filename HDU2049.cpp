#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    long long dp[25];//i个人互相找错的种数
    long long C[25][25];//组合数
    //result[m][n] = C[n][m]*dp[m]
    memset(C,0,sizeof(C));
    dp[1] = 0,dp[2] = 1;
    for(int i = 3;i <= 20;i++) dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    C[0][0] = 1;
    for(int i = 0;i <= 20;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i;j++)
        {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]);
        }
    }
    int T; scanf("%d",&T);
    while(T--)
    {
        int m,n; scanf("%d%d",&n,&m);
        printf("%lld\n",dp[m]*C[n][m]);
    }
    system("pause");
    return 0;
}