#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        // i,j,k,h  四个位置指针 从左到右
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if(i != 0 && nums[i] == nums[i-1]) continue; // 避免重复
            for(int j = i+1; j < size; j++)
            {
                if(j != i+1 && nums[j] == nums[j-1]) continue; // 同上
                int k = j+1, h = size-1;
                while(k < h)
                {
                    int sum = nums[i]+nums[j]+nums[k]+nums[h];
                    if(sum == target)
                    {
                        res.push_back({nums[i],nums[j],nums[k],nums[h]});
                        k++, h--;
                        // 排除重复
                        while(nums[k] == nums[k-1]) k++;
                        while(nums[h] == nums[h+1]) h--;
                    }
                    else if(sum < target) k++;
                    else h--;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> num = {1, 0, -1, 0, -2, 2};
    Solution solu;
    vector<vector<int> > res = solu.fourSum(num,0);
    cout << res.size() << endl;
    return 0;
}