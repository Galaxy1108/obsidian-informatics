#include <cstdio>
#include <algorithm>
using ll=long long;

int n,m;
ll ans,w[200010];

int read()
{
    int x=0;
    char ch=getchar();
    while (!isdigit(ch))
        ch=getchar();
    while (isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

void write(ll x)
{
    if (x>=10)
        write(x/10);
    putchar(x%10+'0');
}

bool cmp(ll x,ll y)
{
    return x>y;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int T,u,v,ww;
    T=read();
    while (T--)
    {
        for (int i=0;i<n;i++)
            w[i]=0;
        n=read(),m=read();
        ans=0;
        for (int i=0;i<m;i++)
        {
            u=read(),v=read(),ww=read();
            w[v]+=ww;
        }
        std::sort(w+2,w+n+1,cmp);
        for (int i=1;i<n;i+=2)
            ans+=w[i];
        write(ans);
        putchar('\n');
    }
    return 0;
}
