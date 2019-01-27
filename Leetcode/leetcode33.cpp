#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

// 一分为二
// 有序二分查找，无序则继续递归
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchHelp(nums,target,0,nums.size()-1);
    }

    int searchHelp(vector<int> &nums, int target, int left, int right) {
        if(left > right) return -1;
        if(left == right) return (nums[left] == target ? left : -1);
        int mid = (left + right)/2;
        int res = -1;
        if(nums[left] < nums[mid]) res = binarySearch(nums,target,left,mid);
        else res = searchHelp(nums,target,left,mid);
        if(res == -1) {
            if(nums[mid+1] < nums[right]) res = binarySearch(nums,target,mid+1,right);
            else res = searchHelp(nums,target,mid+1,right);
        }
        return res;
    }

    int binarySearch(vector<int>& nums, int target, int beg, int end) {
        while(beg <= end) {
            int mid = (beg + end)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) beg = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};