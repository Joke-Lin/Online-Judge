#include <iostream>

using namespace std;

int nums[1001];
int n, k;

int main() {
	cin >> n >> k;
	int res = 0;
	int temp = 0;
	int input;
	for(int i = 0;i < n;i++) {
		cin >> input;
		temp += input;
		if(temp >= k) {
			res++;
			temp = 0;
		}
	}
	if(temp > 0) {
		res++;
	}
	cout << res;
	return 0;
}
