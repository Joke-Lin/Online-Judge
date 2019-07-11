/* 
    给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
    你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
    要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
    文本的最后一行应为左对齐，且单词之间不插入额外的空格。

    说明:

    单词是指由非空格字符组成的字符序列。
    每个单词的长度大于 0，小于等于 maxWidth。
    输入单词数组 words 至少包含一个单词。
    示例:

    输入:
    words = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth = 16
    输出:
    [
       "This    is    an",
       "example  of text",
       "justification.  "
    ]
    示例 2:

    输入:
    words = ["What","must","be","acknowledgment","shall","be"]
    maxWidth = 16
    输出:
    [
      "What   must   be",
      "acknowledgment  ",
      "shall be        "
    ]
    解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
         因为最后一行应为左对齐，而不是左右两端对齐。       
        第二行同样为左对齐，这是因为这行只包含一个单词。
    示例 3:

    输入:
    words = ["Science","is","what","we","understand","well","enough","to","explain",
             "to","a","computer.","Art","is","everything","else","we","do"]
    maxWidth = 20
    输出:
    [
      "Science  is  what we",
    "understand      well",
      "enough to explain to",
      "a  computer.  Art is",
      "everything  else  we",
      "do                  "
    ]
*/

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<int> wordsOfLine;    // save the line words' index 
        int cur = 0;
        int size = words.size();
        while(cur < size) {
            wordsOfLine.clear();
            int len = 0;    // length of all words and minimum space(blank)
            int realLen = 0;    // length of all words
            // select the index array for one line
            while (cur < size) {
                int tempLen = len + words[cur].length();
                if(tempLen > maxWidth) {
                    break;
                }
                realLen += words[cur].length();
                wordsOfLine.push_back(cur++);
                len = tempLen + (tempLen == maxWidth ? 0 : 1);
            }
            int wordsNum = wordsOfLine.size();
            string line = "";
            len = realLen;
            // if not the last line
            if(cur != size) {
                int restSpace = maxWidth - len;
                int i = wordsNum - 1;
                // insert from back to front
                // if the wordNum == 1, it will not insert blank
                // but it will insert last blank in line 107
                while(i >= 0) {
                    line.insert(0, words[wordsOfLine[i]]);
                    if(i != 0) {
                        line.insert(0, restSpace / i, ' ');
                        restSpace -= restSpace / i;
                    }
                    i--;
                } 
            } else {    // meet the last one
                for(int i = 0;i < wordsNum;i++) {
                    line += words[wordsOfLine[i]];
                    if(i != wordsNum - 1) {
                        line += " ";
                    }
                }
            }
            // replenish the line blank
            for(int i = line.length();i < maxWidth;i++) {
                line += " ";
            }
            res.push_back(line);
        }
        return res;
    }
};