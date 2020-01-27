#include<iostream>
#include<algorithm>
#include<map>
#include<climits>
#include<cstdio>
#include<cstring>
#define LOCAL

using namespace std;

const int maxn = 1010;
const int MOD = 1000000007;//改为long long

class Solotion
{
public:
    int calFun(int n)
    {
        int funNum[maxn][6];
        memset(funNum,0,sizeof(funNum));
        funNum[0][0] = 1;
        for(int i = 1;i < n;i++)
        {
            funNum[i][0] = 1;//2
            funNum[i][1] = (2*funNum[i-1][1]+funNum[i-1][0])%MOD;//2 0
            funNum[i][2] = (funNum[i-1][2]+funNum[i-1][0])%MOD;//2 3
            funNum[i][3] = (funNum[i-1][3]*2+funNum[i-1][1]+funNum[i-1][2])%MOD; //0 2 3
            funNum[i][4] = (funNum[i-1][4]*2+funNum[i-1][1])%MOD;//0 1 2
            funNum[i][5] = (funNum[i-1][5]*2+funNum[i-1][3]+funNum[i-1][4])%MOD;
        }
        return funNum[n-1][5];
    }
};

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n; scanf("%d",&n);
    Solotion solo;
    printf("%d\n",solo.calFun(n));
    return 0;
}