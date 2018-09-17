#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#define LOCAL

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int SIZE = strs.size();
        if(SIZE == 0) return res;
        int minLen = 0x3f3f3f3f;
        for(int i = 0;i < SIZE;i++) minLen = min(minLen,(int)strs[i].size());
        int index = 0;
        while(index < minLen)
        {
            char c = strs[0][index];
            for(int i = 0;i < SIZE;i++)
            {
                if(c != strs[i][index]) return res;
            }
            res += c;
            index++;
        }
        return res;
    }
};

int main()
{
#ifdef LOCAL
    freopen("../VScode/in.txt","r",stdin);
    freopen("../VScode/out.txt","w",stdout);
#endif
    Solution solo;
    vector <vector<string>> TRY = {{"flower","flow","flight"},{"dog","racecar","car"},{"res","res","re"}};
    for(auto i : TRY)
    {
        cout << solo.longestCommonPrefix(i) << endl;
    }

    return 0;
}