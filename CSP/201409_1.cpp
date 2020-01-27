#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#define LOCAL

using namespace std;

int num[10000+10];

class Solotion
{
public:
    int search(int n,int num[])
    {
        int res = 0;
        for(int i = 0;i <= 10000;i++)
        {
            if(num[i] == 1 && num[i+1] == 1) res++;
        }
        return res;
    }

};

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n; cin >> n;
    memset(num,0,sizeof(num));
    for(int i = 0;i < n;i++)
    {
        int x; cin >> x;
        num[x] = 1;
    }
    Solotion solo;
    cout << solo.search(n,num);
    return 0;
}