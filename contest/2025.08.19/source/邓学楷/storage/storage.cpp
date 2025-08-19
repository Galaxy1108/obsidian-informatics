#include <cstdio>
typedef long long ll;

int n,x[1000010],p[1000010],c[1000010];
ll minn=0x7f7f7f7f7f7f7f7f;

ll min(ll x,ll y)
{
    return x<y?x:y;
}

void dfs(int cur,int ls,ll res)
{
    if (cur==0)
    {
        minn=min(minn,res);
        return;
    }
    // build
    dfs(cur-1,cur,res+c[cur]);
    // not build
    if (ls!=-1)
        dfs(cur-1,ls,res+p[cur]*(x[ls]-x[cur]));
}

int main()
{
    freopen("storage.in","r",stdin);
    freopen("storage.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",x+i,p+i,c+i);
    dfs(n,-1,0);
    printf("%lld\n",minn);
    return 0;
}