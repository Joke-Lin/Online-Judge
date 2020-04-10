#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
// #define LOCAL

using namespace std;

char getMapChar(int t) {
    return t < 10 ? '0' + t : 'A' + t - 10;
}

void printRadix13(int tar) {
    printf("%c%c", getMapChar(tar/13), getMapChar(tar%13));
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int r, g, b; scanf("%d %d %d", &r, &g, &b);
    printf("#");
    printRadix13(r);
    printRadix13(g);
    printRadix13(b);
    return 0;
}