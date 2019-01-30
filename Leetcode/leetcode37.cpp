#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        isLegal(board,0);
    }

    bool isLegal(vector<vector<char>>& board, int order) {  
        if(order == 81) return true;
        int row = order/9;
        int col = order%9;
        if(board[row][col] != '.') return isLegal(board,order+1);
        vector<int> someLegalChoice = getLegalNumbers(board,order);
        if(someLegalChoice.empty()) return false;
        for(int i = 0;i < someLegalChoice.size();i++) {
            board[row][col] = someLegalChoice[i]+'0';
            bool flag = isLegal(board,order+1);
            if(flag == false) {
                board[row][col] = '.';
            } else return true;
        }
        return false;
    }

    int getBoxindex(int row, int col) {
        return (row / 3) * 3 + col / 3;
    }

    vector<int> getLegalNumbers(vector<vector<char>>& board, int order) {
        int row = order/9;
        int col = order%9;
        int boxIndex = getBoxindex(row,col);
        int pos[9]; fill(pos,pos+9,1);
        for(int i = 0;i < 9;i++) {
            for(int j = 0;j < 9;j++) {
                if(board[i][j] == '.') continue;
                if(i == row || j == col || boxIndex == getBoxindex(i,j)) {
                    pos[board[i][j]-'1'] = 0;
                }
            }
        }
        vector<int> res;
        for(int i = 0;i < 9;i++) {
            if(pos[i] == 1) res.push_back(i+1);
        }
        return res;
    }
};

int main() {
    Solution solo;
    return 0;
}