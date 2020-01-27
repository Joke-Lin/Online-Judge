#include<iostream>
#include<algorithm>
#define LOCAL

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int Pos[110];
    int order_begin[110];
    int Pos_end[110];
    int n,length,seconds;
    cin >> n >> length >> seconds;
    for(int i = 0;i < n;i++) cin >> Pos[i];
    for(int i = 0;i < n;i++) //获取初始顺序和最后的位置
    {
        int pos = Pos[i];
        int order = 0;
        for(int j = 0;j < n;j++)
        {
            if(Pos[j] < pos) order++;
        }
        order_begin[i] = order;
        int turn = (pos+seconds)/length;
        int final_pos = (pos+seconds)%length;
        if(turn % 2 == 0) Pos_end[i] = final_pos;
        else Pos_end[i] = length-final_pos;
    }
    sort(Pos_end,Pos_end+n);
    for(int i = 0;i < n;i++)
    {
       cout << Pos_end[order_begin[i]] << " ";
    }
    return 0;
}