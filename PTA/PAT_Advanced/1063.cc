#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iterator>
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    set<int> sets[51];
    for(int i = 0;i < n;i++) {
        int cnt, t; scanf("%d", &cnt);
        for(int j = 0;j < cnt;j++) {
            scanf("%d", &t);
            sets[i].insert(t);
        }
    }
    int k; scanf("%d", &k);
    map<pair<int, int>, float> res;
    while(k--) {
        int a, b; scanf("%d %d", &a, &b);
        a--, b--;
        if(res.count({a, b}) == 0) {
            set<int> out1, out2;
            set_union(sets[a].begin(), sets[a].end(), sets[b].begin(), sets[b].end(), inserter(out1, out1.begin()));
            set_intersection(sets[a].begin(), sets[a].end(), sets[b].begin(), sets[b].end(), inserter(out2, out2.begin()));
            float t = out2.size()*100.0/out1.size();
            printf("%.1f%%\n", t);
            res.insert({{a,b}, t});
            res.insert({{b,a}, t});
        }
        else {
            printf("%.1f%%\n", res[{a,b}]);
        }
    }
    
    return 0;
}