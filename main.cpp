//http://acm.sdibt.edu.cn/JudgeOnline/problem.php?id=2401

#include<cstdio>
#include<cstring>  //memset函数的头文件
using namespace std;

const int maxn = 110;

bool vis[maxn][maxn];
char maze[maxn][maxn];
int n,ind;

int go[8][2] = {-1,0,1,0,0,-1,0,1,-1,1,1,1,1,-1,-1,-1};

bool dfs(int x,int y) {
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    if(vis[x][y] || maze[x][y] == '0')
        return false;
    vis[x][y] = true;
    int temp = (ind == 1 ? 4 : 8);
    for(int i = 0;i < temp;i++)
        dfs(x+go[i][0],y+go[i][1]);
    return true;
}

int main() {
    int flag = 0;
    int cnt1,cnt2;
    while((scanf("%d",&n) != EOF) && (n != 0)) {
        cnt1 = cnt2 = 0;
        getchar();
        for(int i = 0;i < n;i++) {
            scanf("%s",maze[i]);
        }
        ind = 1;
        memset(vis,false,sizeof(vis));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(dfs(i,j))
                    cnt1++;
            }
        }
        memset(vis,false,sizeof(vis));
        ind = 2;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(dfs(i,j))
                    cnt2++;
            }
        }
        printf("Case %d: %d %d\n\n",++flag,cnt1,cnt2);
    }
    return 0;
}