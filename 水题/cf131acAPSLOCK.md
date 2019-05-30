题目链接：http://codeforces.com/problemset/problem/131/A

水题，但容易出错

对以下几种情况进行处理：
多于一个字符的情况：
1.全是大写的情况  改成  全是小写
2.第一个字母是小写，剩下的全是大写  改成  第一个大写，剩下的全是小写
一个字符的情况：
1.小写的变成大写
2.大写的变成小写
其他情况原样输出

AC代码：
```
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string str;
int len;

void result(bool ok) {
    int i = 0;
    if(ok) {
        if(str[0] >= 'a' && str[0] <= 'z') {
            printf("%c",str[0] - 32);
        } else {
            printf("%c",str[0]);
        }
        i=1;
    }
    for(i;i < len;i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            printf("%c",str[i] + 32);
        } else {
            printf("%c",str[i]);
        }
    }
}

int main() {
    while(cin>>str) {
        len = str.length();
        if(len == 1) {
            if(str[0] >= 'A' && str[0] <= 'Z')
                printf("%c",str[0] + 32);
            else
                printf("%c",str[0]-32);
            cout<<endl;
            continue;
        }
        bool flag = false;
        if(str[0] >= 'A' && str[0] <= 'Z') {
            for(int i = 1;i < len;i++) {
                if(str[0] >= 'A' && str[i] <= 'Z')
                    continue;
                else {
                    flag = true;
                    break;
                }
            }
            if(flag)
                cout<<str;
            else
                result(false);
        }
        else {
            for(int i = 1;i < len;i++) {
                if(str[0] >= 'A' && str[i] <= 'Z')
                    continue;
                else {
                    flag = true;
                    break;
                }
            }
            if(flag)
                cout<<str;
            else
                result(true);
        }
        cout<<endl;
    }
    return 0;
}
```
