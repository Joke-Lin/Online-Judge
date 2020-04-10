#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
#define LOCAL

using namespace std;

struct Record {
    string id;
    int score, belong, rank;    // rank 为局部排名
    bool operator < (const Record& another ) {
        return score != another.score ? score > another.score : id < another.id;
    }
};

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    vector<Record> ranklist;
    for(int i = 1;i <= n;i++) {
        int m; scanf("%d", &m);
        vector<Record> temp_ranklist;
        while(m--) {
            Record t;
            cin >> t.id >> t.score;
            t.belong = i;
            temp_ranklist.push_back(t);
        }
        sort(temp_ranklist.begin(), temp_ranklist.end());
        temp_ranklist[0].rank = 1;
        for(int j = 1;j < temp_ranklist.size();j++) {
            temp_ranklist[j].rank = temp_ranklist[j].score == temp_ranklist[j-1].score ? temp_ranklist[j-1].rank : j+1;
        }
        ranklist.insert(ranklist.end(), temp_ranklist.begin(), temp_ranklist.end());
    }
    sort(ranklist.begin(), ranklist.end());
    cout << ranklist.size() << endl;
    int temp_rank = 1;
    for(int i = 0;i < ranklist.size();i++) {
        if(i == 0 || ranklist[i].score != ranklist[i-1].score) {
            temp_rank = i+1;
        }
        cout << ranklist[i].id << " " << temp_rank << " " << ranklist[i].belong << " " << ranklist[i].rank << endl;
    }
    return 0;
}