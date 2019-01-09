#include<iostream>
#include<climits>
#include<string>
#include<cstdio>
#include<conio.h>
#define LOCAL

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int flag_NEG = 0;
        int flag_BEG = 0;
        bool flag_YiChu = false;
        if(str[0] != '-' && str[0] != '+' && str[0] != ' ' && isalpha(str[0])) return 0;
        for(auto it = str.begin();it != str.end();it++)
        {
            if(*it == ' ' && flag_BEG == 0) continue;
            else if(flag_BEG != -1) flag_BEG = 1;
            if(flag_BEG == 1 && flag_NEG == 0) {
                if(*it == '-' ){
                    flag_NEG = 2;
                    continue;
                }
                else if(*it == '+') {
                    flag_NEG = 1;
                    continue;
                }
                flag_BEG = -1;
            }
            if(flag_NEG != 0 && (*(it-1) == '+' && *it == '-' || *(it-1) == '-' && *it == '+')) return 0;
            if(!isdigit(*it)) break;
            int temp = result;
            result = result * 10;
            if(temp!=0 && (result+(*it-'0') < 0 || result % temp != 0)){
                flag_YiChu = true;
                break;
            }
            else result += (*it-'0');
        }
        if(flag_YiChu){
            if(flag_NEG == 2) return INT_MIN;
            else return INT_MAX;
        }
        if(flag_NEG == 2) return -result;
        else return result;
    }
};

int main()
{
#ifdef LOCAL
    freopen("../VScode/in.txt","r",stdin);
    freopen("../VScode/out.txt","w",stdout);
#endif
    string str;
    Solution s;
    while(getline(cin,str))
    {
        cout << s.myAtoi(str) << endl;
    }
    return 0;
}