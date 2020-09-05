#include <cstdio>
#define LOCAL

using namespace std;

const int maxn = 1e3+1;

int Ax[maxn], Ay[maxn], Bx[maxn], By[maxn];
int numA = 0, numB = 0;
int A, B, C;

bool getRes(int x, int y) {
    return A + B*x + C*y > 0;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int n, m; scanf("%d %d", &n, &m);
    int x, y; char type; 
    for(int i = 0;i < n;i++) {
        scanf("%d %d %c", &x, &y, &type);
        type == 'A' ? (Ax[numA] = x, Ay[numA++] = y) : (Bx[numB] = x, By[numB++] = y);
    }
    for(int i = 0;i < m;i++) {
        scanf("%d %d %d", &A, &B, &C);
        // 检测A B 是不是全部在两边
        bool Aside = getRes(Ax[0], Ay[0]), Bside = getRes(Bx[0], By[0]);
        if(!(Aside ^ Bside)) {
            printf("No\n");
            continue;
        }
        // 检测所有A（B） 是不是在一边
        bool flagA = true;
        for(int j = 1;j < numA;j++) {
            if(getRes(Ax[j], Ay[j]) ^ Aside) {
                flagA = false;
                break;
            }
        }
        bool flagB = true;
        for(int j = 1;j < numB;j++) {
            if(getRes(Bx[j], By[j]) ^ Bside) {
                flagB = false;
                break;
            }
        }
        if(flagA && flagB) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}