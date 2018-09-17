#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string str;
int n;

class Solution {
public:
    string convert(string s, int numRows) {
        const int maxn = 1e3;
        char MAP[maxn][maxn];
        memset(MAP,0,sizeof(MAP));
        int len = s.length();
        int index = 0,i = 0,j = 0;//i 行 j列
        char c;
        while(index < len)
        {
            i = 0;
            while(i < numRows && index < len) MAP[i++][j] = s[index++];
            i -= 2 , j++;
            while(i > 0 && index < len) MAP[i--][j++] = s[index++];
        }
        string result;
        index = 0;
        for(i = 0;i < maxn;i++)
            for(j = 0;j < maxn;j++) {
                if(index > len) return result;
                if(MAP[i][j] != 0) result += MAP[i][j],index++;
            }
        return result;
    }
};

int main()
{
    Solution S;
    while(cin >> str >> n)
    {
        cout << S.convert(str,n) << endl;
    }
    return 0;
}