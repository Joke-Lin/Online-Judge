// 已知N个糖果的重量和价值. 我们有一个口袋, 最多可以装V重量的糖果. 问口袋最多能放多少价值的糖果进去?
// Input
// 输入的第一行是T, 表示有T组数据.
// 每组数据由三行组成.
// 第一行包含两个整数N和V(N <= 1000, V <= 1000). N表示糖果的个数, V表示口袋的载重.
// 第二行包含N个整数, 表示每一颗糖果的价值.
// 第三行包含N个整数, 表示每一颗糖果的重量.
// Output
// 对每一组数据, 输出口袋最终可以放进去糖果的价值.
//
// Sample Input
// 1
// 5 10
// 1 2 3 4 5
// 5 4 3 2 1
// Sample Output
// 14

#include<iostream>

using namespace std;

struct Candy
{
	int wei,val;
}Candies[1010];

int Big_Val(int weight,int n)
{
	int F[1010] = {0};
	for(int i = 0;i < n;i++)
		for(int j = weight;j >= Candies[i].wei;j--)
			F[j] = max(F[j],F[j-Candies[i].wei]+Candies[i].val);
	return F[weight];
}

int main()
{
	int number;
	cin >> number;
	while(number--)
	{
		int num,Weight;
		cin >> num >> Weight;
		for(int i = 0;i < num;i++) cin >> Candies[i].val;
		for(int i = 0;i < num;i++) cin >> Candies[i].wei;
		cout << Big_Val(Weight,num) << endl;
	}

	return 0;
}
