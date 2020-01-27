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
vector<vector<pair<int,int> > > list(maxn);	// ��������С������������ �ڽӱ��ʾ 
set<int> pointsSet;	// �����Ľڵ�ļ��� 


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

// ������� 
int getRes(int root)
{
	int res = 0;
	vector<int> lastLayer;	// ��¼��һ��ĸ��ڵ� 
	lastLayer.push_back(root);
	while(true)
	{
		if(lastLayer.size() == 0) break;
		vector<int> thisLayer = lastLayer;	// ��ǰ�������һ�� 
		lastLayer.clear();
		int temp = 0;
		for(int i = 0;i < thisLayer.size();i++)
		{
			int node = thisLayer[i];
			pointsSet.erase(node);	// ��Ϊ����ͼ 1->2;2->1 ֻ����һ�� 
			for(int i = 0;i < list[node].size();i++)
			{
				int toNode = list[node][i].first; // ��һ�����һ��ڵ�
				// ����Ѿ�ʹ�ù��Ľڵ������ 
				if(pointsSet.find(toNode) == pointsSet.end()) continue;
				// ���������Ѿ�����һ����֧����ײ��򲻼��� 
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
			// ��¼��С�������ıߣ����ظ� 
			list[temp.from].push_back(make_pair(temp.to,temp.cost));
			list[temp.to].push_back(make_pair(temp.from,temp.cost));
			// ����MST�㼯 
			pointsSet.insert(temp.from);
			pointsSet.insert(temp.to);
		}
	}
	cout << getRes(root);
	return 0;
}

