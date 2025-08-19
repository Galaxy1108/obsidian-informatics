#include <cstdio>

const long double eps=1e-9;
int n,cost,w[5010];
long double c[5010],d[5010],maxn;

long double max(long double x,long double y)
{
    return x-y>eps?x:y;
}

void dfs(int x,long double ch,long double dol)
{
    if (x==n+1)
    {
        maxn=max(maxn,ch);
        return;
    }
    // change dollar to rmb
    if ((dol || x==n) && dol*d[x]>cost)
        dfs(x+1,ch+w[x+1]-cost+dol*d[x],0);
    // change rmb to dollar
    if (ch && x!=n)
        dfs(x+1,w[x+1],ch*c[x]);
    // no change
    dfs(x+1,ch+w[x+1],dol);
}

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d%d",&n,&cost);
    for (int i=1;i<=n;i++)
        scanf("%d%Lf%Lf",w+i,c+i,d+i);
    dfs(1,w[1],0);
    printf("%.4Lf\n",maxn);
    return 0;
}
