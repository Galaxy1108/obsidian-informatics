#include <cstdio>
using namespace std;
const int MAXN = 300 + 12;
const int MAXQ = 2e5 + 12;
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
int n,q,a[MAXN][MAXN];
struct QueryNode{
    int x1,y1,x2,y2,id;
}Q[MAXQ],temp[MAXQ];
long long ans[MAXQ];
long long dis1[MAXN][MAXN][MAXN],dis2[MAXN][MAXN][MAXN];
inline void upd(long long&x,long long y)
{
    if (x>y) x = y;
}
void cal1(int x,int y,int l)
{
    dis1[y][x][y] = a[x][y];
    for (int i=x;i>=l;i--)
        for (int j=y;j>=1;j--)
        {
            if (i==x&&j==y) continue ;
            dis1[y][i][j] = 1e18;
            if (i<x) upd(dis1[y][i][j],dis1[y][i+1][j]);
            if (j<y) upd(dis1[y][i][j],dis1[y][i][j+1]);
            dis1[y][i][j] += a[i][j];
        }
}
void cal2(int x,int y,int r)
{
    dis2[y][x][y] = a[x][y];
    for (int i=x;i<=r;i++)
        for (int j=y;j<=n;j++)
        {
            if (i==x&&j==y) continue ;
            dis2[y][i][j] = 1e18;
            if (i>x) upd(dis2[y][i][j],dis2[y][i-1][j]);
            if (j>y) upd(dis2[y][i][j],dis2[y][i][j-1]);
            dis2[y][i][j] += a[i][j];
        }
}
void solve(int l,int r,int L,int R)
{
    if (R<L) return ;
    if (l==r)
    {
        for (int i=L;i<=R;i++)
            for (int j=Q[i].y1;j<=Q[i].y2;j++)
                ans[Q[i].id] += a[l][j];
        return ;
    }
    int md = (l+r)>>1;
    for (int i=1;i<=n;i++)
        cal1(md,i,l),cal2(md+1,i,r);
    int nL = L-1,nR = R+1;
    for (int i=L;i<=R;i++)
    {
        if (Q[i].x1<=md&&Q[i].x2>md)
        {
            long long cur = 1e18;
            for (int j=Q[i].y1;j<=Q[i].y2;j++)
                upd(cur,dis1[j][Q[i].x1][Q[i].y1]+dis2[j][Q[i].x2][Q[i].y2]);
            ans[Q[i].id] = cur;
        }
        else if (Q[i].x1<=md&&Q[i].x2<=md) temp[++nL] = Q[i];
        else temp[--nR] = Q[i];
    }
    for (int i=L;i<=R;i++) Q[i] = temp[i];
    solve(l,md,L,nL),solve(md+1,r,nR,R);
}
int main()
{
    freopen("glyph.in","r",stdin);
    freopen("glyph.out","w",stdout);
    n = read(),q = read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j] = read();
    for (int i=1;i<=q;i++)
        Q[i].x1 = read(),Q[i].x2 = read(),Q[i].y1 = read(),Q[i].y2 = read(),Q[i].id = i;
    solve(1,n,1,q);
    for (int i=1;i<=q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}