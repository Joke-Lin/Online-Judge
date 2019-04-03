#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()<=1) return intervals;
        // 不使用Lambda反而错。。。
        sort(intervals.begin(),intervals.end(),[](Interval&a,Interval&b){return a.start<b.start;});
        Interval Max = intervals[0];    // 外围最大的
        int size = intervals.size();
        for(int i = 1;i < size;i++) {
            if(intervals[i].start > Max.end) {
                res.push_back(Max);
                Max = intervals[i];
                continue;
            }
            if(intervals[i].end > Max.end) {
                Max.end = intervals[i].end;
            }
        }
        res.push_back(Max);
        return res;
    }
};