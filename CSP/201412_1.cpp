#include<iostream>
#include<cstdio>
#include<cstring>
#define LOCAL

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n,num[1010],judge[1010];
    memset(num,0,sizeof(num));
    memset(judge,0,sizeof(judge));
    cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        judge[x] += 1;
        num[i] += judge[x];
        cout << num[i] <<" ";
    }
    return 0;
}