题目链接：<http://poj.org/problem?id=3630>

问题描述：给你n个电话号码（都是字符串形式），目前有 t 组数据， n 个电话号码，如果拨打号码的时候 先拨通了某个号码，那么这一串号码就无法全部拨通，（eg：911 和 9112016652 相比 后者就无法被拨通，因为 911 会先被拨通。）

如果都可拨通 输出 YES ，不然输出 NO 

这道题意思很明确，给你 n 个字符串，每个字符串都不能是另外一个的前缀，这里我们只需要在每个字符串结尾位置对其做一个标记，之后 对于每个新的字符串，我们遍历 从0 --- n-2位，如果发现阶数标记，那么就不能全部拨通，否则就可以。

AC代码：

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100100;

int test,n;
char tree[maxn][15];
int ch[maxn][15];
int flag[maxn];
int cnt,tot;

void insert(char *str) {
    int rt = 0;
    int len = strlen(str);
    int idx;
    for(int i = 0;i < len;i++) {
        idx = str[i] - '0' ;
        if(!ch[rt][idx]) {
            ch[rt][idx] = ++tot;
        }
        rt = ch[rt][idx];
    }
    flag[rt] = true;
}

bool query(char *str) {
    int rt = 0;
    int len = strlen(str);
    int idx;
    //对于每个待查询的字符串，查询其n-2位，如果被标记，那么则拨不通，否则可以拨通。
    for(int i = 0;i < len - 1;i++) {
        idx = str[i] - '0';
        rt = ch[rt][idx];
        if(flag[rt])
            return false;
    }
    return true;
}

int main() {
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        memset(flag,0,sizeof(flag));
        memset(ch,0,sizeof(ch));
        tot = 0;
        for(int i = 0;i < n;i++) {
            scanf("%s",tree[i]);
            insert(tree[i]);
        }
        for(int i = 0;i < n;i++) {
            cnt = 0;
            if(!query(tree[i])) {
                cnt = 1;
                break;
            }
        }
        if(cnt) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
```

