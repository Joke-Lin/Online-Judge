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
#include <stack>
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;
#define LOWBIT(x) ((x)&(-(x)))

using namespace std;

int main() {
    int AB[2][3];
    scanf("%d.%d.%d", AB[0]+0,AB[0]+1,AB[0]+2);
    scanf("%d.%d.%d", AB[1]+0,AB[1]+1,AB[1]+2);
    int a, b, c, mid = 0;
    mid = AB[0][2] + AB[1][2] + mid;
    c = mid < 29 ? mid : mid-29;
    mid = mid < 29 ? 0 : 1;
    mid = AB[0][1] + AB[1][1] + mid;
    b = mid < 17 ? mid : mid-17;
    mid = mid < 17 ? 0: 1;
    mid = AB[0][0] + AB[1][0] + mid;
    a = mid;
    printf("%d.%d.%d", a, b, c);
    return 0;
}