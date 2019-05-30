题目链接：http://codeforces.com/problemset/problem/580/A

AC代码：
```
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100005;

int arr[maxn];
int n;

int main() {
    while(scanf("%d",&n) != EOF) {
        int maxans = 0,temp = 0;
        arr[0] = -1;
        for(int i = 1;i <= n;i++) {
            scanf("%d",&arr[i]);
            if(arr[i] >= arr[i-1]) {
                temp++;
                if(temp > maxans)
                    maxans = temp;
            } else {
                temp = 1;
            }
        }
        printf("%d\n",maxans);
    }
    return 0;
}
```
