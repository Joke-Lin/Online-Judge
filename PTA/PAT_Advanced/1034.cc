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

map<string, map<string, int> > Map;
set<string> p_visited;
set<pair<string, string> > e_visited;

string head;    // 头目
int max_weight, node_sum;   // 某节点最大权值 以及 帮的人员数量
int dfs(string root) {
    if(!p_visited.count(root)) {
        node_sum++;
    }
    int weight_sum = 0;
    int root_weight = 0;
    p_visited.insert(root);
    for(auto i : Map[root]) {
        root_weight += i.second;
        // 遍历过的边不再遍历
        if(!e_visited.count({root, i.first})) {
            e_visited.insert({root, i.first});
            e_visited.insert({i.first, root});
            weight_sum += i.second + dfs(i.first);
        }
    }
    if(root_weight > max_weight) {
        max_weight = root_weight;
        head = root;
    }
    return weight_sum;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, k; scanf("%d %d", &n, &k);
    string A, B;
    int weight;
    for(int i = 0;i < n;i++) {
        cin >> A >> B >> weight;
        // 有了叠加 没有覆盖 开始测试点2错误 如下。。。
        /*
        if(Map.count(A)) {
            Map[A][B] += weight;
            Map[B][A] += weight;
        } else {
            Map[A] = {{B, weight}};
            Map[B] = {{A, weight}};
        }*/
        if(Map.count(A)) {
            Map[A][B] += weight;
        } else {
            Map[A] = {{B, weight}};
        }
        if(Map.count(B)) {
            Map[B][A] += weight;
        } else {
            Map[B] = {{A, weight}};

        }
    }
    map<string, int> res;
    for(auto i : Map) {
        if(!p_visited.count(i.first)) {
            node_sum = 0;
            max_weight = 0;
            int weights = dfs(i.first);
            if(weights > k && node_sum > 2) {
                res.insert({head, node_sum});
            }
        }
    }
    printf("%d\n", res.size());
    for(auto i : res) {
        printf("%s %d\n", i.first.c_str(), i.second);
    }
    return 0;
}