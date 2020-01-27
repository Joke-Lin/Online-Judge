#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define LOCAL

using namespace std;
typedef long long ll;

int n,m,k,r;
const int maxn = 201;	// ����·���� [0,n) [n,n+m)
bool graph[maxn][maxn];
int pos[maxn][2];

// �ж�st ed���·���� �Ƿ�������� 
bool isIn(int st, int ed) {
	return sqrt(pow(pos[st][0] - pos[ed][0],2) + pow(pos[st][1] - pos[ed][1],2)) <= r;
}

int bfs(int st, int ed) {
	bool isVisit[maxn]; 	// ���ʹ���ÿ��ڵ��־ 
	memset(isVisit,0,sizeof(isVisit));
	queue<pair<int,int> > q;	// first����ǰ�������Ľڵ��� second����ʹ�õĴ���·����
	q.push(make_pair(st,0));
	int len = 1,level = 1;	// len:ÿһ������ĳ��� level������
	while(len > 0)  {	// ֻҪ��ǰ�㻹�нڵ� ����� 
		int newLen = 0;
		for(int i = 0;i < len;i++) {	// ����ÿһ�� 
			pair<int,int> node = q.front(); q.pop();
			if(node.first == ed) return level-2;
			for(int j = 0;j < n;j++) {
				if(graph[node.first][j] && !isVisit[j]) {
					isVisit[j] = true;
					q.push(make_pair(j,node.second));
					newLen++;
				}
			}
			for(int j = n;j < n+m;j++) {
				if(graph[node.first][j] && !isVisit[j] && node.second < k) {
					isVisit[j] = true;
					q.push(make_pair(j,node.second+1));
					newLen++;
				}
			}
		}
		len = newLen;
		level++;
	}
	return -1;
}

int main()
{
#ifdef LOCAL
	freopen("./in.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&k,&r);
	for(int i = 0;i < n+m;i++) scanf("%d%d",&pos[i][0],&pos[i][1]); 
	for(int i = 0;i < n+m;i++) {
		for(int j = i+1;j < n+m;j++) {
			graph[i][j] = graph[j][i] = isIn(i,j);	// �Լ����ܺ��Լ��� 
		}
	}
	printf("%d",bfs(1,0));
	return 0;
}
