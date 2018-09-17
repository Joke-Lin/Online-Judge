//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
//
//示例 1：
//
//输入: "babad"
//输出: "bab"
//注意: "aba"也是一个有效答案。
//示例 2：
//
//输入: "cbbd"
//输出: "bb"
//对于i->j的字符串，如果是回文字串则if（s[i+1] == s[]
//
//
#include <iostream>
#include <string>

using namespace std;

class solution
{
public:
	string The_big_of_str(string s);
};

string solution:: The_big_of_str(string s)
{
	int len = s.length();
	int start = 0;   //最长字串的开始位置
	int maxLength = 1;  //长度
	bool ifTrue[len][len] = {false};  //true 为是回文字串 false不是
	for(int i = 0;i < len;i++)
	{
		ifTrue[i][i] = true;
		if(i < len-1 && s[i]==s[i+1])
		{
			ifTrue[i][i+1] = true;
			start = i;
			maxLength = 2;
		}
	}
	for(int strLen = 3;strLen <= len ; strLen++)
	{
		for(int i = 0;i <= len-strLen;i++)
		{
			int j = i + strLen - 1; // 子串结束的位置
			if(ifTrue[i + 1][j - 1] && s[i] == s[j]){
				ifTrue[i][j] = true;
				maxLength = strLen;
				start = i;
			}
		}
	}
	if(maxLength > 0)
	{
		return s.substr(start,maxLength);
	}
	else return NULL;
}

int main()
{
	solution sol;
	string str; cin >> str;
	cout << sol.The_big_of_str(str);
	return 0;
}
