题目链接：<http://acm.hdu.edu.cn/showproblem.php?pid=1015>

题目描述：给出一个目标值target，然后给出一个字符串，在字符串中A=1，B=2,...,Z=25，问能否满足运算：$$ v - w^2 + x^3 - y^4 + z^5 = target $$，若满足，则输出字典序最大的字符串，否则输出no solution；

网上说也可以用多重循环暴力来做，但作为对DFS的一个学习，还是用DFS+回溯的思想来做吧。

AC代码：

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 25;

int n, a[maxn], b[maxn], len;
char ch[maxn], temp;
bool flag, vis[maxn];

bool cmp(int p, int q) {
    return p > q;
}

void check() {
    if (n == b[0] - b[1] * b[1] + b[2] * b[2] * b[2] - b[3] * b[3] * b[3] * b[3] + b[4] * b[4] * b[4] * b[4] * b[4])
        flag = true;
    return;
}

void DFS(int num) {
    if (flag)
        return;
    if (num == 5) {
        check();
        return;
    }
    for (int i = 0; i < len; i++) {
        if (!vis[i] && !flag) {
            vis[i] = true;
            b[num] = a[i];
            DFS(num + 1);
            vis[i] = false;
        }
    }
}

int main() {
    while (cin >> n >> ch && n && ch != "END") {
        len = strlen(ch);
        for (int i = 0; i < len; i++) {
            a[i] = ch[i] - 'A' + 1;
        }
        flag = false;
        sort(a, a + len, cmp);
        DFS(0);
        if (flag) {
            for (int i = 0; i < 5; i++) {
                temp = b[i] - 1 + 'A';
                printf("%c", temp);
            }
            printf("\n");
        } else {
            printf("no solution\n");
        }
    }
    return 0;
}
```

