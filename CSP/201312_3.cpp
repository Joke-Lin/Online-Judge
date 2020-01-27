#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdio>
#define LOCAL

using namespace std;

int solution(int n,int num[])
{
    int res = 0;
    for(int i = 0;i < n-1;i++)
    {
        int MIN = num[i];
        for(int j = i+1;j < n;j++)
        {
            MIN = min(MIN,num[j]);
            res = max(res,(j-i+1)*MIN);
        }
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n,num[1010];
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",num+i);
    printf("%d",solution(n,num));
    return 0;
}