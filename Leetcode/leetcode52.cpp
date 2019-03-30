#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        int pos[100];
        solve(0,&res,pos,n);
        return res;
    }
    void solve(int index, int *res, int *pos, int n) {
        if(index == n) {
            *res++;
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
};

