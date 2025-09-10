#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 12;
const int SIZE = 1<<21;
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
int n,p[MAXN],q[MAXN],h[MAXN];
int visp[MAXN],visq[MAXN];
vector<int> tonp[MAXN],tonq[MAXN];
int findp(int x)
{
    if (visp[x]) return 0;
    visp[x] = 1;
    return findp(p[x]) + 1;
}
int findq(int x)
{
    if (visq[x]) return 0;
    visq[x] = 1;
    return findq(q[x]) + 1;
}
void work(int x,int y,int sz)
{
    while (sz--)
    {
        h[y] = x;
        x = p[x],y = q[y];
    }
}
int main()
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    n = read();
    for (int i=1;i<=n;i++) p[i] = read();
    for (int i=1;i<=n;i++) q[i] = read();
    for (int i=1;i<=n;i++)
        if (visp[i]==0)
            tonp[findp(i)].push_back(i);
    for (int i=1;i<=n;i++)
        if (visq[i]==0)
            tonq[findq(i)].push_back(i);
    for (int i=1;i<=n;i++)
    {
        if (tonp[i].size()!=tonq[i].size())
        {
            printf("NO");
            return 0;
        }
        for (int j=0;j<tonp[i].size();j++)
        {
            work(tonp[i][j],tonq[i][j],i);
        }
    }
    printf("YES\n");
    for (int i=1;i<=n;i++) printf("%d ",h[i]);
    return 0;
}