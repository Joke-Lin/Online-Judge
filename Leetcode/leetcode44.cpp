#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>
#include <algorithm>
#include <set>
#define SEE(x) cout << #x << " : " << x << endl;

using namespace std;

/*
"aab"
"c*a*b"

"mississippi"
"m??*ss*?i*pi"

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int judge[1100][1100] = {0};
        if(!s.empty() && p.empty()) return false;
        if(s.empty() && p.empty()) return true;
        if(s.empty() && !p.empty()) {
            for(int i = 0;i < p.length();i++) {
                if(p[i] != '*') return false;
            } 
            return true;
        }

        int sLength = s.length(), pLength = p.length();
       
        for(int i = 0;i < pLength;i++) {
            if(p[i] == '*') {
                bool flag = false;
                for(int j = 0;j < sLength;j++) {
                    if(flag || i == 0) judge[i][j] = true;
                    if(i != 0 && judge[i-1][j] == true) {
                        flag = true;
                        judge[i][j] = true;
                    }
                }
            }
            else if(p[i] == '?') {
                if(i == 0) {
                    for(int j = 0;j < sLength;j++) judge[i][j] = false;
                    judge[0][0] = true;
                }
                else {
                    for(int j = 0;j < sLength;j++) {
                        if(j == 0) judge[i][j] = (judge[i-1][j] && isAllStar(p,i-1));
                        else if(judge[i-1][j-1] == true) judge[i][j] = true;
                    }
                }
            }
            else {
                if(i == 0) {
                    for(int j = 0;j < sLength;j++) judge[i][j] = false;
                    judge[0][0] = (p[0] == s[0]);
                }
                else {
                    for(int j = 0;j < sLength;j++) {
                        if(j == 0) judge[i][j] = (judge[i-1][j] && p[i] == s[j] && isAllStar(p,i-1));
                        else if(judge[i-1][j-1] == true) judge[i][j] = (p[i] == s[j]);
                    }
                }
            }
        }

        return judge[pLength-1][sLength-1];
    }

    bool isAllStar(string &str, int pos) {
        for(int i = 0;i <= pos;i++) {
            if(str[i] != '*') return false;
        }
        return true;
    }
};