#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> res;
        int get = 0;
        int tempDigit;
        for(auto i = digits.begin();i != digits.end();i++) {
            tempDigit = *i + get;
            if(i == digits.begin()) {
                tempDigit++;
            }
            res.push_back(tempDigit % 10);
            get = tempDigit / 10;
            tempDigit /= 10;
        }
        if(tempDigit != 0) {
            res.push_back(tempDigit);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};