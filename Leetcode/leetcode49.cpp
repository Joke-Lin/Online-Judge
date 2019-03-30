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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mid;
        vector<vector<string>> res;
        for(int i = 0;i < strs.size();i++) {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(mid.find(temp) == mid.end()) {
                mid[temp] = {i};
            } else {
                mid[temp].push_back(i);
            }
        }
        for(auto i = mid.begin();i != mid.end();i++) {
            vector<string> temp;
            for(auto j = i->second.begin();j != i->second.end();j++) {
                temp.push_back(strs[*j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};