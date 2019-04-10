/*
 * 题目链接：http://acm.sdibt.edu.cn/JudgeOnline/problem.php?id=2403
 * 在没有指定数据范围的情况下，保险起见，定义成 long long型
 * 数组大小一般开为1e6或者更保险的情况是根据输入数字的大小定义数组的大小
 * 在不确定数组大小的情况下可以采用链表来实现不定长数据的存储
 */

#include<cstdio>
#include<algorithm>
typedef long long LL;
using namespace std;

LL n;

int main() {
    while(scanf("%lld",&n) != EOF && (n != 0)) {
        LL maze[n+1];
        for(int i=0;i<n;i++) {
            scanf("%lld",&maze[i]);
        }
        sort(maze,maze+n);
        LL sum = 0;
        for(LL i = 1;i < n;i++) {
            sum += (maze[i] - maze[i-1]);
        }
        sum += (maze[n-1] - maze[0]);
        printf("%lld\n",sum);
    }
}