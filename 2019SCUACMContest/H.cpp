#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n,m;
const int maxn = 10e5 + 10;
int pos[maxn];

bool isOK(int d) {
    int num = 1, last = 0;
    for(int i = 1;i < n;i++) {
        if(pos[i] - pos[last] >= d) {
            num++;
            last = i;
        }
    }
    if(num >= m) return true;
    else return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++) {
        scanf("%d",pos + i);
    }
    sort(pos, pos + n);
    int l = 0, r = pos[n-1] - pos[0];
    while(l < r) {
        int mid = (l + r) >> 1;
        if(isOK(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d",r);
    return 0;
}