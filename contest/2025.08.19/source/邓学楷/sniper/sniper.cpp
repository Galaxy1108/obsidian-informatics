#include <cstdio>
typedef long long ll;

const int p[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int n,w[8010],u[8010],t[8010];
ll maxn;

ll max(ll x,ll y)
{
    return x>y?x:y;
}

ll abs(ll x)
{
    return x>=0?x:-x;
}

void dfs(int x,int lu,int lt,ll res)
{
    if (x==n+1)
    {
        maxn=max(maxn,res);
        return;
    }
    if ((x==1) || (t[x]-lt-2)*2>=abs(u[x]-lu)) // can kill current
        dfs(x+1,u[x],t[x],res+p[w[x]]);
    if(w[x]!=15) // current is not sniper, can be not killed
        dfs(x+1,lu,lt,res); // don't kill
}

int main()
{
    freopen("sniper.in","r",stdin);
    freopen("sniper.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",w+i,u+i,t+i);
    dfs(1,0,0,0);
    printf("%lld\n",maxn);
    return 0;
}
