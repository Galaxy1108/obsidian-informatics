#include <cstdio>
#include <random>
#include <algorithm>
#include <cstring>
const int MAXN=5010;
int a[MAXN][MAXN];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
using namespace std;
int n,seed;
int f[1<<19];
int dfs(int p,int s,int id)
{
    if (f[s]) return f[s];
    if (id==n+1)
    {
        for (int i=0;i<=n;i++)
            if (s&(1<<i))
                return f[s] = i+1;
    }
    int np = p+1;
    if (np>n) np = 1;
    int res = 0,val = 0;
    for (int i=0;i<=n;i++)
        if (s&(1<<i))
        {
            int cur = dfs(np,s^(1<<i),id+1);
            if (a[p][cur]>val)
                res = cur,val = a[p][cur];
        }
    return f[s] = res;
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d%d",&n,&seed);
    if (seed==0)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n+1;j++)
                scanf("%d",&a[i][j]);
    else gen(n,seed);
    for (int i=1;i<=n;i++)
    {
        memset(f,0,sizeof(f));
        printf("%d ",dfs(i,(1<<(n+1))-1,1));
    }
    return 0;
}