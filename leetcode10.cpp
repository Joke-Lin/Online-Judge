#include<iostream>
#include<climits>
#include<string>
#include<cstdio>
#include<conio.h>
#define LOCAL

using namespace std;

class Solution {
public:
    bool isNeedChar(char c){ 
        if(c == '.' || c == '*' ) return true;
        else return false;
    }
    bool isMatch(string s, string p) {
        int i = 0,j = 0;
        int len_s = s.length(),len_p = p.length();
        char c = p[0];
        while(i < len_s && j < len_p)
        {
            // if(!isNeedChar(p[j]) && c != s[i]){
            //     if(j == len_p-1) break;
            //     else if(p[j+1] == '*') j++;
            //     else break;
            // }
            // else{
                
            // }
            while(c == s[i] && i < len_s && j < len_p)
            {
                i++,j++;
                c = p[j];
            }
            if(c == '*')
            {

            }
            
        }
        if(i != len_s || j != len_p) return false;
        else return true;
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