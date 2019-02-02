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
    int trap(vector<int>& height) {
        if(height.size() < 2) return 0;
        int res = 0, mid = 0;
        for(int i = 0;i < height.size();i++) {
            if(height[i] > height[mid]) mid = i;
        }
        int maxHeight = *height.begin();
        for(int i = 0;i < mid;i++) {
            res += (maxHeight-height[i] > 0) ? maxHeight-height[i] : 0;
            maxHeight = max(maxHeight,height[i]);
        }
        maxHeight = *(height.end()-1);
        for(int i = height.size()-1;i > mid;i--) {
            res += (maxHeight-height[i] > 0) ? maxHeight-height[i] : 0;
            maxHeight = max(maxHeight,height[i]);
        }
        return res;
    }
};