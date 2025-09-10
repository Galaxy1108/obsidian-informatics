#include <cstdio>
#include <vector>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 1e5 + 12;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
    if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
    return *(iS++);
}
inline int read()
{
    int x = 0;
    char ch = mget();
    while (ch<'0'||ch>'9') ch = mget();
    while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
    return x;
}
vector<int> E[MAXN];
int n,m;
int vis[MAXN],cnt;
int sum[MAXN],ans;
void dfs(int u,int cl)
{
    vis[u] = cl;
    for (int i=0;i<E[u].size();i++)
    {
        int v = E[u][i];
        if (vis[v]) continue ;
        dfs(v,cl);
    }
}
int main()
{
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    n = read(),m = read();
    for (int i=1;i<=m;i++)
    {
        int u = read(),v = read();
        E[u].push_back(v),E[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        if (vis[i]==0)
        {
            cnt++;
            dfs(i,cnt);
        }
    for (int u=1;u<=n;u++)
        sum[vis[u]] += E[u].size();
    for (int i=1;i<=cnt;i++)
    {
        sum[i] /= 2;
        ans += sum[i]/2;
    }
    printf("%d",ans);
    return 0;
}