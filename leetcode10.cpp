#include<iostream>
#include<climits>
#include<string>
#include<cstdio>
#include<conio.h>
#define LOCAL

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.length() >= 1 && p.length() < 1) return false;
        else return match(s,0,p,0);
    }
    //s为空p不为空不一定不能匹配
    bool match(const string& s,int i,const string& p,int j) {
        cout << "**" << i << "***" << j << endl;
        if(i >= s.length() && j >= p.length()) return true;
        if(i < s.length() && j >= p.length()) return false;
        //下一个不是*号
        if((j+1 < p.length() && p[j+1] != '*') || j+1 == p.length())
        {
            cout << "&&&" << i << "&&&" << j << endl;
            if(i < s.length() && (s[i]==p[j] || p[j]=='.')) return match(s,i+1,p,j+1);
            else return false;
        }
        else{
            //下一个是*号
            //不匹配的情况 以及 类似abb ab*这样的s已经达到最后一个
            if((i < s.length() && s[i]!=p[j] && p[j] != '.')||(i == s.length())) {
                cout << i << " " << j << endl;
                return match(s,i,p,j+2);
            }
            //匹配一个 0个多个
            else return match(s,i,p,j+2) || match(s,i+1,p,j) || match(s,i+1,p,j+2);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("../VScode/in.txt","r",stdin);
    freopen("../VScode/out.txt","w",stdout);
#endif
    string s,p;
    Solution solo;
    while(cin >> s >> p)
    {
       cout << solo.isMatch(s,p) << endl;
    }
    return 0;
}