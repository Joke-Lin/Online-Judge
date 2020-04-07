#include <cstdio>
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

const int maxn = 1001;

map<string, set<int>> M[5];  // 存储每个关键字的库

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        int id; scanf("%d", &id); // 注意ID会是0000001
        getchar();  // 读取换行
        string title, author, publisher, year, temp_key;
        vector<string> keys;
        getline(cin, title);
        M[0][title].insert(id);
        getline(cin, author);
        M[1][author].insert(id);
        getline(cin, temp_key);
        stringstream ss(temp_key);
        while(ss >> temp_key) {
            M[2][temp_key].insert(id);
        }
        getline(cin, publisher);
        M[3][publisher].insert(id);
        getline(cin, year);
        M[4][year].insert(id);
    }
    scanf("%d", &n);
    getchar();
    for(int i = 0;i < n;i++) {
        string tar; getline(cin, tar);
        cout << tar << endl;
        int type = tar[0] - '0' - 1;
        tar = tar.substr(3);
        if(M[type].count(tar) == 0) {
            cout << "Not Found" << endl;
        }
        else {
            for(auto v : M[type][tar]) {
                printf("%07d\n", v);    // 注意ID会是0000001
            }
        }
    }
    return 0;
}