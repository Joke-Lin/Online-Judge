#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

struct Stu {
    static int sort_by;
    string id;
    string name;
    int grade;
    bool operator < (const Stu& another) {
        if(sort_by == 1) {
            return id < another.id;
        }
        if(sort_by == 2) {
            return name == another.name ? id < another.id : name < another.name;
        }
        if(sort_by == 3) {
            return grade == another.grade ? id < another.id : grade < another.grade;
        }
    }
};

int Stu::sort_by = 1;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, sort_by;
    scanf("%d %d", &n, &Stu::sort_by);
    vector<Stu> stus;
    for(int i = 0;i < n;i++) {
        Stu temp;
        cin >> temp.id >> temp.name >> temp.grade;
        stus.push_back(temp);
    }
    sort(stus.begin(), stus.end());
    for(auto v : stus) {
        // 不要用cout...
        printf("%s %s %d\n", v.id.c_str(), v.name.c_str(), v.grade);
    }
    return 0;
}