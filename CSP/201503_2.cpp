#include<iostream>
#include<cstdio>
#include<memory.h>

#define LOCAL

using namespace std;

int maxn = 1010;
int num[1010];

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    memset(num,0,sizeof(num));
    int n; scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int temp; scanf("%d",&temp);
        num[temp]++;
    }
    for(int i = 0;i < maxn;i++)
    {
        int digit = 0;
        for(int j = 0;j < maxn;j++)
        {
            if(num[j] > num[digit]) digit = j;
        }
        if(digit == 0) break;
        printf("%d %d\n",digit, num[digit]);
        num[digit] = 0;
    }
    return 0;
}