#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#define LOCAL

using namespace std;
char Map[100][100];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(Map, ' ', sizeof(Map));
    char str[100]; scanf("%s", str);
    int n1, n2, n = strlen(str);
    int delta = 0x3f3f3f3f;
    // 遍历找最小
    for(int i = 2;i <= (n-1)/2;i++) {
        int temp = abs(n + 2 - 2*i - i);
        if(temp >= delta || n+2-2*i < i) {
            break;
        }
        delta = temp;
        n1 = i;
        n2 = n + 2 - 2*n1;
    }
    // 也可以直接除三。。
    // n1 = (n+2)/3;
    // n2 = n+2 - 2*n1;
    for(int i = 0;i < n1;i++) {
        Map[i][0] = str[i];
    }
    for(int i = 0;i < n2;i++) {
        Map[n1-1][i] = str[n1-1+i];
    }
    for(int i = n1-1;i >= 0;i--) {
        Map[i][n2-1] = str[n-i-1];
    }
    for(int i = 0;i < n1;i++) {
        for(int j = 0;j < n2;j++) {
            printf("%c", Map[i][j]);
        }
        printf("\n");
    }
    return 0;
}