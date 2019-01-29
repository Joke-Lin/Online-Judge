#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowRepeat[9][9] = {};
        bool colRepeat[9][9] = {};
        bool boxRepeat[9][9] = {};
        for(int i = 0;i < 9;i++) {
            for(int j = 0;j < 9;j++) {
                if(board[i][j] == '.') continue;
                int number = board[i][j] - '1';
                if(rowRepeat[i][number]) return false;
                else rowRepeat[i][number] = true;
                if(colRepeat[j][number]) return false;
                else colRepeat[j][number] = true;
                if(boxRepeat[getBoxindex(i,j)][number]) return false;
                else boxRepeat[getBoxindex(i,j)][number] = true;
            }
        }
        return true;
    }

    int getBoxindex(int row, int col) {
        return (row / 3) * 3 + col / 3;
    }
};