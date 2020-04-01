#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define LOCAL

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    char kinds[] = {'W', 'T', 'L'};
    float res = 1;
    for(int i = 0;i < 3;i++) {
        int index = 0;
        float big_val, temp_val;
        scanf("%f", &big_val);
        for(int j = 1;j <= 2;j++) {
            scanf("%f", &temp_val);
            if(temp_val > big_val) {
                index = j;
                big_val = temp_val;
            }
        }
        printf("%c ", kinds[index]);
        res *= big_val;
    }
    printf("%.2f", (res*0.65-1)*2);
    return 0;
}