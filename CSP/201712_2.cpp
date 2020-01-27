#include<iostream>
#include<cstdio>
#define LOCAL

using namespace std;

int child[1010];

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n,k; scanf("%d %d",&n,&k);
    for(int i = 1;i <= n;i++) child[i] = 1; // 1: alive ; 0: go out
    int alive = n;
    int beg = 0;
    int number = 0;
    while(alive > 1)
    {
        while(true)
        {
            beg++;
            if(beg > n) beg = beg % n;
            if(child[beg] == 0) continue;
            number++;
            if(number % 10 == k || number % k == 0)
            {
                child[beg] = 0;
                alive--;
                break;
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(child[i])
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}