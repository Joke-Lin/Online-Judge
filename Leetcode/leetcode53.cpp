#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> maxNums = nums;
        int Max = maxNums[0];
        for(int i = 1;i < nums.size();i++) {
            maxNums[i] = max(maxNums[i-1] + nums[i],nums[i]);
            Max = max(Max,maxNums[i]);
        }
        return Max;
    }
};


