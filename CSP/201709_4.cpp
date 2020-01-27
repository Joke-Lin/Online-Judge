/*
*	图的遍历 数据量小 直接DFS即可 
*	题目虽说是单向 但是两条单向就构成了双向 需要每次DFS构建一个访问过点的数组 负责会死循环
*	s->t 说明两者都认识 
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 1005;

vector<vector<int> > graph(maxn);	// 定义邻接表 
int n,m;
bool flag[maxn][maxn];
bool isVis[maxn];

// 判断以此节点开始能否遍历到所有节点 
// flag: bool 数组判断是否遍历过
// 最后跳过遍历flag数组 
void isAllThrough(int st, int cur) {
	isVis[cur] = true;
	flag[st][cur] = flag[cur][st] = true;
	for(int i = 0;i < graph[cur].size();i++) {
		if(!isVis[graph[cur][i]]) isAllThrough(st, graph[cur][i]);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++) {
		int s,t; scanf("%d%d",&s,&t);
		graph[s].push_back(t);
	}
	int res = 0;
	// 初始化 flag数组 
	for(int i = 1;i <= n;i++) {
		isVis[i] = false;
		for(int j = 1;j <= n;j++) {
			flag[i][j] = false;
		}
	}
	for(int i = 1;i <= n;i++)  {
		memset(isVis,0,sizeof(isVis));
		isAllThrough(i, i);
	}
	for(int i = 1;i <= n;i++) {
		bool flagRow = true, flagCol = true;
		for(int j = 1;j <= n;j++) {
			if(flag[i][j] == false) flagRow = false;
			if(flag[j][i] == false) flagCol = false;
		}
		if(flagRow || flagCol) res++;
	}
	printf("%d",res);
	return 0;
}
