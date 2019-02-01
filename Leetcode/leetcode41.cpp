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
// 数据特别小 只要10000 足够 此时用时4ms
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool positive[100000] = {};
        fill(positive,positive+100000,false);
        for(int i = 0;i < nums.size();i++) {
            if(i >= 0) positive[i] = true;
        }
        for(int i = 1;i < 100000;i++) {
            if(positive[i] == false) return i;
        }
        return 1;
    }
};