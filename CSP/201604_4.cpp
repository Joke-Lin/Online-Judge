#include<iostream>
#include<cstdio>
#include<vector> 
#include<queue>
#include<cstring>

#define LOCAL

using namespace std;

typedef pair<int,int> P;

struct node{
	int x, y, t;
}; 

int n, m, st;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int visited[100][100][310];

bool isIn(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

int bfs() {
	queue<node> que;
	node start = {0, 0, 0};
	que.push(start);
	while(!que.empty()) {
		node curNode = que.front(); que.pop();
		if(curNode.y == n-1 && curNode.x == m-1) {
			return curNode.t;
		}
		for(int i = 0; i < 4;i++) {
			int x = curNode.x + dx[i], y = curNode.y + dy[i];
			node nextNode = {x, y, curNode.t + 1};
			if(isIn(x, y) && visited[y][x][nextNode.t] == 0) {
				visited[y][x][nextNode.t] = 1;
				que.push(nextNode);
			}
		}
	}
	return 0; 
}

int main() {
#ifdef LOCAL
	freopen("./in.txt","r",stdin);
    //freopen("./out.txt","w",stdout);
#endif
	memset(visited, 0, sizeof(visited));
	scanf("%d %d %d", &n, &m, &st);
	int r,c,a,b;
	for(int i = 0;i < st;i++) {
		scanf("%d %d %d %d", &r, &c, &a, &b);
		for(int j = a; j<= b;j++) {
			visited[c-1][r-1][j] = 1;
		}
	}
	printf("%d\n", bfs());
	return 0;	 
}
