#include <iostream>
#include <vector>
#include <algorithm>

#define LOCAL
#define X 1 //Alice
#define O 2 //Bob

using namespace std;

const int INF = 0x3f3f3f3f;
int chess[3][3]; //棋盘

bool judge(int someone) //判断someone赢了没有
{
    for (int i = 0; i < 3; i++) //横竖
    {
        if (chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2] && chess[i][2] == someone)
            return true;                                                                        //row
        if (chess[0][i] == chess[1][i] && chess[1][i] == chess[2][i] && chess[2][i] == someone) // rol
            return true;
    }
    if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[2][2] == someone)
        return true;
    if (chess[2][0] == chess[1][1] && chess[1][1] == chess[0][2] && chess[0][2] == someone)
        return true;
    return false;
}

int dfs_chess(int who) //模拟who下棋
{
    int block = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (chess[i][j] == 0)
                block++;
    if(who == X && judge(O)) return -block-1;//下之前检查对方有没有赢
    if(who == O && judge(X)) return block+1;
    if(block == 0) return 0; //此时已经下完 结束游戏平局
    int score_x = -INF, score_o = INF;
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(chess[i][j] == 0)
            {
                chess[i][j] = who;
                if(who == X) score_x = max(score_x,dfs_chess(O)); //最大的分数就是最优解 (空格最多)
                if(who == O) score_o = min(score_o,dfs_chess(X));
                chess[i][j] = 0; //回溯
            }
        }
    }
    return who == X ? score_x : score_o;
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> chess[i][j];
        cout << dfs_chess(X) << endl;
    }
    return 0;
}
