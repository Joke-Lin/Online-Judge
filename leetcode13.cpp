#include<iostream>
#include<climits>
#include<string>
#include<cstdio>
#include<conio.h>
#define LOCAL

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int res = 0;
        for(int i = 0;i < len;i++)
        {
            switch(s[i])
            {
            case 'I':
                if(s[i+1] == 'V') res += 4,i++;
                else if(s[i+1] == 'X') res += 9,i++;
                else res += 1;
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                if(s[i+1] == 'L') res += 40,i++;
                else if(s[i+1] == 'C') res += 90,i++;
                else res += 10;
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                if(s[i+1] == 'D') res += 400,i++;
                else if(s[i+1] == 'M') res += 900,i++;
                else res += 100;
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
            }
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
    string s,p;
    Solution solo;
    string TRY[5] = {"III","IV","IX","LVIII","MCMXCIV"};
    for(auto i : TRY)
    {
       cout <<"i: " << i << " res :"<< solo.romanToInt(i) << endl;
    }
    return 0;
}