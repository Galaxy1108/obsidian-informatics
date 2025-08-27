#include <cstdio>
#include <vector>
using namespace std;
int n,x;
int dis[22][22];
vector<int> E[22];
int ans[22];
inline int count(int x)
{
    int cnt = 0;
    for (int i=0;i<x;i++)
        if (x&(1<<i))
            cnt++;
    return cnt;
}
void dfs(int u,int f,int st,int d)
{
    dis[st][u] = d;
    for (int i=0;i<E[u].size();i++)
    {
        int v = E[u][i];
        if (v==f) continue ;
        dfs(v,u,st,d+1);
    }
}
int main()
{
    freopen("youup.in","r",stdin);
    freopen("youup.out","w",stdout);
    int tp;
    scanf("%d",&tp);
    scanf("%d%d",&n,&x);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        dfs(i,0,i,0);
    for (int s=1;s<(1<<n);s++)
    {
        int flag = 1;
        for (int i=1;i<=n;i++)
            if (s&(1<<(i-1)))
                for (int j=1;j<=n;j++)
                    if (s&(1<<(j-1)))
                        if (dis[i][j]>x)
                            flag = 0;
        ans[count(s)] += flag;
    }
    for (int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}