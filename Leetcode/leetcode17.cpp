#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    map<char,string> list;
    vector<string> letterCombinations(string digits) {
        list.insert(make_pair('2',"abc"));
        list.insert(make_pair('3',"def"));
        list.insert(make_pair('4',"ghi"));
        list.insert(make_pair('5',"jkl"));
        list.insert(make_pair('6',"mno"));
        list.insert(make_pair('7',"pqrs"));
        list.insert(make_pair('8',"tuv"));
        list.insert(make_pair('9',"wxyz"));
        vector<string> res;
        getRes(0,digits,res,"");
        return res;
    }

    void getRes(int cur, string &digits , vector<string> &res, string temp)
    {
        if(digits.size() == 0) return;
        if(cur == digits.size()) res.push_back(temp);
        string codes = list[digits[cur]];
        for(int i = 0;i < codes.size();i++) getRes(cur+1,digits,res,temp+codes[i]);
    }
};

int main()
{
    Solution solu;
    vector<string> rs = solu.letterCombinations("23");
    for(int i = 0;i < rs.size();i++)
    {
        cout << rs[i] << endl;
    }
    return 0;
}