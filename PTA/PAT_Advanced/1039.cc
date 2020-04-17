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

using namespace std;

map<string, vector<int>> course_lists;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, k; scanf("%d %d", &n, &k);
    for(int i = 0;i < k;i++) {
        int index, num;
        scanf("%d %d", &index, &num);
        for(int j = 0;j < num;j++) {
            string name; cin >> name;
            if(course_lists.count(name)) {
                course_lists[name].push_back(index);
            }
            else {
                course_lists[name] = {index};
            }
        }
    }
    for(int i = 0;i < n;i++) {
        string name; cin >> name;
        printf("%s ", name.c_str());
        if(course_lists.count(name) == 0) {
            printf("0\n");
        }
        else {
            int len = course_lists[name].size();
            printf("%d ", len);
            sort(course_lists[name].begin(), course_lists[name].end());
            for(int j = 0;j < len;j++) {
                printf("%d", course_lists[name][j]);
                if(j != len - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }

    }
    return 0;
}