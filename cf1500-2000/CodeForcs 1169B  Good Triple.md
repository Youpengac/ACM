CodeForcs 1169B  Good Triple

题目链接：<http://codeforces.com/problemset/problem/1169/B>

题目描述：给你m对不超过n的数字，找出一对x，y，满足在这m对数中至少有一个数字等于x或者y。

思路：假设第一对为（a，b），若x，y存在，则其中之一一定是a，b中的一个数，那么如果存在（c，d），使得与a，b都不相同，那么x，y中的另一个数必在c，d中，所以x，y可能是（a，c），（a，d），（b，c），（b，d），如果不存在（c，d），则x，y就是（a，b），要对m对数进行扫描，则只要满足以下五中情况任意之一即可：（a，b），（a，c），（a，d），（b，c），（b，d）。时间复杂度O(5m)。

```c++
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 300005;

pair<int, int> pa[maxn];
int n, m;

bool check(int a, int b) {
    for (int i = 0; i < m; i++) {
        if (a != pa[i].first && a != pa[i].second && b != pa[i].first && b != pa[i].second) return false;
    }
    return true;
}

int main() {
    while (cin >> n >> m) {
        if (m == 1) {
            cin >> pa[0].first >> pa[0].second;
            cout << "YES" << endl;
            continue;
        }
        cin >> pa[0].first >> pa[0].second;
        int a = pa[0].first, b = pa[0].second, c, d;
        for (int i = 1; i < m; i++) {
            scanf("%d%d", &pa[i].first, &pa[i].second);
            if (a != pa[i].first && a != pa[i].second && b != pa[i].first && b != pa[i].second) {
                c = pa[i].first;
                d = pa[i].second;
            }
        }
        bool flag = check(a, b) || check(a, c) || check(a, d) || check(b, c) || check(b, d);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
```