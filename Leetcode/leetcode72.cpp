// 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int dp[1000][1000];
        // initialize when len1 or len2's length = 0
        for(int i = 0;i < 1000;i++) {
            dp[0][i] = i;
            dp[i][0] = i;
        }
        for(int i = 1;i <= len1;i++) {
            for(int j = 1;j <= len2;j++) {
                // if the last letter are equal then 
                // it equal to i-1,j-1
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                // otherwise, it should add a step of change last letter
                else {
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};