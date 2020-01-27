#include<iostream>
#include<cstdio>
#define LOCAL

using namespace std;

int State[31][31];
int isClear[31][31];
int n,m; 

void clear(int i, int j) // clear the row or col if it's legal
{
    // in vertical
    int up = i,down = i;
    while(up >= 0)
    {
        if(State[up][j] == State[i][j]) up--;
        else break;
    }
    while(down < n)
    {
        if(State[down][j] == State[i][j]) down++;
        else break;
    }
    up++,down--;
    if(down - up + 1 >=  3)
    {
        for(int k = up;k <= down;k++) isClear[k][j] = 0;
    }
    // in horizental
    int right = j, left = j;
    while(right < m)
    {
        if(State[i][right] == State[i][j]) right++;
        else break;
    }
    while(left >= 0)
    {
        if(State[i][left] == State[i][j]) left--;
        else break;
    }
    right--,left++;
    if(right - left + 1 >= 3)
    {
        for(int k = left;k <= right;k++) isClear[i][k] = 0;
    }
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++) scanf("%d",&State[i][j]),isClear[i][j] = 1;
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++) clear(i,j);
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(isClear[i][j] == 0) State[i][j] = 0;
            printf("%d ",State[i][j]);
        }
        printf("\n");
    }
    return 0;
}