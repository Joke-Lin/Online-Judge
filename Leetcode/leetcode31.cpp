#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int k = size - 2;
        while(k >= 0 && nums[k] >= nums[k+1]) k--;
        int small;
        if(k >= 0)
        {
            for(small = size-1;small >= k;small--)
            {
                if(nums[small] > nums[k]) break;
            }
            swap(nums[k],nums[small]);
        }
        reverse(nums.begin()+k+1,nums.end());
    }
};