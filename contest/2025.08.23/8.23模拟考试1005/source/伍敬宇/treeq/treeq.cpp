#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int MAXN = 5000 + 12;
int n,fa[MAXN],w[MAXN];
vector<int> E[MAXN];
int sum[MAXN];
long long c[MAXN][MAXN],a[MAXN][MAXN];
long long mx[MAXN];
void dfs1(int u)
{
    sum[u] = 1;
    for (int i=0;i<E[u].size();i++)
    {
        int v = E[u][i];
        dfs1(v);
        sum[u] += sum[v];
    }
}
void dfs2(int u,int top)
{
    c[u][top] = n - sum[top];
    for (int i=0;i<E[u].size();i++)
    {
        int v = E[u][i];
        dfs2(v,top);
    }
}
int main()
{
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
    scanf("%d",&n);
    for (int i=2;i<=n;i++) scanf("%d%d",fa+i,w+i),E[fa[i]].push_back(i);
    dfs1(1);
    for (int i=2;i<=n;i++)
    {
        dfs2(i,i);
        for (int j=1;j<=n;j++)
            if (c[j][i]==0)
                c[j][i] = sum[i];
    }
    for (int i=2;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j] = c[j][i]*w[i];
    for (int i=1;i<=n;i++)
        for (int j=2;j<=n;j++)
            mx[i] = max(mx[i],a[j][i]);
    int ans = 0;
    for (int i=2;i<=n;i++)
    {
        int cur = 0;
        for (int j=1;j<=n;j++)
            if (a[i][j]==mx[j])
                cur++;
        ans ^= cur;
    }
    printf("%d",ans);
    return 0;
}