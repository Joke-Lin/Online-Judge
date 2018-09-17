#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
char a[10000000];
char b[10000000];
char mid[10000000];
int i,j;

void change(char* str)
{
	if(strcmp(str,"0") == 0) return;
	i = 0,j = strlen(str)-1;
	int flag = false;
	for(i = 0;i < strlen(str);i++)
	{
		if(('0' < str[i] && str[i] <= '9') || str[i]=='.') 
		{
			if(str[i] == '.') i--;
			break;
		}
	}
	if(strchr(str,'.')!=NULL)
	{
		for(j = strlen(str)-1;j >= 0;j--)
		{
			if(str[j] != '0' || str[j] == '.')
			{
				if(str[j] == '.') j--;
				break;
			}
		}
	}
	return;
}

int main()
{
	while(~scanf("%s%s",a,b))
	{	
		strcpy(mid,a);
		change(a);
		strncpy(a,mid+i,j-i+1);
		a[j-i+1] = '\0';
		strcpy(mid,b);
		change(b);
		strncpy(b,mid+i,j-i+1);
		b[j-i+1] = '\0';
		printf("%s\n",strcmp(a,b)==0 ? "YES" : "NO");
	}
	return 0;
}
