/*
 * poj 3349
 * 哈希表的运用
 * https://blog.csdn.net/u013555159/article/details/52052944
 */

#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1200010;
const int H = 1200007;

int cur;

struct node {
    int num[6];
    int next;
}hash[N];

//定义一个hash表
int hashtable[H];

//初始化哈希表
int inithash() {
    cur = 0;
    for (int i = 0;i < H;i++) {
        hashtable[i] = -1;
    }
}

//获取哈希值，对哈希数组求和然后模除一个比较大的数
int gethash(int *num) {
    int sum = 0;
    for (int i = 0;i < 6;i++) {
        sum += num[i];
    }
    return sum % H;
}

bool cmp(int *num1,int *num2) {
    for (int i = 0;i < 6;i++) {
        if(num1[i] != num2[i]) {
            return false;
        }
    }
    return true;
}

void inserthash(int *num,int h) {
    cur++;
    for(int i = 0;i < 6;i++) {
        hash[cur].num[i] = num[i];
    }
    hash[cur].next = hashtable[h];
    hashtable[h] = cur;
}

bool hashsearch(int *num) {
    int h = gethash(num);
    int next = hashtable[h];
    while (next != -1) {
        if (cmp(num,hash[next].num)) {
            return true;
        } else {
            next = hash[next].next;
        }
    }
    inserthash(num,h);
    return false;
}

int main() {
    int t;
    scanf("%d",&t);
    inithash();
    bool flag = false;
    while (t--) {
        int num[2][12];
        for(int i = 0;i < 6;i++) {
            scanf("%d",&num[0][i]);
            num[0][i+6] = num[0][i];
        }
        if(flag) {
            continue;
        }
        for(int i = 0;i < 6;i++) {
            num[1][i+6] = num[1][i] = num[0][5-i];
        }

        for(int i = 0;i < 6;i++) {
            if(hashsearch(num[0]+i) || hashsearch(num[1] + i)) {
                flag = true;
                break;
            }
        }
    }
    if (flag) {
        printf("Twin snowflakes found.\n");
    } else {
        printf("No two snowflakes are alike.\n");
    }
    return 0;
}

