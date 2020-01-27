#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdio>
// #define LOCAL

using namespace std;

void solution(char str[])
{
    int res = 0,len = strlen(str);
    int index = 1;
    for(int i = 0;i < len;i++)
    {
        if(str[i] == '-') continue;
        if(i == len-1){
            if(res == 10){
                if(str[i] == 'X') printf("Right\n");
                else{
                    str[i] = 'X';
                    printf("%s\n",str);
                }
                return;
            }
            if(res == str[i]-'0') printf("Right\n");
            else{
                str[i] = res+'0';
                printf("%s\n",str);
            }
        }
        res = res + (str[i]-'0')*(index++);
        res %= 11;
    }
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    char str[20];
    scanf("%s",str);
    solution(str);
    return 0;
}