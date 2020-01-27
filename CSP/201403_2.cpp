#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#define LOCAL

using namespace std;

struct Rectange
{
    int x1,y1,x2,y2,order,index;
    bool operator < (Rectange another)
    {
        return order > another.order;
    }
}rec[11];

bool check(int x,int y,const Rectange& another)
{
    if(another.x1 <= x && x <= another.x2 && another.y1 <= y && y <= another.y2) return true;
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int x1,y1,x2,y2;
    int n,m; cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        rec[i] = Rectange{x1,y1,x2,y2,i,i+1};
    }
    while(m--)
    {
        sort(rec,rec+n);
        int index = -1;
        int order = -1;
        int x,y; cin >> x >> y;
        for(int i = 0;i < n;i++)
        {
            if(check(x,y,rec[i]))
            {
                cout <<rec[i].index << endl;
                order = rec[i].order;
                index = i;
                rec[i].order = n-1;
                break;
            }
        }
        if(index == -1){
            cout << "IGNORED" << endl;
            continue;
        }
        for(int i = 0;i < n;i++)
        {
            if(rec[i].order == index) continue;
            if(rec[i].order > order) rec[i].order--;
        }
    }
    return 0;
}