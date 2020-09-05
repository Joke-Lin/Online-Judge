#include <cstdio>
#define LOCAL

using namespace std;

const int maxn = 1e3+1;

int pointsX[maxn], pointsY[maxn];
int res[5] = {0, 0, 0, 0, 0};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d %d", pointsX+i, pointsY+i);
    }
    int direX[8] = {0, 0, 1, -1, -1, -1, 1, 1}, direY[8] = {1, -1, 0, 0, -1, 1, 1, -1};
    for(int i = 0;i < n;i++) {
        int score1 = 0, score2 = 0;
        for(int j = 0;j < n;j++) {
            if(i == j) continue;
            for(int k = 0;k < 4;k++) {
                if(pointsX[j] == pointsX[i] + direX[k] && pointsY[j] == pointsY[i] + direY[k]) {
                    score1++;
                    break;
                }
            }
            for(int k = 4;k < 8;k++) {
                if(pointsX[j] == pointsX[i] + direX[k] && pointsY[j] == pointsY[i] + direY[k]) {
                    score2++;
                    break;
                }
            }
        }
        if(score1 == 4) {
            res[score2]++;
        }
    }
    for(int i = 0;i < 5;i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}