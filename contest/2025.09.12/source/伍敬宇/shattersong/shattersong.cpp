#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m;
int z[23];
int a[23];
bool av[1<<(15)+12];
struct Edge{
    int u,v,w;
    bool operator<(const Edge&rhs) const{
        return w < rhs.w;
    }
}E[98];
int res[23],pre[23],d[23][23],sz[23],sta[23];
int find(int x) {return (x==pre[x])?x:pre[x]=find(pre[x]);}
bool check(int k)
{
    for (int i=1;i<=k;i++) sz[i] = res[i] = 0;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=k;j++)  
            d[i][j] = 1.5e9;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>1)
            sz[a[i]] ++;
        pre[i] = i;
    }
    for (int i=1;i<=m;i++)
    {
        int u = E[i].u,v = E[i].v,w = E[i].w;
        if (a[u]==1||a[v]==1) continue ;
        if (a[u]!=a[v]) d[a[u]][a[v]] = min(d[a[u]][a[v]],w);
        else if (find(u)!=find(v))
        {
            pre[find(u)] = find(v);
            res[a[i]] = max(res[a[i]],w);
        }
    }
    for (int i=2;i<=k;i++)
        for (int j=i+1;j<=k;j++)
            if (d[i][j]<=min(res[i]+z[sz[i]],res[j]+z[sz[j]]))
                return 0;
    return 1;
}
void dfs(int id,int k)
{
    if (id>n)
    {
        if (k<=2||check(k)==0) return ;
        int s = 0;
        for (int i=1;i<=n;i++)
            if (a[i]>1)
                s |= (1<<(i-1));
        av[s] = 1;
        return ;
    }
    for (int i=1;i<=k;i++)
    {
        a[id] = i;
        dfs(id+1,k);
    }
    a[id] = k+1;
    dfs(id+1,k+1);
}
bool realCheck(int k)
{
    for (int i=1;i<=k;i++) sta[i] = 0;
    for (int i=1;i<=n;i++)
        sta[a[i]] |= (1<<(i-1));
    for (int i=2;i<=k;i++)
        if (av[sta[i]])
            return 0;
    return 1;
}
void getAns(int id,int k)
{
    if (id>n)
    {
        if (k==1||check(k)==0) return ;
        //printf("%d %d\n",id,k);
        if (realCheck(k)==0) return ;
        printf("%d\n",k-1);
        for (int i=2;i<=k;i++)
        {
            int cnt = 0;
            for (int j=1;j<=n;j++)
                if (a[j]==i) cnt++;
            printf("%d ",cnt);
            for (int j=1;j<=n;j++)
                if (a[j]==i)
                    printf("%d ",j);
            printf("\n");
        }
        exit(0);
        return ;
    }
    for (int i=2;i<=k;i++)
    {
        a[id] = i;
        getAns(id+1,k);
    }
    a[id] = k+1;
    getAns(id+1,k+1);
}
int main()
{
    freopen("shattersong.in","r",stdin);
    freopen("shattersong.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",z+i);
    for (int i=1;i<=m;i++) scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
    sort(E+1,E+m+1);
    dfs(1,1);
    getAns(1,1);
    return 0;
}