#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(stk.empty()) stk.push(s[i]);
            else {
                if(s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    if((s[i] == ')' && stk.top() != '(') || (s[i] == ']' && stk.top() != '[') 
                        || (s[i] == '}' && stk.top() != '{'))   return false;
                    else stk.pop();
                }
                else stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};