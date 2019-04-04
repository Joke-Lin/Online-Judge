#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, flag = 1;
        for(int i = s.size()-1;i >= 0;i--) {
            if(s[i] == ' ') {
                if(flag) continue;
                else break;
            }
            else {
                flag = 0;
                len++;
            }
        }
        return len;
    }
};