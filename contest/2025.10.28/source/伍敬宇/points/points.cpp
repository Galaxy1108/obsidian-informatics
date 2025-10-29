#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 2e5 + 12;
struct Interval{
    int tp,id;
    long long l,r;
    bool operator<(const Interval&rhs) const{
        //return l < rhs.l;
        if (l!=rhs.l) return l < rhs.l;
        if (r!=rhs.r) return r > rhs.r;
        return tp < rhs.tp;
    }
}I[MAXN<<1];
int cnt = 0;
int n,m;
long long f[MAXN];
inline void upd(long long&x,long long y)
{
    if (x>y) x = y;
}
void solve(int l,int r,int L,int R,long long val)
{
    if (r<l) return ;
    int md = (l+r)>>1;
    long long mn = 0x3f3f3f3f3f3f3f3f;
    int opt;
    for (int i=L;i<=R;i++)
    {
        long long cur = f[I[i].id-1] + I[md].l - I[i].r + min(I[md].l-val,val-I[i].r);
        if (cur<mn) mn = cur,opt = i;
    }
    solve(l,md-1,L,opt,val),solve(md+1,r,opt,R,val);
    upd(f[I[md].id],mn);
}
int main()
{
    freopen("points.in","r",stdin);
    freopen("points.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        long long a;
        scanf("%lld",&a);
        I[++cnt] = {1,0,a,a};
    }
    for (int j=1;j<=m;j++)
    {
        long long l,r;
        scanf("%lld%lld",&l,&r);
        I[++cnt] = {0,0,l,r};
    }
    sort(I+1,I+cnt+1);
    long long cr = 1e18;
    int tm = m;
    for (int i=cnt;i>=1;i--)
    {
        if (I[i].r>=cr) 
        {
            if(I[i].tp==0) I[i].id = -1,tm--;
        }
        else cr = I[i].r;
    }
    //printf("TM  %d\n",tm);
    int ncnt = 0;
    for (int i=1;i<=cnt;i++) 
        if (I[i].id!=-1)
            I[++ncnt] = I[i];
    cnt = ncnt;
    m = 0;
    for (int i=1;i<=cnt;i++)
        if (I[i].tp==0)
            I[i].id = ++m;
    memset(f,0x3f3f3f3f,sizeof(f));
    f[0] = 0;
    for (int t=1;t<=cnt;t++)
    {
        if (I[t].tp==0) continue ;
        int l1 = t,r1 = t-1;
        while (l1-1>0&&I[l1-1].tp==0) l1--;
        int l2 = t+1,r2 = t;
        while (r2<cnt&&I[r2+1].tp==0) r2++;
        if (r1<l1&&r2<l2) continue ;
        //printf("%d %d %d %d %d\n",t,l1,r1,l2,r2);
        if (r1<l1)
        {
            for (int i=l2;i<=r2;i++)
                upd(f[I[i].id],f[I[l2].id-1]+I[i].l-I[t].r);
            continue ;
        }
        if (r2<l2)
        {
            for (int i=l1;i<=r1;i++)
                upd(f[I[r1].id],f[I[i].id-1]+I[t].l-I[i].r);
            continue ;
        }
        solve(l2,r2,l1,r1,I[t].l);
   
        for (int i=l2;i<=r2;i++)
            upd(f[I[i].id],f[I[l2].id-1]+I[i].l-I[t].r);
        for (int i=l1;i<=r1;i++)
            upd(f[I[r1].id],f[I[i].id-1]+I[t].l-I[i].r);
    }
    // for (int i=1;i<=cnt;i++)
    //     printf("%d %d %lld %lld %lld\n",I[i].tp,I[i].id,I[i].l,I[i].r,f[I[i].id]);
    printf("%lld",f[m]);
    return 0;
}