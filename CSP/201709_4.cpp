/*
*	ͼ�ı��� ������С ֱ��DFS���� 
*	��Ŀ��˵�ǵ��� ������������͹�����˫�� ��Ҫÿ��DFS����һ�����ʹ�������� �������ѭ��
*	s->t ˵�����߶���ʶ 
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 1005;

vector<vector<int> > graph(maxn);	// �����ڽӱ� 
int n,m;
bool flag[maxn][maxn];
bool isVis[maxn];

// �ж��Դ˽ڵ㿪ʼ�ܷ���������нڵ� 
// flag: bool �����ж��Ƿ������
// �����������flag���� 
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
	// ��ʼ�� flag���� 
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
