#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
#define LOCAL

using namespace std;

struct Customer {
    int arrive;
    int leave;
    int serve_secs;
    bool operator < (const Customer & another) {
        return arrive < another.arrive;
    }
}customers[100001];

const int clock_8 = 8*3600;
const int clock_17 = 17*3600;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int whole_wait_sec = 0;
    int legal_nums = 0;
    int n, m; scanf("%d %d",&n, &m);
    for(int i = 0;i < n;i++) {
        int h, m, s, t; scanf("%d:%d:%d %d", &h, &m, &s, &t);
        int arrive = h*60*60 + m*60 + s;
        if(arrive > clock_17) {
            continue;
        }
        customers[legal_nums].arrive = arrive;
        customers[legal_nums++].serve_secs = t > 60 ? 3600 : t*60;
    }
    sort(customers, customers + legal_nums);
    priority_queue<int, vector<int>, greater<int>> leave_que;
    // 先push M 个 8：00 全在8点离开
    for(int i = 0;i < m;i++) {
        leave_que.push(clock_8);
    }
    for(int i = 0;i < legal_nums;i++) {
        int serve_time = max(leave_que.top(), customers[i].arrive); leave_que.pop();
        leave_que.push(serve_time + customers[i].serve_secs);
        whole_wait_sec += serve_time - customers[i].arrive;
    }
    printf("%.1f", legal_nums == 0 ? 0.0 : whole_wait_sec/60.0/legal_nums);
    return 0;
}