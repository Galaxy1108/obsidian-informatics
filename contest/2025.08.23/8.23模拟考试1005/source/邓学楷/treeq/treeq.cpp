#include <cstdio>
#include <cstring>
#include <vector>
typedef long long ll;

const ll inf=0x7f7f7f7f7f7f7f7f;
int n,c[1000010],cost[1000010],fans[1000010];
ll ans;
struct edge
{
    int to,dis,id;
};
std::vector<edge> vec[1000010];

ll max(ll x,ll y)
{
    return x>y?x:y;
}

int dfs(int u,int f)
{
    int ans=1,t;
    for (edge v:vec[u])
    {
        if (v.to==f)
            continue;
        t=dfs(v.to,u);
        ans+=t;
        c[v.id]+=t;
    }
    return ans;
}

int main()
{
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
    int f,w,wm1=-0x7f7f7f7f,wm2=-0x7f7f7f7f,wmid1,wmid2;
    bool chain=1,fl=1;
    ll a;
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
    {
        scanf("%d%d",&f,&w);
        vec[i].push_back(edge{f,w,i});
        vec[f].push_back(edge{i,w,i});
        if (f!=1)
            fl=0;
        if (f!=i-1)
            chain=0;
        if (w>wm1)
            wm2=wm1,wmid2=wmid1,wm1=w,wmid1=i;
        if (w>wm2 && w<wm1)
            wm2=w,wmid2=i;
        cost[i]=w;
    }
    if (fl)
    {
        // for i=1
        fans[wmid1]++;
        for (int i=2;i<=n;i++)
        {
            if (cost[i]==wmid1)
            {
                if (1ll*(n-1)*cost[i]>wm2)
                    fans[i]++;
                else if (1ll*(n-1)*cost[i]<wm2)
                    fans[wmid2]++;
                else
                    fans[i]++,fans[wmid2]++;
            }
            else
            {
                if (1ll*(n-1)*cost[i]>wm1)
                    fans[i]++;
                else if (1ll*(n-1)*cost[i]<wm1)
                    fans[wmid1]++;
                else
                    fans[i]++,fans[wmid1]++;
            }
        }
        for (int i=2;i<=n;i++)
            ans^=fans[i];
        printf("%lld\n",ans);
    }
    else if (n<=5000 || chain)
    {
        for (int i=1;i<=n;i++)
        {
            if (!chain)
                dfs(i,-1);
            else
            {
                for (int j=2;j<=n;j++)
                {
                    if (j<=i)
                        c[j]=j-1;
                    else
                        c[j]=n+1-j;
                }
            }
            a=-inf;
            for (int j=2;j<=n;j++)
                a=max(a,1ll*c[j]*cost[j]);
            for (int j=2;j<=n;j++)
                if (c[j]*cost[j]==a)
                    fans[j]++;
            memset(c,0,sizeof c);
        }
        for (int i=2;i<=n;i++)
            ans^=fans[i];
        printf("%lld\n",ans);
    }
    return 0;
}
