#include<iostream>
#include<string>

using namespace std;

int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int main()
{
	 while(true)
	 {
		 int a[100] = {0},b[100] = {0},result[100];
		 int len_a,len_b,i = 0;
		 char c;
		 //input
		 while(scanf("%d%c",&a[i],&c))
		 {
			 i++;
			 len_a = i;
			 if(c == ' ') break;
		 }
		 i = 0;
		 while(scanf("%d%c",&b[i],&c))
		 {
			 i++;
			 len_b = i;
			 if(c == '\n') break;
		 }
		 //数组逆序
		 for(i = 0;i < len_a/2;i++)
		 {
			 int temp = a[i];
			 a[i] = a[len_a-i-1];
			 a[len_a-i-1] = temp;
		 }		
		 
		 for(i = 0;i < len_b/2;i++)
		 {
			 int temp = b[i];
			 b[i] = b[len_b-i-1];
			 b[len_b-i-1] = temp;
		 }
		 
		 if(len_a==1 && len_b==1 && a[0]==0 && b[0]==0) break;

		 int MAX = len_a>len_b?len_a:len_b;
		 
		 int get = 0;
		 
		 for(i = 0;i < MAX;i++)
		 {
			 int sum = a[i]+b[i]+get;
			 result[i] = sum%prime[i];
			 get = sum/prime[i];
		 }
		 
		 if(get) result[MAX++] = get;
		
		 for(int i = MAX-1; i >= 0;i--)
		 {
			 cout << result[i];
			 if(i != 0) cout << ",";
		 }
		 
		 cout << endl;
	 }
	 return 0;
}