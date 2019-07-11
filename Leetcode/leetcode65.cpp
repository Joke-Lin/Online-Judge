// 验证给定的字符串是否可以解释为十进制数字。
// 例如:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int charToInt(char c) {
        if(c == ' ') {
            return 0;
        }
        else if(c >= '0' && c <= '9') {
            return 1;
        }
        else if(c == '-' || c == '+') {
            return 2;
        }
        else if(c == '.') {
            return 3;
        }
        else if(c == 'e') {
            return 4;
        }
        else {
            return 5;
        }
    }
    bool isNumber(string s) {
        // 列为 0:空格，1:数字，2:符号，3:点，4:e
        // 行表示状态编号
        // 对应的值是需要切换的状态
        s += ' ';
        int states[][5] = {
            {0, 2, 1, 3, -1},
            {-1, 2, -1, 3, -1},
            {8, 2, -1, 4, 5},
            {-1, 4, -1, -1, -1},
            {8, 4, -1, -1, 5},
            {-1, 7, 6, -1, -1},
            {-1, 7, -1, -1, -1},
            {8, 7, -1, -1, -1},
            {8, -1, -1, -1, -1}
        };
        int state = 0;  // 初始状态
        int index;
        for(int i = 0;i < s.length();i++) {
            index = charToInt(s.at(i));
            if(index == 5) {
                return false;
            }
            state = states[state][index];
            if(state < 0) {
                return false;
            }
        }
        if(state == 8) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() 
{
    Solution solo;
    string s;
    while(cin >> s) {
        cout << solo.isNumber(s) << endl;
    }
}