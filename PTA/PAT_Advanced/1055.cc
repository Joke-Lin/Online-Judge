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

using namespace std;

struct Man {
    char name[10];
    int wealth;
    int age;
    bool operator < (Man &another) const {
        if(another.wealth != wealth) {
            return wealth > another.wealth;
        }
        else if(age != another.age) {
            return age < another.age;
        }
        return strcmp(name, another.name) < 0;
    }
};

vector<Man> mans;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n, m; scanf("%d %d", &n, &m);
    char name[10];
    int age, wealth;
    Man mid;
    for(int i = 0;i < n;i++) {
        scanf("%s %d %d", name, &age, &wealth);
        mid.wealth = wealth;
        mid.age = age;
        strcpy(mid.name, name);
        mans.push_back(mid);
    }
    sort(mans.begin(), mans.end());
    for(int i = 1;i <= m;i++) {
        int num, beg, end;
        scanf("%d %d %d", &num, &beg, &end);
        printf("Case #%d:\n", i);
        int temp = num;
        for(int j = 0;j < n;j++) {
            if(mans[j].age >= beg && mans[j].age <= end) {
                printf("%s %d %d\n",mans[j].name, mans[j].age, mans[j].wealth);
                num--;
                if(num == 0) {
                    break;
                }
            }
        }
        if(num == temp) {
            printf("None\n");
        }
    }
    return 0;
}