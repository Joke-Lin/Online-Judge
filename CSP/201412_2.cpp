//这里题目比较简单是正方形
#include<iostream>
#include<algorithm>
#include<map>
#define LOCAL

using namespace std;

int num[505][505];

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n; cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) cin >> num[i][j];
    int flag = 1;
    //上半部分
    for(int i = 0;i < n;i++,flag++)
    {
        if(flag & 1)//奇数 ↗
            for(int j = i;j >= 0;j--) cout << num[j][i-j] << " ";
        else
            for(int j = 0;j <= i;j++) cout << num[j][i-j] << " ";
    }
    //下一部分
    if(n & 1) flag = 2;
    else flag = 1;
    for(int i = 1;i < n;i++,flag++)
    {
        if(flag & 1)//奇数 奇数 ↗
            for(int j = i,k = 1;j < n;j++,k++) cout << num[n-k][j] << " ";
        else 
            for(int j = i,k = 1;j < n;j++,k++) cout << num[j][n-k] << " ";
    }
    return 0;
}