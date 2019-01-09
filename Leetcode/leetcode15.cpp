#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        //计算三数之和 先确定第一个
        for (int i = 0; i < size; i++)
        {
            //如果和前面的重复就跳过
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            //定义中间和右边的指针
            int l = i + 1, r = size - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0) //相等的时候特判
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    //将所有的重复元素删去
                    //比如找到 a b c 如果下一个还是 c 或者 b那就重复了
                    while (nums[l] == nums[l - 1])
                        l++;
                    while (nums[r] == nums[r + 1])
                        r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0) //不断向中间逼近
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};

int main()
{
    Solution solo;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector< vector<int> > res = solo.threeSum(nums);
    for(int i = 0;i < res.size();i++)
    {
        for(int j = 0;j < 3;j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}