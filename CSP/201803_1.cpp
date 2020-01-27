#include<iostream>
#define LOCAL

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int res = 0,jump = 0,flag = 0;
    while(true)
    {
        cin >> jump;
        if(jump == 1) flag = 0,res += 1;
        if(jump == 2) 
        {
            if(flag == 0) res += 2,flag++;
            else 
            {
                flag ++;
                res += 2*flag;
            }
        }
        if(jump == 0) break;
    }
    cout << res;
    return 0;
}