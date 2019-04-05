#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// https://blog.csdn.net/Hi_KER/article/details/81263889 
// 康托展开
class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        k--;
        vector<int> fac(n+1);
        vector<int> isused(n+1,0);
        fac[0] = 1;
        for(int i = 1;i <= n;i++) {
            fac[i] = fac[i-1]*i;
        }
        for(int i = n-1;i >= 0;i--) {
            int num = k/fac[i];
            k = k%fac[i];
            int index, temp;
            for(index = 1, temp = 0;index <= n;index++) {
                if(isused[index] == 0) temp++;
                if(temp > num) break;
            }
            res += index + '0';
            isused[index] = 1;
        }
        return res;
    }
};