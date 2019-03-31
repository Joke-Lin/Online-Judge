#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int visited = 0x3f3f3f3f;
        vector<int> res;
        int h = matrix.size();
        if(h == 0) return res;
        int w = matrix[0].size();
        int x = 0,y = 0;    // 定义初始位置
        while(true) {
            bool flag = true;
            // 向右
            while(y < w && matrix[x][y] != visited) {
                res.push_back(matrix[x][y]);
                matrix[x][y++] = visited;
                flag = false;
            }
            y--,x++;
            // 向下
            while(x < h && matrix[x][y] != visited) {
                res.push_back(matrix[x][y]);
                matrix[x++][y] = visited;
                flag = false;
            }
            x--,y--;
            // 向左
            while(y >= 0 && matrix[x][y] != visited) {
                res.push_back(matrix[x][y]);
                matrix[x][y--] = visited;
                flag = false;
            }
            y++,x--;
            // 向上
            while(x >= 0 && matrix[x][y] != visited) {
                res.push_back(matrix[x][y]);
                matrix[x--][y] = visited;
                flag = false;
            }
            x++,y++;
            if(flag) break;
        }
        return res;
    }
};

int main() {
    Solution solo;
    vector<vector<int>> temp = {{1,2,3},{4,5,6},{7,8,9}};
    solo.spiralOrder(temp);
    return 0;
}