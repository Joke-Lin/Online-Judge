#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


// 自带erase
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int last = 0x3f3f3f3f;
//         for(int i = nums.size()-1;i >= 1;i--)
//         {
//             if(nums[i] == nums[i-1]) nums.erase(nums.begin()+i);
//         }
//         return nums.size();
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = 0;j < nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};