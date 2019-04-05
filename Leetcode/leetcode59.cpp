#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int x = 0,y = 0;    // 定义初始位置
        int num = 1;
        while(true) {
            bool flag = true;
            // 向右
            while(y < n && matrix[x][y] == 0) {
                matrix[x][y++] = num++;
                flag = false;
            }
            y--,x++;
            // 向下
            while(x < n && matrix[x][y] == 0) {
                matrix[x++][y] = num++;
                flag = false;
            }
            x--,y--;
            // 向左
            while(y >= 0 && matrix[x][y] == 0) {
                matrix[x][y--] = num++;
                flag = false;
            }
            y++,x--;
            // 向上
            while(x >= 0 && matrix[x][y] == 0) {
                matrix[x--][y] = num++;
                flag = false;
            }
            x++,y++;
            if(flag) break;
        }
        return matrix;
    }
};