// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int cur = 0;
        while(cur <= r) {
            if(nums[cur] == 0) {
                swap(nums[cur], nums[l]);
                l++, cur++;
            }
            else if(nums[cur] == 2) {
                swap(nums[cur], nums[r]);
                r--;
            }
            else {
                cur++;
            }
        }
    }
};