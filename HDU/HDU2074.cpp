#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

char map[100][100];

int main()
{
    int n,kase = 0;
    char a,b;
    while(~scanf("%d %c %c",&n,&a,&b))
    {
        if(kase) printf("\n");
        kase++;
        if(n == 1) {
            printf("%c\n",a);
            continue;
        }
        if((n>>1)%2 != 0) swap(a,b);
        /************up down***************/
        for(int i = 0;i <= n>>1;i++)
        {
            for(int j = i;i+j < n;j++)
            {
                if(i % 2 == 0) map[i][j] = a,map[n-i-1][j] = a;
                else map[i][j] = b,map[n-i-1][j] = b;
            }
        }
        /************right left***************/
        for(int i = 0;i <= n>>1;i++)
        {
            for(int j = i;i+j < n;j++)
            {
                if(i % 2 == 0) map[j][i] = a,map[j][n-i-1] = a;
                else map[j][i] = b,map[j][n-i-1] = b;
            }
        }
        map[0][0] = map[0][n-1] = map[n-1][0] = map[n-1][n-1] = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++) printf("%c",map[i][j]);
            printf("\n");
        }
    }
    return 0;
}