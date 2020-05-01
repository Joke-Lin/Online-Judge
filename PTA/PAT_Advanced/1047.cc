#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <set>
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m; scanf("%d %d", &n, &m);
    map<int, vector<string>> res;
    for(int i = 0;i < n;i++) {
        string stu;
        int course, num;
        char temp[10];
        scanf("%s %d", temp, &num);
        for(int j = 0;j < num;j++) {
            scanf("%d", &course);
            res[course].push_back(temp);
        }
    }
    for(int i = 1;i <= m;i++) {
        if(res.count(i) == 0) {
            printf("%d 0\n", i);
        }
        else {
            sort(res[i].begin(), res[i].end());
            printf("%d %d\n", i, res[i].size());
            for(auto v : res[i]) {
                printf("%s\n", v.c_str());
            }
        }
    }
    return 0;
}