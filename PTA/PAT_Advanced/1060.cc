#include <string>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <set>
#include <stack>
//#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

string format(int n, string a) {
    int pos = a.find('.');  // pos为点的位置
    // 保证字符串有小数部分
    if(pos == string::npos) {
        a += ".0";
        pos = a.length() - 2;
    }
    int length = a.length();
    // 去除前导0
    int temp_pos = -1;
    for(int i = 0;i < length;i++) {
        if(a[i] != '0') {
            break;
        }
        temp_pos = i;
    }
    // temp_pos 记录前导0的位置 注意对00.1这样的判断
    if(temp_pos != -1) {
        if(a[temp_pos+1] == '.') {
            temp_pos--;
        }
        // 删除前导0 并更新长度和点的位置
        a.erase(0, temp_pos+1);
        pos -= temp_pos+1;
        length -= temp_pos+1;
    }
    string res = "";
    int cnt = 0, non_zero = -1;
    // 取n个有效数字 并且记录第一个非0值的位置
    for(int i = 0; i < length;i++) {
        if(cnt == n) {
            break;
        }
        if(non_zero < 0 && a[i] != '.' && a[i] != '0') {
            non_zero = i;
        }
        if(a[i] != '.' && non_zero != -1) {
            cnt++;
            res.push_back(a[i]);
        }
    }
    int exp = 0;    // if non_zero = 0说明是000.000这样的 那么exp = 0
    if(non_zero != -1) {
        // 指数的判断 需要分大于小于1
        if(non_zero > pos) {
            exp = pos - non_zero + 1;
        }
        else {
            exp = pos;
        }
    }
    // 有效数不足的要补零
    res.insert(res.end(), n-cnt, '0');
    res = "0." + res + "*10^" + std::to_string(exp);
    return res;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
#endif
    int n;
    string A, B;
    cin >> n >> A >> B;
    A = format(n, A);
    B = format(n, B);
    if(A == B) {
        cout << "YES " << A;
    }
    else {
        cout << "NO " << A << " " << B;
    }
    return 0;
}