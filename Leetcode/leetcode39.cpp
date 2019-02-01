#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        if(candidates.size() == 0 || target <= 0) return res;
        dfs(res,candidates,target,0,temp);
        return res;
    }
    void dfs(vector<vector<int>> &res,vector<int>& candidates, int target, int index, vector<int> tempList) {
        if(target == 0) {
            res.push_back(tempList);
            return;
        }
        if(index == candidates.size() || target < 0) return;
        for(int i = 0;i <= target/candidates[index];i++) {   // 不取当前值，或者取到整除减1，需先按照先序排列
            if(i != 0) tempList.push_back(candidates[index]);
            dfs(res,candidates,target-i*candidates[index],index+1,tempList);
        }
    }
};