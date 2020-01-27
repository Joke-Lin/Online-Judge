#include <iostream>
#include <cstdio>
#include <memory.h>

#define LOCAL

using namespace std;

int SEAT[20][5];

inline int getId(int r,int c)
{
    return r*5+c+1;
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    memset(SEAT,0,sizeof(SEAT));
    int n; scanf("%d",&n);
    while(n--)
    {
        int num; scanf("%d",&num);
        bool flag = false; // if the seats is enough
        for(int i = 0;i < 20;i++) // judge if it have enough seats for a row Neighboringly
        {
            for(int j = 0;j < 5;j++)
            {
                if(SEAT[i][j] == 1) continue;
                int empty_seat = 1;
                for(int k = 1;k < 5-j;k++)
                {
                    if(SEAT[i][j+k] == 0) empty_seat++;
                    else break;
                }
                if(empty_seat >= num)
                {
                    flag = true;
                    for(int k = j;k < j+num;k++)
                    {
                        printf("%d ",getId(i,k));
                        SEAT[i][k] = 1;
                    }
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) // if it doesn't have, chose the seat in ascending order
        {
            int k = 0;
            bool flag = false;
            for(int i = 0;i < 20;i++)
            {
                for(int j = 0;j < 5;j++)
                {
                    if(SEAT[i][j] == 0)
                    {
                        k++;
                        printf("%d ",getId(i,j));
                        if(k == num) 
                        {
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
        }
        printf("\n");
    }
    return 0;
}