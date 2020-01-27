#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#define LOCAL

using namespace std;

int MAP[105][105];

void draw(int x1,int y1,int x2,int y2)
{
    for(int i = x1;i < x2;i++)
        for(int j = y1;j < y2;j++) MAP[i][j] = 1;
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    memset(MAP,0,sizeof(MAP));
    int x1,y1,x2,y2;
    int n;cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        draw(x1,y1,x2,y2);
    }
    // cout << MAP[1][1] << endl;
    int res = 0;
    for(int i = 0;i <= 100;i++)
    {
        for(int j = 0;j <= 100;j++)
        {
            res += MAP[i][j];
        }
    }
    cout << res;
    return 0;
}