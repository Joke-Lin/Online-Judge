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
#define LOCAL

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    float tank, dis, avg, n;
    scanf("%f %f %f %f", &tank, &dis, &avg, &n);
    vector<pair<float, float> > gas_stations;
    for(int i = 0;i < n;i++) {
        float v, d;
        scanf("%f %f", &v, &d);
        gas_stations.push_back({d, v});
    }
    gas_stations.push_back({dis, 0});   // 将最后一个站设为免费加油站 便于后面处理
    sort(gas_stations.begin(), gas_stations.end()); // 按距离排序
    // 起始位置没有加油站
    if(gas_stations[0].first != 0) {
        printf("The maximum travel distance = %.2f", 0);
        return 0;
    }
    float cost = 0, last_gas = 0;  // 开销 & 到此加油站剩余油
    int cur_pos = 0, stations_size = gas_stations.size();
    while(true) {
        float next_dis = gas_stations[cur_pos].first + tank*avg;  // 在这个站满油情况下的可以开到的最远位置
        int tar_pos = -1;   // 获取开销最小的下一个加油站
        // 从这段距离中获取合适的
        for(int i = cur_pos+1;i < stations_size;i++) {
            if(gas_stations[i].first > next_dis) {
                break;
            }
            tar_pos = i;
            if(gas_stations[i].second <= gas_stations[cur_pos].second) {
                break;
            }
        }
        // 不能到达到下一个站
        if(tar_pos == -1) {
            printf("The maximum travel distance = %.2f", next_dis);
            return 0;
        }
        float gas_need; // 需要购买的油
        // 有价格更小的站
        if(gas_stations[tar_pos].second <= gas_stations[cur_pos].second) {
            gas_need = (gas_stations[tar_pos].first-gas_stations[cur_pos].first)/avg - last_gas;
            last_gas = 0;   // 直接买足够到下一个站的油即可
        }
        // 价格都比它大
        else {
            gas_need = tank - last_gas;   // 直接加满
            last_gas = (next_dis - gas_stations[tar_pos].first)/avg; // 更新到下一个站的油量
        }
        cost += gas_need*gas_stations[cur_pos].second;
        // 到达目标地
        if(tar_pos == stations_size-1) {
            break;
        }
        cur_pos = tar_pos;
    }
    printf("%.2f", cost);
    return 0;
}