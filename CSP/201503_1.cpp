#include<iostream>
#include<cstdio>
#include<memory.h>

#define LOCAL
using namespace std;

int num[1001][1001];

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif 
    int n,m; scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            scanf("%d",&num[i][j]);
        }
    }

    for(int j = m-1;j >= 0;j--)
    {
        for(int i = 0;i < n;i++)
        {
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}