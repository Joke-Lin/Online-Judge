#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdio>
 
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int nums[1001];
	int res = 0;
	for(int i = 0;i < n;i++) {
		scanf("%d", nums+i);
	}
	if(n > 2) {
		for(int i = 1;i < n-1;i++) {
			if((nums[i]-nums[i-1]) * (nums[i+1]-nums[i]) < 0) {
				res++;
			}
		}
	}
	printf("%d", res);
    return 0;
}
