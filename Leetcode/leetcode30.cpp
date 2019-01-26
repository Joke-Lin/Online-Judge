//https://www.cnblogs.com/ariel-dreamland/p/9134212.html
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty() || s.empty() || s.length() < words.size()*words[0].length()) return res;

        int lenOfWord = words[0].length();    // 记录单词的长度
        unordered_map<string,int> dict; // 存最初的单词以及出现次数

        for(int i = 0;i < words.size();i++) {   // 初始化最初的dict
            if(dict.find(words[i]) == dict.end()) {
                dict.insert(make_pair(words[i],1));
            } else {
                dict[words[i]]++;
            }
        }
        // 以单词位单位进行遍历
        // strBeg: 每个单词串的开头
        for(int strBeg = 0;strBeg < lenOfWord;strBeg++) {   // 每一个单词串开头
            unordered_map<string,int> tempDict;
            int left = strBeg, len = 0;
            for(int cur = strBeg;cur <= s.length()-lenOfWord;cur += lenOfWord) {
                string substr = s.substr(cur,lenOfWord);
                if(dict.count(substr) == 0) {   // 非法单词
                    tempDict.clear();
                    len = 0;
                    left = cur + lenOfWord;
                } else {
                    if(tempDict[substr] < dict[substr]) {
                        tempDict[substr]++;
                        len++;
                    } else {
                        string temp;
                        while((temp = s.substr(left,lenOfWord)) != substr) {
                            tempDict[temp]--;
                            left += lenOfWord;
                            len--;
                        }
                        left += lenOfWord;
                    }
                    if(len == words.size()) {
                        res.push_back(left);
                        tempDict[s.substr(left,lenOfWord)]--;
                        len--;
                        left += lenOfWord;
                    }
                }
            }
        }
        return res;
    }
};
// 思路同 就是map改成clear而不是直接构造 时间花费巨少
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> res;
//         if(words.empty() || s.empty() || s.length() < words.size()*words[0].length()) return res;

//         int lenOfWord = words[0].length();    // 记录单词的长度
//         unordered_map<string,int> dict; // 存最初的单词以及出现次数

//         for(int i = 0;i < words.size();i++) {   // 初始化最初的dict
//             if(dict.find(words[i]) == dict.end()) {
//                 dict.insert(make_pair(words[i],1));
//             } else {
//                 dict[words[i]]++;
//             }
//         }
//         // 以单词位单位进行遍历
//         // strBeg: 每个单词串的开头
//         for(int strBeg = 0;strBeg < lenOfWord;strBeg++) {   // 每一个单词串开头
//             unordered_map<string,int> tempDict;
//             tempDict = dict;
//             int left = strBeg, len = 0;
//             for(int cur = strBeg;cur <= s.length()-lenOfWord;cur += lenOfWord) {
//                 string substr = s.substr(cur,lenOfWord);
//                 if(dict.count(substr) == 0) {   // 非法单词
//                     tempDict = dict;
//                     len = 0;
//                     left = cur + lenOfWord;
//                 } else {
//                     if(tempDict[substr] != 0) {
//                         tempDict[substr]--;
//                         len++;
//                     } else {
//                         while(s.substr(left,lenOfWord) != substr) {
//                             tempDict[s.substr(left,lenOfWord)]++;
//                             left += lenOfWord;
//                             len--;
//                         }
//                         left += lenOfWord;
//                     }
//                     if(len == words.size()) {
//                         res.push_back(left);
//                         tempDict[s.substr(left,lenOfWord)]++;
//                         len--;
//                         left += lenOfWord;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };