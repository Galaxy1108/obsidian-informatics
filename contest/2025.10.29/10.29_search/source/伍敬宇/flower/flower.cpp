#include <cstdio>
using namespace std;
int a[88],n,flag;
int vis[44];
char s[44][112];
void dfs(int id)
{
    if (flag) return;
    while (a[id]) id++;
    if (id>n*2)
    {
        flag = 1;
        for (int i=1;i<=n*2;i++)
            printf("%s\n",s[a[i]]);
        return ;
    }
    for (int i=n;i>=1;i--)
    {
        if (vis[i]) continue ;
        if (id+i+1>n*2) return ;
    }
    for (int i=n;i>=1;i--)
    {
        if (vis[i]) continue ;
        if (a[id+i+1]) continue ;
        vis[i] = 1;
        a[id] = a[id+i+1] = i;
        dfs(id+1);
        if (flag) return ;
        a[id] = a[id+i+1] = 0;
        vis[i] = 0;
    }
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%s",s[i]);
    dfs(1);
    return 0;
}