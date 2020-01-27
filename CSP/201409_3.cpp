#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#define LOCAL

using namespace std;

int TEMP = 'A'-'a';

void change(char str[])
{
    for(int i = 0;i < strlen(str);i++)
    {
        if('A' <= str[i] && str[i] <= 'Z') str[i] -= TEMP;
    }
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    char str1[110];
    char str2[110];
    char temp[110];
    cin >> str1;
    int cmd; cin >> cmd;
    if(cmd == 0) change(str1);
    int n; cin >> n;
    while(n--)
    {
        cin >> str2;
        strcpy(temp,str2);
        if(cmd == 0) change(str2);
        if(strstr(str2,str1) != NULL) cout << temp << endl;
    }
    return 0;
}