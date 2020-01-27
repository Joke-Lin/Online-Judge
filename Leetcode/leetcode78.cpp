// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

// 说明：解集不能包含重复的子集。

// 示例:

// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp; res.push_back(temp);
        for(auto i = nums.begin();i != nums.end();i++) {
            int size = res.size();
            for(int j = 0;j < size;j++) {
                temp = res[j]; 
                temp.push_back(*i);
                res.push_back(temp);
            }
        }
        return res;
    }
};