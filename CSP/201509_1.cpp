#include <iostream>
#include <cstdio>

using namespace std;

int n;
int list[1010];

int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++) {
		scanf("%d",list+i);
	}
	int piror = list[0];	// µÚÒ»¸ö
	int res = 1;
	for(int i = 0;i < n;i++) {
		if(list[i] != piror) {
			res++;
			piror = list[i];
		}
	}
	printf("%d",res);
	return 0;
}
