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
typedef long long ll;

bool cmp(string &a, string &b) {
    int i = 0;
    while(i != a.size() && i != b.size()) {
        if(a[i] < b[i]) {
            return true;
        }
        else if(a[i] > b[i]) {
            return false;
        }
        i++;
    }
    string c = a+b, d = b+a;
    i = 0;
    while(i != c.size()) {
        if(c[i] < d[i]) {
            return true;
        }
        else if(c[i] > d[i]) {
            return false;
        }
        i++;
    }
    return true;
}


int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    string num_str;
    vector<string> seq;
    for(int i = 0;i < n;i++) {
        cin >> num_str;
        seq.push_back(num_str);
    }
    sort(seq.begin(), seq.end(), cmp);
    bool flag = false;
    for(auto i : seq) {
        if(!flag) {
            for(int j = 0;j < i.length();j++) {
                if(i[j] != '0') {
                    flag = true;
                    cout << i[j];
                }
                else {
                    if(flag) {
                        cout << i[j];
                    }
                }
            }
        }
        else {
            cout << i;
        }
    }
    if(!flag) {
        cout << "0";
    }
    return 0;
}