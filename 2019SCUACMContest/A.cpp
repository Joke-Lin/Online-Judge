#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int,int> Area;

bool cmp(Area a, Area b) {
    return a.second < b.second;
}

int getNums(vector<Area> &areas) {
    sort(areas.begin(), areas.end(), cmp);
    int num = 1;
    int end = areas[0].second;
    for(int i = 1;i < areas.size();i++) {
        if(areas[i].first < end) continue;
        num++;
        end = areas[i].second;
    }
    return num;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        vector<Area> temp;
        for(int i = 0;i < n;i++) {
            Area area;
            scanf("%d%d", &area.first, &area.second);
            temp.push_back(area);
        }
        printf("%d\n",getNums(temp));
    }
    return 0;
}