#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 300 + 12;
int n,m,dep[MAXN],sum[MAXN],dfn[MAXN],idx,p[MAXN];
vector<int> E[MAXN];
int lb[MAXN],rb[MAXN],ans;
int cur = 0;
bool cmp(int x,int y)
{
    if (dep[x]!=dep[y]) return dep[x] < dep[y];
    return sum[x] > sum[y];
}
void dfs(int u,int f)
{
    dep[u] = dep[f] + 1;
    sum[u] = 1;
    dfn[u] = ++idx;
    for (int i=0;i<E[u].size();i++)
    {
        int v = E[u][i];
        if (v==f) continue ;
        dfs(v,u);
        sum[u] += sum[v];
    }
}
struct FenwickTree{
    int bas[MAXN];
    inline int lowbit(int x) {return x&(-x);}
    void addp(int id)
    {
        for (;id<=n;id+=lowbit(id))
            bas[id] ++;
    }
    void addn(int id)
    {
        for (;id<=n;id+=lowbit(id))
            bas[id] --;
    }
    int query(int id)
    {
        int res = 0;
        for (;id;id-=lowbit(id))
            res += bas[id];
        return (res>0);
    }
}tr;
void work(int d,int res)
{
    if (res>ans) ans = res;
    if (lb[d]==0) return ;
    if (cur>6e6) return;
    for (int t=lb[d];t<=rb[d];t++)
    {
        int i = p[t];
        if (tr.query(dfn[i])) continue ;
        tr.addp(dfn[i]);
        tr.addn(dfn[i]+sum[i]);
        cur ++;
        work(d+1,res+sum[i]);
        tr.addn(dfn[i]);
        tr.addp(dfn[i]+sum[i]);
    }
}
int main()
{
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++) p[i] = i;
    sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        rb[dep[p[i]]] = i;
        if (lb[dep[p[i]]]==0)
            lb[dep[p[i]]] = i;
    }
    work(2,0);
    printf("%d",n-ans);
    return 0;
}