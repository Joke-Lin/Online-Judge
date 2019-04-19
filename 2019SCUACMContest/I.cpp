#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool ispreix(string &a, string &b) {
    if(b.find(a) == 0) {
        return true;
    }
    else return false;
}


bool isOK(vector<string> &list) {
    sort(list.begin(),list.end());
    for(int i = 0;i < list.size()-1;i++) {
        if(ispreix(list[i],list[i+1])) return false;
    }
    return true;
}

int main() 
{
    int t; scanf("%d",&t);
    while(t--) {
        int n; scanf("%d",&n);
        vector<string> list;
        string temp;
        for(int i = 0;i < n;i++) {
            cin >> temp;
            list.push_back(temp);
        }
        if(isOK(list)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}