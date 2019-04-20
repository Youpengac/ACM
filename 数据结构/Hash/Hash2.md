/*
 * poj 2406
 * https://blog.csdn.net/u012860063/article/details/38532507
 * 给出一个字符串，问自身有多少中模式匹配的方法
 */

#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 1000005;

char str[maxn];
int nextt[maxn];

void getnext(int len) {
    int i = 0, j = -1;
    nextt[0] = -1;
    while (i < len) {
        if (j == -1 || str[i] == str[j]) {
            i++;
            j++;
            nextt[i] = j;
        } else {
            j = nextt[j];
        }
    }
}

int main() {
    int len, length;
    while (scanf("%s", str)) {
        len = strlen(str);
        if (len == 1 && str[0] == '.')
            return 0;
        getnext(len);
        length = len - nextt[len];
        if (len % length == 0) {
            printf("%d\n", len / length);
        } else {
            printf("1\n");
        }
    }
    return 0;
}
