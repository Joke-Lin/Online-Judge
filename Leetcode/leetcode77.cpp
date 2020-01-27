// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

// 示例:

// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <vector>

using namespace std;

class Solution {
public:
    int range;  // 数值范围
    int num;    // 需要的组合数的数量
    bool mid[10001];
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        memset(mid, 0, sizeof(mid));
        range = n;
        num = k;
        getAnswer(0, 0);
        return res;
    }

    void getAnswer(int s, int l) {
        if(l == num) {  // 此时已经找到符合条件的数
            vector<int> temp;
            for(int i = 0;i < range;i++) {
                if(mid[i]) {
                    temp.push_back(i+1);
                }
            }
            res.push_back(temp);
            return;
        }
        for(int i = s;i < range;i++) {
            mid[i] = 1;
            getAnswer(i+1, l+1);
            mid[i] = 0; // 回溯
        }
    }
};