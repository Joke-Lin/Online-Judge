#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define LOCAL

using namespace std;

const int maxn = 101;
const char English[][10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    char str[maxn] = "";
    scanf("%s", str);
    int num = 0;
    for(int i = 0;i < strlen(str);i++) {
        num += str[i] - '0';
    }
    sprintf(str, "%d", num);
    int length = strlen(str);
    for(int i = 0;i < length;i++) {
        printf("%s", English[str[i]-'0']);
        if(i != length - 1) {
            printf(" ");
        }
    }
    return 0;
}