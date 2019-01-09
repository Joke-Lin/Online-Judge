#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <memory.h>

using namespace std;

class Solution {
public:
    int next[100000];
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        getNext(needle);
        int i = 0,j = 0;
        int lenT = needle.size();
        int lenMatch = haystack.size();
        while(i < lenMatch && j < lenT)
        {
            if(j == -1 || haystack[i] == needle[j]) i++,j++;
            else j = next[j];
        }
        if(j == lenT) return i-lenT;
        else return -1;
    }

    void getNext(string &needle)
    {
        int j = 0, k = -1, len = needle.size();
        next[0] = -1;
        while(j < len)
        {
            if(k == -1 || needle[j] == needle[k]) next[++j] = ++k;
            else k = next[k];
        }
    }
};