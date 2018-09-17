#include<iostream>
#include<climits>
#include<string>
#include<cstdio>
#include<conio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#define LOCAL

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0,r = height.size() - 1;
        while(l < r)
        {
            res = max(res,(r-l)*min(height[l],height[r]));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return res;
    }
};
int main()
{
#ifdef LOCAL
    freopen("../VScode/in.txt","r",stdin);
    freopen("../VScode/out.txt","w",stdout);
#endif
    string s,p;
    Solution solo;
    vector<int> target = {1,8,6,2,5,4,8,3,7};
    cout << solo.maxArea(target) << endl;
    return 0;
}