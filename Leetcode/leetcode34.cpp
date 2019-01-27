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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty()) return {-1,-1};
        // 找左边界
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = (left+right) / 2;
            if(nums[mid] == target) {
                if(mid == 0 || nums[mid-1] != nums[mid]) {
                    res.push_back(mid);
                    break;
                } else {
                    right = mid-1;
                }
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid-1;
        }
        if(res.empty()) return {-1,-1}; // 没有找到直接返回结果
        // 找右边界
        left = res[0], right = nums.size()-1;
        while(left <= right) {
            int mid = (left+right) / 2;
            if(nums[mid] == target) {
                if(mid == nums.size()-1 || nums[mid+1] != nums[mid]) {
                    res.push_back(mid);
                    break;
                } else {
                    left = mid + 1;
                }
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid-1;
        }
        return res;
    }
};