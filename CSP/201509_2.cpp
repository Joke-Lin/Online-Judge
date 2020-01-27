#include <iostream>
#include <cstdio>

using namespace std;

int Mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int year,days;
	scanf("%d%d",&year,&days);
	bool flag;	// true: ÈòÄê 
	if((year%400 == 0) || (year%4 == 0 && year%100 != 0)) Mon[1] = 29;
	int mon = 0;
	for(int i = 0;i < 12;i++) {
		if(days - Mon[i] > 0) days -= Mon[i];
		else {
			mon = i + 1;
			break;
		}
	}
	printf("%d\n%d",mon,days);
	return 0;
}
