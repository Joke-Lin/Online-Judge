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
    string multiply(string num1, string num2) {
        string res;
        for(int k = num2.length() - 1; k >= 0; k--) {
            string tempRes;
            int get = 0;
            for(int j = num1.length() - 1; j >= 0; j--) {
                int mid = (num2[k]-'0')*(num1[j]-'0');
                mid += get;
                get = mid/10;
                tempRes.insert(0,1,(char)(mid % 10 + '0'));
            }
            if(get != 0) tempRes.insert(0,1,(char)(get + '0'));
            for(int j = 0; j < num2.length()-1-k; j++) tempRes += '0';
            string temp;
            get = 0;
            int i = res.length()-1, j = tempRes.length()-1; // i: res ; j: tempRes
            while(i >= 0 || j >= 0 || get != 0) {
                int sum = get;
                if(i >= 0) sum += res[i] - '0';
                if(j >= 0) sum += tempRes[j] - '0';
                get = sum / 10;
                temp.insert(0, 1, (char)(sum % 10 + '0'));
                i--,j--;
            }
            res = temp;
        }
        int beg = -1;   // 去除多余的前导0
        for(int i = 0;i < res.length()-1;i++) {
            if(res[i] == '0') beg = i;
            else break;
        }
        return res.substr(beg+1);
    }
};

int main() {
    Solution solo;
    cout << solo.multiply("999","22");
}