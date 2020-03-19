#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int m; scanf("%d", &m);
    string first_name, last_name, first_time, last_time;
    cin >> first_name >> first_time >> last_time;
    last_name = first_name;
    m--;
    string temp_name, temp_in, temp_out;
    while (m != 0) {
        cin >> temp_name >> temp_in >> temp_out;
        if(temp_in < first_time) {
            first_name = temp_name;
            first_time = temp_in;
        }
        if(temp_out > last_time) {
            last_name = temp_name;
            last_time = temp_out;
        }
        m--;
    }
    cout << first_name << " " << last_name;
    return 0;
}