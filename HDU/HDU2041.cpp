#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main()
{
    int dp[42];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4;i <= 40;i++) dp[i] = dp[i-2]+dp[i-1];
    int n; scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        printf("%d\n",dp[a]);
    }
    system("pause");
    return 0;
}