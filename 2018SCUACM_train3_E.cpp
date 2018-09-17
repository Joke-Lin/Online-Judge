// 青蛙举行了运动会，要求青蛙跳跃小河。河流宽度为 L (1<= L <= 1000000000). 河里会有 n 个石头沿着垂直于河岸的直线排成一排，青蛙以跳到石头上，然后再次跳跃。青蛙最多能够跳 m 次；现在青蛙们想知道他们最少应该有多大的跳跃能力才能够到达河对岸？
//
// Input
// 多组数据；
//
// 每行输入   L，n，m；
//
// 接下来输入n个数，代表第 i 个石头距离开始位置的距离，两个石头不可能出现在一起。
//
// Output
// 输出一个数，代表至少需要的跳跃距离（最小的最大跳跃能力）；
//
// Sample Input
// 6 1 2
// 2
// 25 3 3
// 11
// 2
// 18
// Sample Output
// 4
// 11

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dis;

bool check(int);
int L,n,m;

int main()
{
	while(~scanf("%d%d%d",&L,&n,&m))//和EOF意思一样
	{
		dis.clear();
		dis.push_back(0);
		for(int i = 0;i < n;i++)
		{
			int j; scanf("%d",&j);
			dis.push_back(j);
		}
		dis.push_back(L);
		sort(dis.begin(),dis.end());
		int front = 0,end = L,mid;
		while(front < end)
		{
			mid = front + (end-front)/2;
			if(check(mid)) end = mid;
			else front = mid+1;
		}
		printf("%d\n",front);
	}
	return 0;
}

bool check(int len)
{
	int total = 0,j = 0,mid = 0;
	for(int i = 0;i < m;i++)
	{
		while(j < dis.size() && total+len >= dis[j]) mid = dis[j++];
		total = mid;
	}
	if(total>=L) return true;
	else return false;
}
