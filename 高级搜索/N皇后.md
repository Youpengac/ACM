题目链接：<http://acm.hdu.edu.cn/showproblem.php?pid=2553>

关于八皇后问题的参考链接：

* <https://www.jianshu.com/p/65c8c60b83b8>
* <https://blog.csdn.net/codes_first/article/details/78474226>
* <https://www.cnblogs.com/bigmoyan/p/4521683.html>
* <https://blog.csdn.net/Biubiuxin/article/details/82151485>



AC代码：

```c++
#include <cstdio>

using namespace std;

const int maxn = 110;

int vis[3][maxn];
int sum;
int dp[11];

void DFS(int row, int n) {
    if (row == n + 1)
        sum++;
    else {
        for (int i = 1; i <= n; i++) {
            if (!vis[0][i] && !vis[1][row + i] && !vis[2][row - i + n]) {
                vis[0][i] = vis[1][row + i] = vis[2][row - i + n] = true;
                DFS(row + 1, n);
                vis[0][i] = vis[1][row + i] = vis[2][row - i + n] = false;
            }
        }
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        sum = 0;
        DFS(1, i);
        dp[i] = sum;
    }
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        printf("%d\n", dp[n]);
    }
    return 0;
}
```

