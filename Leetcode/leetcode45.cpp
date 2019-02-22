#include <iostream>
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
    int jump(vector<int>& nums) {
        int step = 0;
        int lastPos = 0;
        int maxPos = 0;
        for(int i = 0;i < nums.size();i++) {
            if(i > lastPos) {
                step++;
                lastPos = maxPos;
            }
            maxPos = max(maxPos, i + nums[i]);
        }
        return step;
    }
};