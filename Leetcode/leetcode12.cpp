#include<iostream>
#include<climits>
#include<string>
#include<cstdio>
#include<conio.h>
#define LOCAL

using namespace std;

class Solution {
public:
    string addChar(int num,char c)
    {
        string res = "";
        while(num--) res += c;
        return res;
    }
    string intToRoman(int num) {
        int temp;
        string res = "";
        //1000
        temp = num/1000;
        res += addChar(temp,'M'); 
        num = num % 1000;
        //900
        temp = num/900;
        res += temp > 0 ? "CM" : "";
        num %= 900;
        //500
        temp = num/500;
        res += addChar(temp,'D'); 
        num %= 500;
        //400
        temp = num/400;
        res += temp > 0 ? "CD" : "";
        num %= 400;
        //100
        temp = num/100;
        res += addChar(temp,'C'); 
        num = num % 100;
        //90*
        temp = num/90;
        res += temp > 0 ? "XC" : "";
        num %= 90;
        //50
        temp = num/50;
        res += addChar(temp,'L'); 
        num = num % 50;
        //40*
        temp = num/40;
        res += temp > 0 ? "XL" : "";
        num %= 40;
        //10
        temp = num/10;
        res += addChar(temp,'X'); 
        num = num % 10;
        //9*
        temp = num/9;
        res += temp > 0 ? "IX" : "";
        num %= 9;
        //5
        temp = num/5;
        res += addChar(temp,'V'); 
        num = num % 5;
        //4*
        temp = num/4;
        res += temp > 0 ? "IV" : "";
        num %= 4;
        //1
        temp = num/1;
        res += addChar(temp,'I'); 
        num = num % 1;
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
    int TRY[5] = {3,4,9,58,1994};
    for(auto i : TRY)
    {
        cout << solo.intToRoman(i) << endl;
    }
    return 0;
}