/*!
	连通图判断 欧拉路径判断
	并查集 + DFS 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define LOCAL 

using namespace std;

const int maxn = 1e4+5; 

int n,m;
int father[maxn];
int rank[maxn];
set<int> roads[maxn];	// 自动排序 
bool used[maxn][maxn];
vector<int> path;

void init() {
	for(int i = 1;i <= n;i++) {
		father[i] = i;
		rank[i] = 0;
		//for(int j = 1;j <= n;j++) used[i][j] = used[j][i] = false;
	}
}

int find(int x) {
	return father[x] == x ? x : father[x] = find(father[x]); 
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rank[x] < rank[y]) father[x] = y;
	else {
		father[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

void dfs(int node) {
	for(set<int>::iterator it = roads[node].begin();it != roads[node].end();it++) {
		if(!used[node][*it]) {
			used[node][*it] = true;
			used[*it][node] = true;
			dfs(*it);
		}
	}
	path.push_back(node);
}

int main()
{
#ifdef LOCAL
	freopen("./in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	init();
	for(int i = 1;i <= m;i++) {
		int st,ed; scanf("%d%d",&st,&ed);
		roads[st].insert(ed);
		roads[ed].insert(st);
		merge(st,ed);
	}
	// 判断是否连通 
	int tempFather = find(1);
	bool isEuler = true;
	for(int i = 1;i <= n;i++) {
		if(find(i) != tempFather) {
			isEuler = false;
			break;
		}
	}
	// 判断是否存在欧拉路径
	int oddNum = 0;
	if(isEuler) {
		for(int i = 1;i <= n;i++) {
			if(roads[i].size()%2 != 0) oddNum++;
		}
		if(!(oddNum == 0 || (oddNum == 2 && roads[1].size() % 2 == 1))) isEuler = false;
	}
	if(!isEuler) {
		cout << -1;
		return 0;
	}
	dfs(1);
	for(int i = path.size()-1;i >= 0;i--) {
		cout << path[i] << " ";
	}
	return 0;
}
