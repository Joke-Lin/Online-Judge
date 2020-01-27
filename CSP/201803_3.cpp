#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#define LOCAL

using namespace std;

vector< vector<string> > r; //规则
vector< vector<string> > p; //匹配串

//将规则和名字包装成列表
vector<string> transform(string url, string name = "")
{
    //去除斜杠 生成字符串流
    if(url[url.length()-1] == '/')
    {
        url += '$';
    }
    for (int i = 0; i < url.length(); i++)
    {
        if (url[i] == '/')
        {
            url[i] = ' ';
        }
    }
    vector<string> res;
    string str;
    stringstream ss(url);
    while (ss >> str)
    {
        res.push_back(str);
    }
    if(res[res.size()-1] == "$")
    {
        res[res.size()-1] = "/";
    }
    if (!name.empty())
        res.push_back(name);
    return res;
}

//判断是不是数字
bool isINT(const string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!(str[i]>='0' && str[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

//判断 p是不是匹配规则 r
bool isMatch(const vector<string> &r, const vector<string> &p)
{
    int index = 0;
    int size_r = r.size() - 1; //减去最后一个名字
    int size_p = p.size();
    while (index < size_p && index < size_r)
    {
        if (r[index] == "<int>")
        {
            if (!isINT(p[index]))
                return false;
            else
                index++;
        }
        else if (r[index] == "<str>")
        {
            index++;
        }
        else if (r[index] == "<path>")
        {
            return true;
        }
        else
        {
            if (r[index] == p[index])
                index++;
            else
                return false;
        }
    }
    if(index == size_p && index < size_r) return false;
    else if(index == size_r && index < size_p) return false;
    return true;
}

//打印参数 包含末尾换行
void show(const vector<string> &r, const vector<string> &p)
{
    int index = 0;
    int size_r = r.size() - 1; //减去最后一个名字
    int size_p = p.size();
    cout << r[size_r] << " ";
    while (index < size_p && index < size_r)
    {
        if (r[index] == "<int>")
        {
            int temp;
            stringstream ss(p[index]);
            ss >> temp;
            cout << temp << " "; 
        }
        else if (r[index] == "<str>")
        {
            cout << p[index] << " ";
        }
        else if (r[index] == "<path>")
        {
            for(int i = index;i < size_p;i++)
            {
                if(p[i]!="/")   cout << p[i];
                if(i != size_p-1) cout << "/";
            }
            break;
        }
        index++;
    }
    cout << endl;
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    string strUrlRule, strUrlName; //str1:url
    for (int i = 0; i < n; i++)
    {
        cin >> strUrlRule >> strUrlName;
        r.push_back(transform(strUrlRule, strUrlName));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> strUrlRule;
        p.push_back(transform(strUrlRule));
    }
    for (int i = 0; i < m; i++) //外循环为匹配串
    {
        int flag = false;           //是否存在匹配成功标志
        for (int j = 0; j < n; j++) //循环匹配 URL规则
        {
            if (isMatch(r[j], p[i]))
            {
                flag = true;
                show(r[j],p[i]);
                break;
            }
        }
        if (flag == false)
            cout << 404 << endl;
    }
    return 0;
}