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

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n;
    priority_queue<ll> cou_que, prod_que;
    priority_queue<ll, vector<ll>, greater<ll> > cou_que_neg, prod_que_neg;
    scanf("%d", &n);
    ll v;
    for(int i = 0;i < n;i++) {
        scanf("%lld", &v);
        if(v > 0) {
            cou_que.push(v);
        }
        else if(v < 0) {
            cou_que_neg.push(v);
        }
    }
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%lld", &v);
        if(v > 0) {
            prod_que.push(v);
        }
        else if(v < 0) {
            prod_que_neg.push(v);
        }
    }
    ll res = 0;
    while(!cou_que.empty() && !prod_que.empty()) {
        res += cou_que.top()*prod_que.top();
        cou_que.pop();
        prod_que.pop();
    }
    while(!cou_que_neg.empty() && !prod_que_neg.empty()) {
        res += cou_que_neg.top()*prod_que_neg.top();
        cou_que_neg.pop();
        prod_que_neg.pop();
    }
    cout << res;
    return 0;
}