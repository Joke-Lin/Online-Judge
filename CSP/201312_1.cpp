#include<iostream>
#include<algorithm>
#include<map>
#define LOCAL

using namespace std;

class Solotion
{
public:
    int maxCount(int n,int num[])
    {
        map<int,int> mapNum;
        int MAX = 1;
        for(int i = 0;i < n;i++)
        {
            if(mapNum.count(num[i]) == 0) mapNum[num[i]] = 1;
            else {
                mapNum[num[i]]++;
                MAX = max(MAX,mapNum[num[i]]);
            }
        }
        for(map<int,int>::iterator it = mapNum.begin();it != mapNum.end();it++)
        {
            if(it->second == MAX){
                return it->first;
            }
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n,num[1000];
    Solotion solo;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> *(num+i);
    cout << solo.maxCount(n,num) << endl;
    return 0;
}