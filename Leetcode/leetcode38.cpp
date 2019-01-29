#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string lastStr = countAndSay(n-1);
        string res;
        char lastChar = 0;
        int sum = 0;
        for(int i = 0;i < lastStr.length();i++) {
            if(sum == 0 || lastStr[i] != lastChar) {
                if(sum != 0) {
                    res += sum+'0';
                    res += lastChar;
                }
                lastChar = lastStr[i];
                sum = 1;
            }
            else if(lastStr[i] == lastChar) {
                sum++;
            }
        }
        res += sum+'0';
        res += lastChar;
        return res;
    }
};