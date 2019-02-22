#include <iostream>
#include <conio.h>
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

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        // 先上下变换
        for(int i = 0;i < size/2;i++) {
            for(int j = 0;j < size;j++) {
                swap(matrix[i][j],matrix[size-1-i][j]);
            }
        }
        // 然后沿主对角线变换
        for(int i = 0;i < size;i++) {
            for(int j = 0;j < i;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};