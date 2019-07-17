// 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
// 常数空间

#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool flagRow = false, flagCol = false;

        // this i,j must be initialized to 1
        for(int i = 0;i < rows;i++) {
            for(int j = 0;j < cols;j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) {
                        flagCol = true;
                    }
                    if(j == 0) {
                        flagRow = true;
                    }
                    else if(i != 0 && j != 0) {
                        matrix[0][j] = matrix[i][0] = 0;
                    }
                }
            }
        }


        for (int i = 1;i < rows;i++) {
            if(matrix[i][0] == 0) {
                // attention here j = 1
                for(int j = 1;j < cols;j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1;j < cols;j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1;i < rows;i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(flagRow) {
            for(int i = 0;i < rows;i++) {
                matrix[i][0] = 0;
            }
        }

        if(flagCol) {
            for(int i = 0;i < cols;i++) {
                matrix[0][i] = 0;
            }
        }
    }
};

int main() {
    return 0;
}