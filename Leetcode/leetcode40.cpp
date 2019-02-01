#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;


class Solution { 
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> tempRes;
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        if(candidates.size() == 0 || target <= 0) return res;
        dfs(tempRes,candidates,target,0,temp);
        for(auto i = tempRes.begin();i != tempRes.end();i++) res.push_back(*i);
        return res;
    }
    void dfs(set<vector<int>> &res,vector<int>& candidates, int target, int index, vector<int> tempList) {
        if(target == 0) {
            res.insert(tempList);
            return;
        }
        if(index == candidates.size() || target < 0) return;
        dfs(res,candidates,target,index+1,tempList);
        tempList.push_back(candidates[index]);
        dfs(res,candidates,target-candidates[index],index+1,tempList);
    }
};

