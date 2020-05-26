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
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

int l, h;

struct Man {
    int id;
    int V, T;
    bool operator < (const Man &another);
};


bool isSage(Man t) {
    return t.V >= h && t.T >= h;
}

bool isNoble(Man t) {
    return t.T < h && t.V >= h;
}

bool isfool(Man t) {
    return t.V < h && t.T < h && t.V >= t.T;
}

bool judge(Man a, Man b, bool flag = true) {
    if(a.V + a.T == b.V + b.T) {
        if(a.V == b.V) {
            return a.id < b.id;
        }
        return a.V > b.V;
    }
    if(flag) {
        return a.V + a.T > b.V + b.T;
    }
    else {
        return a.V + a.T < b.V + b.T;
    }
}

bool Man::operator< (const Man &another) {
    // 一个圣人 一个不是
    if(isSage(*this) && !isSage(another)) {
        return true;
    }
    if(!isSage(*this) && isSage(another)) {
        return false;
    }
    // 都是圣人
    if(isSage(*this) && isSage(another)) {
        return judge(*this, another);
    }
    // 都不是圣人
    // 君子和 不是君子
    if(isNoble(*this) && !isNoble(another)) {
        return true;
    }
    if(!isNoble(*this) && isNoble(another)) {
        return false;
    }
    // 都是君子
    if(isNoble(*this) && isNoble(another)) {
        return judge(*this, another);
    }
    // 都不是君子
    if(!isNoble(*this) && !isNoble(another)) {
        if(isfool(*this) && !isfool(another)) {
            return true;
        }
        if(!isfool(*this) && isfool(another)) {
            return false;
        }
        if(isfool(*this) && isfool(another)) {
            return judge(*this, another);
        }
        return judge(*this, another);
    }
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n; scanf("%d %d %d", &n, &l, &h);
    vector<Man> vec;
    for(int i = 0;i < n;i++) {
        Man temp;
        scanf("%d %d %d", &temp.id, &temp.V, &temp.T);
        if(temp.T >= l && temp.V >= l) {
            vec.push_back(temp);
        }
    }
    int len = vec.size();
    sort(vec.begin(), vec.end());
    printf("%d\n", len);
    for(int i = 0;i < len;i++) {
        printf("%08d %d %d\n", vec[i].id, vec[i].V, vec[i].T);
    }
    return 0;
}