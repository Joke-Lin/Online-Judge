#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const long long MOD = 1e9 + 7;
map<pair<int,int>,int> results;


int get(const string &s, int l, int r)
{
    if(results.count(make_pair(l,r)) == 1) {
        return results[make_pair(l,r)];
    }

    int length = r - l + 1; //查询的字符串长度
    int begin = l - 1;

    vector<int> cur_index(length + 1, 0), last_index(9, 0);
    vector<long long> result(length + 1, 0);

    for (int i = 1; i <= length; i++)
    {
        int a = s[i + begin - 1] - 'a'; //当前字符
        cur_index[i] = last_index[a];   //当前字符出现的最后位置
        last_index[a] = i;              //更新字符最后出现的位置
    }

    result[0] = 0; //初始化
    for (int i = 1; i <= length; i++)
    {
        if(results.count(make_pair(l,l+i-1)) == 1) {
            result[i] = results[make_pair(l,l+i-1)];
            continue;
        }
        if (cur_index[i] == 0)
        { //如果当前字符未出现
            result[i] = (result[i - 1] + result[i - 1] + 1);
        }
        else
        { //当前字符出现的最后位置为p[i]
            result[i] = (result[i - 1] + result[i - 1] - result[cur_index[i] - 1]);
        }
        result[i] %= MOD;
        results.insert(make_pair(make_pair(l,l+i-1),result[i]));
    }
    return result[length];
}

int main()
{
    string s;
    int q = 0;
    cin >> s; //输入只包含a,b,c,d,e,f,g,h,i
    scanf("%d",&q);
    int l, r;
    while (q--)
    {                  //计算每一次询问
        scanf("%d%d", &l, &r);
        printf("%d\n",get(s,l,r));
    }
    return 0;
}
