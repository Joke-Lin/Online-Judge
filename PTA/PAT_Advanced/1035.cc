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

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    string name, password;
    vector<pair<string, string>> res;
    for(int i = 0;i < n;i++) {
        cin >> name >> password;
        bool flag = false;
        for(int j = 0;j < password.size();j++) {
            if(password[j] == '1') {
                password[j] = '@';
                flag = true;
            }
            else if(password[j] =='0') {
                password[j] = '%';
                flag = true;
            }
            else if(password[j] == 'l') {
                password[j] = 'L';
                flag = true;
            }
            else if(password[j] == 'O') {
                password[j] = 'o';
                flag = true;
            }
        }
        if(flag) {
            res.push_back({name, password});
        }
    }
    if(res.size() == 0) {
        printf("There %s %d account%s and no account is modified", n == 1 ? "is" : "are", n, n == 1 ? "" : "s");
    }
    else {
        printf("%d\n", res.size());
        for(auto i : res) {
            printf("%s %s\n", i.first.c_str(), i.second.c_str());
        }
    }
    return 0;
}