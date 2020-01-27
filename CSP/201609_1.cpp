#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int num[1001];
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", num+i);
	}
	int res = 0;
	for(int i = 1;i < n;i++) {
		res = max(abs(num[i]-num[i-1]), res);
	}
	printf("%d", res);
	return 0;
}
