#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        int pos[100];
        solve(0,res,pos,n);
        return res;
    }
    void solve(int index, vector<vector<string>> &res, int *pos, int n) {
        if(index == n) {
            res.push_back(creatString(pos,n));
            return;
        }
        for(int i = 0;i < n;i++) {  // 尝试放
            pos[index] = i;
            if(check(pos,index)) {
                solve(index+1,res,pos,n);
            }
        }
    }
    // 检测当前放入的是否合法
    bool check(int *pos, int n) {
        for(int i = 0;i < n;i++) {
            if(abs(pos[i]-pos[n]) == n-i || pos[i] == pos[n]) {
                return false;
            }
        }
        return true;
    }
    
    vector<string> creatString(int *pos, int n) {
        vector<string> str(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                str[j] += (j == pos[i]) ? 'Q' : '.';
            }
        }
        return str;
    }
};

