#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        creatBracket(n,0,0,0,temp,res);
        return res;
    }

    void creatBracket(int size, int index, int numberOfLeft,int numberOfMatch,string tar, vector<string> &res)
    {
        if(index == 2*size) 
        {
            res.push_back(tar);
            return;
        }
        if(numberOfMatch > 0) creatBracket(size,index+1,numberOfLeft,numberOfMatch-1,tar+')',res);
        if(numberOfLeft < size) creatBracket(size,index+1,numberOfLeft+1,numberOfMatch+1,tar+'(',res);
    }
};