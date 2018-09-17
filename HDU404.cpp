#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int l,n,m;
vector<int>s;
bool check(int dis)
{
    int sum=0,i,j=0,cnt=0;
    int k=s.size();
    for(i=0; i<m; i++)
    {
        while(j<k&&s[j]<=sum+dis)//如果如果青蛙能跳过此石头s[j]的位置，就记录下此石头的位置，并继续检测青蛙是否能跳过下一个石头
        {
            cnt=s[j];//记录走过的石头的位置
            j++;
        }
        sum=cnt;//记录每一步跳到的位置
    }
    if(sum>=l)//如果青蛙能过在m步内跳过终点，则此跳跃能力合格
        return 1;
    return 0;
}
int main()
{
    while(~scanf("%d%d%d",&l,&n,&m))
    {
        int i,k;
        s.clear();
        s.push_back(0);
        for(i=0; i<n; i++)
        {
            scanf("%d",&k);
            s.push_back(k);
        }
        s.push_back(l);
        sort(s.begin(),s.end());
        int x=0,y=l,mid;
        while(x<y)
        {
            mid=x+(y-x)/2;
            if(check(mid))
                {
					y=mid;
				}
            else
                x=mid+1;
        }
        printf("%d\n",x);
    }
    return 0;
}
