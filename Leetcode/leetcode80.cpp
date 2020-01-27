// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

// 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int i = 0, j = 1, num = 1;
        int size = nums.size();
        int last = nums[0];
        for(int i = 1;i < size;i++) {
            if(nums[i] == last) {
                num++;
            }
            else {
                num = 1;
            }
            if(num <= 2) {
                nums[j++] = nums[i];
            }
            last = nums[i];
        }
        return j;
    }
};