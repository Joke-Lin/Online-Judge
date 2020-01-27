// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

// - 每行中的整数从左到右按升序排列。
// - 每行的第一个整数大于前一行的最后一个整数。

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        int l = 0, r = rows*cols - 1;

        int i, j, mid;
        while(l <= r) {
            mid = (l + r) >> 1;
            i = mid / cols;
            j = mid % cols;
            if(matrix[i][j] == target) {
                return true;
            }
            else if(matrix[i][j] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return false;
    }
};