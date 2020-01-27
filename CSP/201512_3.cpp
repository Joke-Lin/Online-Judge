#include <cstdio>
#include <algorithm>
#include <cstring>
#define LOCAL

using namespace std;

const int maxn = 101;
char graph[maxn][maxn];
bool isVisited[maxn][maxn];

int r, c, n;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y, char ch) {
	graph[r-y-1][x] = ch;
	isVisited[r-y-1][x] = true;
	for(int i = 0;i < 4;i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(isVisited[r-ny-1][nx]) {
			continue;
		}
		if((nx < 0 || nx >= c) || (r-ny-1 < 0 || r-ny-1 >= r)) {
			continue;
		}
		else if(graph[r-ny-1][nx] != '-' && graph[r-ny-1][nx] != '|' && graph[r-ny-1][nx] != '+') {
			bfs(nx, ny, ch);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("./in.txt", "r", stdin);
#endif
	scanf("%d %d %d", &c, &r, &n);
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			graph[i][j] = '.';
		}
	}
	int cmd;
	int x1, y1, x2, y2;
	for(int i = 0;i < n;i++) {
		scanf("%d", &cmd);
		if(cmd == 0) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			// »­ÊúÏß 
			if(x1 == x2) {
				if(y1 > y2)	swap(y1, y2);
				for(int j = y1;j <= y2;j++) {
					if(graph[r-j-1][x1] == '+')	continue;
					graph[r-j-1][x1] = graph[r-j-1][x1] == '-' ? '+' : '|';
				}
			}
			// »­ºáÏß 
			else {
				if(x1 > x2) swap(x1, x2);
				for(int j = x1;j <= x2;j++) {
					if(graph[r-y1-1][j] == '+') continue;
					graph[r-y1-1][j] = graph[r-y1-1][j] == '|' ? '+' : '-';
				}
			}
		}
		else {
			char ch;
			memset(isVisited, 0, sizeof(isVisited));
			scanf("%d %d %c", &x1, &y1, &ch);
			bfs(x1, y1, ch);
		}
	}
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			printf("%c", graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
