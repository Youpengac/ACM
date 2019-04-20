/*
 * poj 2752
 * https://www.cnblogs.com/dongsheng/archive/2012/08/13/2636261.html
 * https://blog.csdn.net/loi_dqs/article/details/50728033
 * 给定一个字符串，计算有多少个子串满足前后缀相同
 * puts与printf的区别:
 * puts在输出字符时会自动加上换行，而printf不会。
 * puts（参数），printf(格式，参数)
 *
 * runtime error：可能数组开小了
 */
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 10000010;

char str[maxn];
int nextt[maxn];

stack <int> g;

void getnext(char str[]) {
    int len = (int)strlen(str);
    nextt[0] = nextt[1] = 0;
    for(int i = 1;i < len;i++) {
        int j = nextt[i];
        while (j && str[i] != str[j]) {
            j = nextt[j];
        }
        nextt[i + 1] = (str[i] == str[j] ? j+1 : 0);
    }
}

int main() {
    while(scanf("%s",str) != EOF) {
        getnext(str);
        int j = (int)strlen(str);
        while (j) {
            g.push(j);
            j = nextt[j];
        }
        while(g.size()) {
            printf("%d ",g.top());
            g.pop();
        }
        puts("");
    }
    return 0;
}
