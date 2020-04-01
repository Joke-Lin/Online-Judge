#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int n, b; scanf("%d %d", &n, &b);
    vector<int> res;
    do {
        res.push_back(n % b);
        n = n/b;
    } while (n != 0);
    bool flag = true;
    int length = res.size();
    for(int i = 0;i < length/2;i++) {
        if(res[i] != res[length - i - 1]) {
            flag = false;
            break;
        }
    }
    printf("%s\n", flag == true ? "Yes" : "No");
    for(int i = length-1;i >= 0;i--) {
        printf("%d", res[i]);
        if(i != 0) {
            printf(" ");
        }
    }
    return 0;
}