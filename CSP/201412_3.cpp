#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#include<cstring>
#define LOCAL

using namespace std;

struct Ticket
{
    double po;
    int s;
    int order;
    int on_off;
}buy[5010],sell[5010];

int cancle[5010];

int order = 1,x = 0,y = 0,z = 0;

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    char cmd[5];
    float po;
    int s;
    while(cin >> cmd)
    {
        if(cmd[0] == 'c') {
            cin >> s;
            cancle[z++] = s;
        }
        else if(cmd[0] == 'b') {
            cin >> po >> s;
            buy[x++] = {po,s,order,1};
        }
        else {
            cin >> po >> s;
            sell[y++] = {po,s,order,1};
        }
        order++;
    }
    return 0;
}