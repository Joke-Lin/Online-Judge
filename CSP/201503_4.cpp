//
//做法：两次BFS求解，第一次任选一个点，求该点能到达的最远点u，第二次从u出发，求u能到达的最远点v，则u，v的距离是树的直径。
//
//定理：假设路径s-t为树的直径，则从任意一点u出发找到的最远的点一定是s、t中的一点。
//
//利用这个定理，我们先从任一点出发找到其中一个端点，然后再从这个最远点开始搜，就可以搜到另一个最长路的端点，即用两遍广搜就可以找出树的直径。
//
//证明：
//
//1.如果u是s-t路径上的一点。
//
//假设找到的最远点为T则dis(u,T) >dis(u,s)且dis(u,T)>dis(u,t) ，则最长路不是s-t了，与假设矛盾。
//
//2.如果u不是s-t路径上的点
//
//	情况1：u走到最远点的路径与s-t路径交于X点，则最后肯定走到某个端点（s或t），这一点在上面已经证明。
//	假设是t ，则路径总长度为dis(u,X)+dis(X,t)；
//	
//	情况2：u走到最远点的路径u-T与s-t无交点。假设u可到达s-t上的某个点X
//	则必然有dis(u,T) >dis(u,X)+dis(X,t)>dis(X,t)，不然u-t将会是最长路
//	于是dis(s,X)+dis(X,u)+dis(u,T)>dis(s,X)+dis(u,T)>dis(s,X)+dis(X,t)=dis(s,t)，这与最长路是s-t矛盾

#include <iostream>
#include <vector>
#include <cstdio>
#include <memory.h>

#define LOCAL

using namespace std;

const int maxn = 20010;

int n,m;
int pointTo[maxn];

// now 当前节点 last上一个节点： 避免重复走一条路 
void dfs(int now, int last, vector<vector<int> > &tree, int len) {
	if(tree[now].size() == 1 && len != 0) {	// 到达叶节点 
		pointTo[now] = len;
		return;
	}
	for(int i = 0;i < tree[now].size();i++) {
		int to = tree[now][i];
		if(to == last) continue;	// 避免重复
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
	// i号终端编号为 n+i 
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
