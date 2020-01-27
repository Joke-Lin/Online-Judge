#include <iostream>
#include <vector>
#define LOCAL

using namespace std;

int find(const vector<int>& students,int targ)
{
    for(int i = 0;i < students.size();i++)
    {
        if(targ == students[i]) return i;
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    vector<int> students;
    int n; cin >> n;
    int cmd; cin >> cmd;
    for(int i = 1;i <= n;i++) students.push_back(i);
    while(cmd--)
    {
        int number,move;
        cin >> number >> move;
        int pos = find(students,number);
        students.insert(students.begin()+(move >= 0 ? pos+move+1 : pos+move),number);
        students.erase(students.begin()+(move >= 0 ? pos : pos+1));
    }
    for(int i = 0;i < students.size();i++)
    {
        cout << students[i] << " ";
    }
    return 0;
}
