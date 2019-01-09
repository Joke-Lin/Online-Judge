#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
typedef long long ll;

ll PL(int i)
{
    ll sum = 1;
    for(int j = 2;j <= i;j++) sum *= j;
    return sum;
}

int main()
{
    ll dp[30];//dp[i]表示i个位子错排的可能
    //对dp[n]考虑n放在哪里有n-1个位子 
    //假设放在k那么k该放在哪里 1.放在n 2.其他位置
    //两者分别是dp[n-2] dp[n-1]
    //dp[n] = (n-1)(dp[n-1]+dp[n-2])
    dp[0] = 0,dp[1] = 0,dp[2] = 1;
    for(int i = 3;i <= 20;i++) dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    int n; scanf("%d",&n);
    while(n--)
    {
        int k;scanf("%d",&k);
        printf("%.2lf%%\n",100.0*dp[k]/PL(k));
    }
    system("pause");
    return 0;
}