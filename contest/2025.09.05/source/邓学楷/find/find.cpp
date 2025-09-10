#include <cstdio>
#define max(x,y) ((x)>(y)?(x):(y))
using ll=long long;

const int M=1e9+7;
ll n,k,af[5010],mp[5010][5010],mm[5010][5010],ans;

ll f(int x)
{
    if (af[x]==-1)
    {
	    ll ans=1;
	    while (x)
	    {
	        ans*=x%10;
	        x/=10;
	        if (ans>n)
	            return -1;
	    }
	    af[x]=ans;
	}
    return af[x];
}

void change()
{
    ll fi,fj;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            mm[i][j]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (!mp[i][j])
                continue;
            fi=f(i),fj=f(j);
            if (fi==-1 || fj==-1)
                continue;
            mm[fi][fj]+=mp[i][j];
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            mp[i][j]=mm[i][j];
}

ll getmax()
{
    ll maxn=-1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            maxn=max(maxn,mp[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (mp[i][j]==maxn)
            {
                mp[i][j]=0;
                return maxn;
            }
    return maxn;
}

int main()
{
    freopen("find.in","r",stdin);
    freopen("find.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            mp[i][j]=1;
        af[i]=-1;
    }
    while (k--)
    {
        change();
        ans+=getmax()%M;
        ans%=M;
    }
    printf("%lld\n",ans);
    return 0;
}
