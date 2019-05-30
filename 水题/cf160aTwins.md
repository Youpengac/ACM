题目链接：http://codeforces.com/problemset/problem/160/A

注意排序是从大到小排，不要上来就sort导致从小到大排，细节水题。

AC代码：
```
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[101];
int n;

bool cmp(int a,int b) {
    return a > b;
}
int main() {
    while(scanf("%d",&n) != EOF && (n>=1 && n <= 100)) {
        int sum = 0;
        for(int i = 0;i < n;i++) {
            scanf("%d",&arr[i]);
            sum += arr[i];
        }
        int temp = 0;
        int flag = 0;
        sort(arr,arr+n,cmp);
        for(int i = 0;i < n;i++) {
            temp += arr[i];
            sum -= arr[i];
            flag++;
            if(temp > sum)
                break;
        }
        printf("%d\n",flag);
    }
    return 0;
}
```
