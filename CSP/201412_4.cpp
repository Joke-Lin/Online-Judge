#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int s;
	int t;
	int cost;
	bool operator < (const Edge &another) {
		return cost < another.cost;
	}
	Edge(int s_, int t_, int cost_):
		s(s_), t(t_), cost(cost_)
	{}
};

const int maxn = 1010;
vector<Edge> edges;
int n,m;
int father[maxn], rank[maxn];

void init() {
	for(int i = 1;i <= n;i++) {
		father[i] = i, rank[i] = 0;
	}
}

int find(int x)
{
	return father[x] == x ? x : father[x] = find(father[x]);
}

void merge(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x == y)  return;
	if(rank[x] < rank[y]) father[x] = y;
	else {
		father[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++) {
		int s,t,cost;
		scanf("%d%d%d",&s,&t,&cost);
		edges.push_back(Edge(s,t,cost));
	}
	sort(edges.begin(),edges.end());
	init();
	int res = 0;
	for(int i = 0;i < m;i++) {
		Edge temp = edges[i];
		if(find(temp.s) != find(temp.t)) {
			merge(temp.s,temp.t);
			res += temp.cost;
		}
	}
	printf("%d",res);
	return 0;
}
