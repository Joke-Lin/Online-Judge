#include<iostream>
#include<algorithm>
#include<conio.h>
#include<string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if(x < 0) flag = true;
        x = abs(x);
        int sum = 0;
        string str;
        while(x > 0)
        {
            char c = x%10+'0';
            str = str + c;
            x /= 10;
        }
        str.reserve();
        int len = str.size();
        for(int j = 0;j < len;j++)
        {
            if(j == len-1 && sum > 0x7fffffff/10) return 0;
            sum *= 10;
            sum += str[j]-'0';
        }
        return flag == true ? -sum : sum;
    }
};

int main()
{
    Solution my_solusion;
    int num;
    while(scanf("%d",&num))
    {
        printf("%d\n",my_solusion.reverse(num));
    }
    return 0;
}