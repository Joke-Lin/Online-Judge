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

struct Stu {
    string name;
    string id;
    int score;
    bool operator < (const Stu& another) {
        return score > another.score;
    }
};

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    vector<Stu> female, male;
    int n, score; scanf("%d", &n);
    string name, id, gender;
    for(int i = 0;i < n;i++) {
        cin >> name >> gender >> id >> score;
        if(gender == "F") {
            female.push_back({name, id, score});
        }
        else {
            male.push_back({name, id, score});
        }
    }
    sort(female.begin(), female.end());
    sort(male.begin(), male.end());
    if(female.size() == 0) {
        printf("Absent\n");
    }
    else {
        printf("%s %s\n", female[0].name.c_str(), female[0].id.c_str());
    }
    if(male.size() == 0) {
        printf("Absent\n");
    }
    else {
        printf("%s %s\n", male[male.size()-1].name.c_str(), male[male.size()-1].id.c_str());
    }
    if(female.size() == 0 || male.size() == 0) {
        printf("NA");
    }
    else {
        printf("%d", female[0].score - male[male.size()-1].score);
    }
    return 0;
}