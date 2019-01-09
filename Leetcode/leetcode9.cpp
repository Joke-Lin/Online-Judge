#include<iostream>
#include<climits>
#include<string>
#include<cstring>
#include<cstdio>
#include<conio.h>
#include<sstream>
#define LOCAL

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str_int;
        stringstream Transform;
        Transform << x;
        str_int = Transform.str();
        if(!isdigit(str_int[0])) return false;
        int i = 0,j = str_int.length()-1;
        while(i <= j && str_int[i]==str_int[j]) i++,j--;
        return i >= j;
    }
};

int main()
{
#ifdef LOCAL
    freopen("../VScode/in.txt","r",stdin);
    freopen("../VScode/out.txt","w",stdout);
#endif
    int INT;
    Solution s;
    while(cin >> INT)
    {
       cout << s.isPalindrome(INT) << endl;
    }
    return 0;
}