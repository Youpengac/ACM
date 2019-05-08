题目链接：<http://poj.org/problem?id=1056>

思路：这种类型题目一般用字典树了，在判断时注意，第一，在添加新串时发现已有字符串是它的前缀，第二，没有发现有字符串是它的前缀，但是，存在以它为前缀的字符串（就是还有个字符串经过它，但是比它长），第二点容易忽略，做题要细心.

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200;
const int sigma_size = 2;

int ch[maxn][maxn], val[maxn];
char ss[maxn];
int sz;

void init() {
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    val[0] = 0;
}

bool insert(char *s) {
    int len = strlen(s);
    int rt = 0;
    bool flag = true;
    int idx;
    for (int i = 0; i < len; i++) {
        idx = s[i] - '0';
        if (!ch[rt][idx]) {
            ch[rt][idx] = sz;
            val[sz] = 0;
            memset(ch[sz], 0, sizeof(ch[sz]));
            sz++;
        }
        rt = ch[rt][idx];
        //判断是否存在前缀
        if (val[rt]) {
            flag = false;
            break;
        }
    }
    //判断是否存在超集
    val[rt] = 1;
    for (int i = 0; i < sigma_size; i++) {
        if (ch[rt][i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    init();
    int num = 1;
    bool ok = true;
    //用scanf读入如果没有加!=EOF,会导致Output Limit Exceeded错误
    //改正要么采用下面的方法，要么采用cin输入。
    while (scanf("%s", ss) != EOF) {
        if (strcmp(ss, "9") == 0) {
            if (ok)
                printf("Set %d is immediately decodable\n", num++);
            else
                printf("Set %d is not immediately decodable\n", num++);
            init();
            ok = true;
            continue;
        }
        if (ok)
            ok = insert(ss);
    }
    return 0;
}
```