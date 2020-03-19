#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int a, b; scanf("%d %d", &a, &b);
    int c = a+b;
    char num_str[30] = "";
    sprintf(num_str, "%d", c);
    int len = strlen(num_str);
    char deal_str[30] = "";
    int j = 0;
    for(int i = len-1;i >= 0;i--) {
        deal_str[j++] = num_str[i];
        if(i != 0 && (len - i) % 3 == 0 && ((i == 1 && num_str[0] != '-') || i != 1)) {
            deal_str[j++] = ',';
        }
    }
    for(int i = j-1;i >= 0;i--) {
        printf("%c", deal_str[i]);
    }
    return 0;
}