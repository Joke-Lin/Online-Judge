#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = nums[0]+nums[1]+nums[2];
        int size = nums.size();
        for(int i = 0;i < size-2;i++)
        {
            int l = i+1;
            int r = size-1;
            while(l < r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(sum - target) < abs(res-target))
                {
                    res = sum;
                    if(res == target) return target;
                }
                else if(sum > target)
                {
                    r--;
                }
                else l++;
            }
        }
        return res;
    }
};

int main()
{
    Solution solo;
    vector<int> nums = {-3,-2,-5,3,-4};
    cout << solo.threeSumClosest(nums,-1);
    return 0;
}