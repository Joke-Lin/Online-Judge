#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 贪心
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int Max = 0;
        for(int i = 0;i < nums.size();i++) {
            if(i > Max) return false;
            Max = max(Max,i+nums[i]);
        }
        return true;
    }
};
