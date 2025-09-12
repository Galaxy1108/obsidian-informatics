#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 2e5 + 12;
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
int n,m;
long long val[MAXN],ans;
void work()
{
    n = read(),m = read();
    for (int i=1;i<=n;i++) val[i] = 0;
    for (int i=1;i<=m;i++)
    {
        int u = read(),v = read(),w = read();
        val[u] += w,val[v] += w;
    }
    sort(val+1,val+n+1);
    int f = 1;
    ans = 0;
    for (int i=n;i>=1;i--)
    {
        ans += val[i]*f;
        f = -f;
    }
    printf("%lld\n",ans/2);
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int t = read();
    while (t--) work();
    return 0;
}