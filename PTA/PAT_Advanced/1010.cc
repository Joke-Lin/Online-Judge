#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

typedef long long ll;

int getNum(char tar) {
    if(tar >= '0' && tar <= '9') {
        return tar - '0';
    }
    else {
        return tar - 'a' + 10;
    }
}

int getMinRadix(string &tar) {
    char c = '0';
    for(int i = 0;i < tar.length();i++) {
        if(tar[i] > c) {
            c = tar[i];
        }
    }
    return  max(getNum(c) + 1, 2);
}

ll getRes(string &tar, int radix) {
    ll res = 0;
    int len = tar.length();
    for(int i = 0;i < tar.length();i++) {
        res = res*radix + getNum(tar[i]);
        if(res < 0) {
            return -1;
        }
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    string A, B;
    int tag, radix;
    cin >> A >> B >> tag >> radix;
    if(tag == 2) {
        swap(A, B);
    }
    // B 是 要计算的
    ll tar = getRes(A, radix);
    //  二分
    ll left = getMinRadix(B);
    ll right = max(left, tar);
    while (left <= right) {
        ll mid = (left + right) >> 1;
        ll temp = getRes(B, mid);
        if(temp == tar) {
            printf("%lld", mid);
            return 0;
        }
        if(temp < 0 || temp > tar) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    printf("Impossible");
    return 0;
}