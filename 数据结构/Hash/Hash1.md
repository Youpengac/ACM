//https://blog.csdn.net/hjd_love_zzt/article/details/45111985

/*
 * (KMP 1.2)hdu 1686 Oulipo(计算模式串在文本串中出现的次数)
 */

#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1000005;

char pattern[maxn]; //模式串
char text[maxn]; //匹配串
int nextt[maxn]; //定义成next可能会和某些类冲突

//O(n)的时间求next数组
void getnext() {
    int patternlen = (int)strlen(pattern);  //计算模式串的长度
    nextt[0] = nextt[1] = 0;
    int j;
    for(int i = 1;i < patternlen;i++) {
        j = nextt[i];
        while(j && pattern[i] != pattern[j]) {
            j = nextt[j];
        }
        nextt[i+1] = (pattern[i] == pattern[j] ? j+1 : 0);
    }
}

/*
 * O(n)的时间进行匹配
 * 返回第一次匹配的位置
 */
int kmp() {
    int ans = 0;

    int patternlen = (int)strlen(pattern);
    int textlen = (int)strlen(text);

    int j = 0; //初始化在模式串的第一个位置
    for(int i = 0;i < textlen;i++) {
        while(j && pattern[j] != text[i]) { //顺着失配走,直到可以匹配,最坏的情况时j==0;
            j = nextt[j];
        }
        if(pattern[j] == text[i]) {
            j++;
        }
        if(j == patternlen) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        /*可以读入类似这种格式的字符串,换行符不会被读入:
         * string1
         * string2
         */
        scanf("%s%s",pattern,text);
        getnext();
        printf("%d\n",kmp());
    }
    return 0;
}
