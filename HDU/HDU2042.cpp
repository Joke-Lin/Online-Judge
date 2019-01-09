#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main()
{
    long long dp[50];
    dp[1] = 4;
    for(int i = 2;i <= 30;i++) dp[i] = 2*(dp[i-1]-1);
    int n;scanf("%d",&n);
    while(n--) {
        int k; scanf("%d",&k);
        printf("%lld\n",dp[k]);
    }
    system("pause");
    return 0;
}