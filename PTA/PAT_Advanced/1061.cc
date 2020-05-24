#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#include <stack>
#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

char week [][4] = {
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN",
};

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    char strs[4][100];
    scanf("%s %s %s %s", &strs[0], &strs[1], &strs[2], &strs[3]);
    char a = 0, b;
    for(int i = 0;i < strlen(strs[0]) && i < strlen(strs[1]);i++) {
        if(a == 0) {
            if(strs[0][i] == strs[1][i] && strs[0][i] >= 'A' && strs[0][i] <= 'G') {
                a = strs[0][i];
            }
        }
        else{
            if(strs[0][i] == strs[1][i] && ((strs[0][i] >= 'A' && strs[0][i] <= 'N') || strs[0][i] >= '0' && strs[0][i] <= '9') ) {
                b = strs[0][i];
                break;
            }
        }
    }
    int m = 0;
    for(int i = 0;i < strlen(strs[2]) && i < strlen(strs[3]);i++) {
        if(strs[2][i] == strs[3][i] && ((strs[2][i] >= 'a' && strs[2][i] <= 'z') || (strs[2][i] >= 'A' && strs[2][i] <= 'Z'))) {
            m = i;
            break;
        }
    }
    int h = b >= 'A' ? 10+b-'A' : b-'0';
    printf("%s %02d:%02d", week[a-'A'], h, m);
    return 0;
}