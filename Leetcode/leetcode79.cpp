// 给定一个二维网格和一个单词，找出该单词是否存在于网格中。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

// 示例:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// 给定 word = "ABCCED", 返回 true.
// 给定 word = "SEE", 返回 true.
// 给定 word = "ABCB", 返回 false.

#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isVisited[1001][1001];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int width;
    int height;
    bool exist(vector<vector<char>>& board, string word) {
        memset(isVisited, 0, sizeof(isVisited));
        height = board.size();
        width = board[0].size();
        for(int i = 0;i < height;i++) {
            for(int j = 0;j < width;j++) {
                if(dfs(board, word, 0, j, i)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int index, int x, int y) {
        if(board[y][x] != word[index]) {
            return false;
        }
        // 相等的时候
        if(index == word.size()-1) {
            return true;
        }
        isVisited[y][x] = true;
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= width || ny < 0 || ny >= height) {
                continue;
            }
            if(!isVisited[ny][nx]) {
                if(dfs(board, word, index + 1, nx, ny)) {
                    isVisited[y][x] = false;
                    return true;
                }
            }
        }
        isVisited[y][x] = false;    // 这里也要回溯
        return false;
    }
};