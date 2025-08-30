#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;

int n,k,a[510],fa[510];
bool sel[510];
vi vec[510];
long long ans;

struct node
{
    int dat,id;
    bool operator <(node oth) const
    {
        if (dat==oth.dat)
            return id>oth.id;
        return dat>oth.dat;
    }
} g[510];

void add(vi& x,vi y)
{
    for (auto i:y)
        x.push_back(i);
}

int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}

int gcd(vi v)
{
    int g=v[0];
    for (int i=1;i<v.size();i++)
        g=gcd(g,v[i]);
    return g;
}

vi work(int u,int f)
{
    vi son;
    fa[u]=f;
    son.push_back(a[u]);
    for (int v:vec[u])
    {
        if (v==f || v==-1)
            continue;
        add(son,work(v,u));
    }
    g[u]={gcd(son),u};
    return son;
}

void ban(int f,int u)
{
    for (int i=0;i<vec[f].size();i++)
        if (vec[f][i]==u)
            vec[f][i]=-1;
}

int main()
{
    freopen("plan.in","r",stdin);
    freopen("plan.out","w",stdout);
    int u,v;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n-1;i++)
    {
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    u=0;
    while (u<k)
    {
        work(1,-1);
        std::sort(g+1,g+n+1);
        for (v=1;v<=n;v++)
            if (!sel[v])
                break;
        sel[v]=1;
        ans+=g[v].dat;
        ban(fa[g[v].id],g[v].id);
        u++;
    }
    work(1,-1);
    ans+=g[1].dat;
    printf("%lld\n",ans);
    return 0;
}