//
//����������BFS��⣬��һ����ѡһ���㣬��õ��ܵ������Զ��u���ڶ��δ�u��������u�ܵ������Զ��v����u��v�ľ���������ֱ����
//
//��������·��s-tΪ����ֱ�����������һ��u�����ҵ�����Զ�ĵ�һ����s��t�е�һ�㡣
//
//����������������ȴ���һ������ҵ�����һ���˵㣬Ȼ���ٴ������Զ�㿪ʼ�ѣ��Ϳ����ѵ���һ���·�Ķ˵㣬����������ѾͿ����ҳ�����ֱ����
//
//֤����
//
//1.���u��s-t·���ϵ�һ�㡣
//
//�����ҵ�����Զ��ΪT��dis(u,T) >dis(u,s)��dis(u,T)>dis(u,t) �����·����s-t�ˣ������ì�ܡ�
//
//2.���u����s-t·���ϵĵ�
//
//	���1��u�ߵ���Զ���·����s-t·������X�㣬�����϶��ߵ�ĳ���˵㣨s��t������һ���������Ѿ�֤����
//	������t ����·���ܳ���Ϊdis(u,X)+dis(X,t)��
//	
//	���2��u�ߵ���Զ���·��u-T��s-t�޽��㡣����u�ɵ���s-t�ϵ�ĳ����X
//	���Ȼ��dis(u,T) >dis(u,X)+dis(X,t)>dis(X,t)����Ȼu-t�������·
//	����dis(s,X)+dis(X,u)+dis(u,T)>dis(s,X)+dis(u,T)>dis(s,X)+dis(X,t)=dis(s,t)�������·��s-tì��

#include <iostream>
#include <vector>
#include <cstdio>
#include <memory.h>

#define LOCAL

using namespace std;

const int maxn = 20010;

int n,m;
int pointTo[maxn];

// now ��ǰ�ڵ� last��һ���ڵ㣺 �����ظ���һ��· 
void dfs(int now, int last, vector<vector<int> > &tree, int len) {
	if(tree[now].size() == 1 && len != 0) {	// ����Ҷ�ڵ� 
		pointTo[now] = len;
		return;
	}
	for(int i = 0;i < tree[now].size();i++) {
		int to = tree[now][i];
		if(to == last) continue;	// �����ظ�
		dfs(to,now,tree,len+1);
	}
}


int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	vector<vector<int> > tree(n+m+2);
	for(int i = 2;i <= n;i++) {
		int last; scanf("%d",&last);
		tree[last].push_back(i);
		tree[i].push_back(last);
	}
	// i���ն˱��Ϊ n+i 
	for(int i = 1;i <= m;i++) {
		int last; scanf("%d",&last);
		tree[n+i].push_back(last);
		tree[last].push_back(n+i);
	}
	
	memset(pointTo,0,sizeof(pointTo));
	dfs(1,0,tree,0);
	int start = 0;
	for(int i = 1;i < m+n+2;i++) {
		if(pointTo[i] > pointTo[start]) {
			start = i;
		}
	}
	
	memset(pointTo,0,sizeof(pointTo));
	dfs(start,0,tree,0);
	int end = 0;
	for(int i = 1;i < m+n+2;i++) {
		if(pointTo[i] > pointTo[end]) {
			end = i;
		}
	}
	cout << pointTo[end];
	
	return 0;
}
