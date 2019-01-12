#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <memory.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned res = divideUnsigned(abs((long long)dividend),abs((long long)divisor));
        int sign = (dividend>0 && divisor<0 || dividend<0 && divisor>0) ? -1 : 1;
        if(sign == 1 && res == 0x80000000) res--;
        return  sign == 1 ? res : -res;
    }

    unsigned divideUnsigned(unsigned dividend, unsigned divisor, int bits = 0)
    {
        if(dividend > divisor) return divideUnsigned(dividend,divisor << 1, bits + 1);
        if(dividend < divisor)
        {
            divisor = divisor >> 1;
            bits--;
        }
        unsigned res = 0;
        while(bits >= 0)
        {
            if(dividend >= divisor) 
            {
                res += 1 << bits;
                dividend = dividend - divisor;
            }
            divisor = divisor >> 1;
            bits--;
        }
        return res;
    }
};