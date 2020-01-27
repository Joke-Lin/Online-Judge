#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

#define LOCAL
#define SEE(x) cout << #x << " : " << x << endl; 
using namespace std;

int n,m,root;
const int maxn = 50010;
int father[50010]; 
int rank[50010]; 

struct edge
{
	int from;
	int to;
	int cost;
	edge(int from_ = 0,int to_ = 0,int cost_ = 0):from(from_),to(to_),cost(cost_){}
	bool operator < (edge other){ return cost < other.cost; }
};

vector<edge> edges;
vector<vector<pair<int,int> > > list(maxn);	// 存最后的最小生成树的数据 邻接表表示 
set<int> pointsSet;	// 存最后的节点的集合 


void init()
{
	for(int i = 0;i < maxn;i++) father[i] = i, rank[i] = 0;
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

// 按层遍历 
int getRes(int root)
{
	int res = 0;
	vector<int> lastLayer;	// 记录上一层的父节点 
	lastLayer.push_back(root);
	while(true)
	{
		if(lastLayer.size() == 0) break;
		vector<int> thisLayer = lastLayer;	// 当前层等于上一层 
		lastLayer.clear();
		int temp = 0;
		for(int i = 0;i < thisLayer.size();i++)
		{
			int node = thisLayer[i];
			pointsSet.erase(node);	// 以为无向图 1->2;2->1 只能有一个 
			for(int i = 0;i < list[node].size();i++)
			{
				int toNode = list[node][i].first; // 这一层的下一层节点
				// 如果已经使用过的节点就跳过 
				if(pointsSet.find(toNode) == pointsSet.end()) continue;
				// 如果这个点已经是这一条分支的最底层则不加入 
				if(list[toNode].size() != 1) lastLayer.push_back(toNode); 
				temp = max(temp,list[node][i].second);
			}
		}
		res = max(res,temp);
	}
	return res;
}


int main()
{
	init();
#ifdef LOCAL
	freopen("./in.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&root);
	for(int i = 0;i < m;i++)
	{
		int beg,end,cost; scanf("%d%d%d",&beg,&end,&cost);
		edges.push_back(edge(beg,end,cost));
	}
	sort(edges.begin(),edges.end());
	for(int i = 0;i < m;i++)
	{
		edge temp = edges[i];
		if(find(temp.from) != find(temp.to))
		{
			merge(temp.from,temp.to);
			// 记录最小生成树的边，有重复 
			list[temp.from].push_back(make_pair(temp.to,temp.cost));
			list[temp.to].push_back(make_pair(temp.from,temp.cost));
			// 加入MST点集 
			pointsSet.insert(temp.from);
			pointsSet.insert(temp.to);
		}
	}
	cout << getRes(root);
	return 0;
}

