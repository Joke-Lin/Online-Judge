#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 10002;
int DFN[maxn];
int LOW[maxn];
vector<int> G[maxn];
bool isInStack[maxn];
stack<int> s;
int index = 0;

void tarjan(int root, int &res) {
	DFN[root] = LOW[root] = ++index;
	s.push(root);
	isInStack[root] = true;
	for(int i = 0;i < G[root].size();i++) {
		int v = G[root][i]; 
		if(DFN[v] == 0) {
			tarjan(v, res);
			LOW[root] = min(LOW[root], LOW[v]);
		}
		else if(isInStack[v]) {
			LOW[root] = min(LOW[root], DFN[v]);
		}
	}
	if(DFN[root] == LOW[root]) {
		int num = 0, v;
		do{
			v = s.top(); s.pop();
			isInStack[v] = false;
			num++;
		} while(v != root);
		res += num*(num-1)/2;
	}
}

int main() {
	int n, m; cin >> n >> m;
	memset(DFN, 0, sizeof(DFN));
	memset(isInStack, 0, sizeof(isInStack));
	for(int i = 0;i < m;i++) {
		int s, t;	cin >> s >> t;
		G[s].push_back(t);
	}
	int res = 0;
	for(int i = 1;i <= n;i++) {
		if(DFN[i] == 0) {
			tarjan(i, res);
		}
	}
	cout << res;
	return 0;
}
