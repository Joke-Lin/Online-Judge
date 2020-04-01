#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>

#define LOCAL

using namespace std;

struct Record {
    int t, mon, day, hour, mins;
    bool type;  // 1: on-line 0: off-line
    bool operator < (const Record& another) const {
        return t < another.t;
    }
};

map<string, vector<Record>> calls;
int price_table[24], price_day = 0;

ll getCost(Record &tar) {
    int d = tar.day, h = tar.hour, m = tar.mins;
    ll cost = d * price_day;
    for(int i = 0;i < h;i++) {
        cost += price_table[i]*60;
    }
    cost += price_table[h]*m;
    return cost;
}

void printTime(Record &tar) {
    printf("%02d:%02d:%02d", tar.day, tar.hour, tar.mins);
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    for(int i = 0;i < 24;i++) {
        scanf("%d", price_table+i);
        price_day += price_table[i]*60;
    }
    string customer, t, line;
    int n; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        cin >> customer;
        Record temp;
        scanf("%d:%d:%d:%d", &temp.mon, &temp.day, &temp.hour, &temp.mins);
        cin >> line;
        temp.type = line == "on-line";
        temp.t = 24*60*temp.day + 60*temp.hour + temp.mins; // 获取从00:00:00到此的分钟数
        calls[customer].push_back(temp);
    }
    for(auto i : calls) {
        sort(i.second.begin(), i.second.end());
        int size = i.second.size();
        float cost_all = 0;
        bool flag = false;  // 判断是否存在有效时间
        for(int j = 0;j < size - 1;j++) {
            if(i.second[j].type == true && i.second[j+1].type == false) {
                if(!flag) {
                    cout << i.first << " "; printf("%02d\n", i.second[0].mon);
                }
                printTime(i.second[j]);
                printf(" ");
                printTime(i.second[j+1]);
                float temp_cost = (getCost(i.second[j+1]) - getCost(i.second[j]))/100.0;
                printf(" %d $%.2f\n", i.second[j+1].t - i.second[j].t, temp_cost);
                cost_all += temp_cost;
                flag = true;
            }
        }
        if(flag)
            printf("Total amount: $%.2f\n", cost_all);
    }
    return 0;
}