#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LOCAL

using namespace std;

const int MODER = 1000000007;
const int maxn = 1e5+1;

char str[maxn] = "";
int pNums[maxn];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    memset(pNums, 0, sizeof(pNums));
    scanf("%s", str);
    int res = 0;
    int length = strlen(str);
    int pTotal = 0;
    for(int i = 0;i < length;i++) {
        str[i] == 'P' && pTotal++;
        pNums[i] = pTotal;
    }
    int tTotal = str[length-1] == 'T' ? 1 : 0;
    for(int i = length-2;i >= 1;i--) {
        str[i] == 'T' && tTotal++;
        if(str[i] == 'A') {
            res = (res + (pNums[i-1] * tTotal) % MODER) % MODER;
        }
    }
    printf("%d", res);
    return 0;
}