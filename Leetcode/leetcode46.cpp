#include <iostream>
#include <conio.h>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>
#include <algorithm>
#include <set>
#define SEE(x) cout << #x << " : " << x << endl;

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        int size = nums.size();
        if(size == 1 || size == 0) return res;
        while(true) {
            int j = size-2;
            while(j >= 0 && nums[j] >= nums[j+1]) j--;   // 获取第一个不符合升序的位置
            if(j < 0) break;
            int i = size - 1;
            while(i > j && nums[i] <= nums[j]) i--;     // 在其右获取第一个比它大的数的位置
            swap(nums[i],nums[j]);                      // 交换两个数
            int r = size - 1;
            int l = j + 1;
            while(r > l) {
                swap(nums[r],nums[l]);
                r--, l++;
            }
            // for(int k = 0;k < size;k++) {
            //     cout << nums[k] << " ";
            // }
            // cout << endl;
            // getch();
            res.push_back(nums);
        }
        return res;
    }
};


int main() {
    Solution solo;
    vector<int> ex = {1,1,3,2};
    vector<vector<int>> res = solo.permute(ex);
    SEE(res.size());
    for(int i = 0;i < res.size();i++) {
        for(int j = 0;j < res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}














