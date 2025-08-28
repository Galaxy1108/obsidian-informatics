#include <bits/stdc++.h>
using namespace std;
#define ls (p<<1)
#define rs (p<<1|1)
#define mid ((l+r)>>1)
const int mod = 998244353;

long long tga[1000010],tgb[1000010],tgc[1000010];
long long ta[1000010],tb[1000010],tc[1000010];
long long a[250010],b[250010],c[250010];

void pushup(int p)
{
    ta[p] = (ta[ls] + ta[rs]) % mod;
    tb[p] = (tb[ls] + tb[rs]) % mod;
    tc[p] = (tc[ls] + tc[rs]) % mod;
    return;
}
void pushupb(int p)
{
    tb[p] = (tb[ls] + tb[rs]) % mod;
    return;
}
void pushupc(int p)
{
    tc[p] = (tc[ls] + tc[rs]) % mod;
    return;
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        ta[p] = a[l];
        tb[p] = b[l];
        tc[p] = c[l];
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
void changea(int p,int l,int r,int L,int R,int x)
{
    ta[p] += (min(R,r)-max(L,l)+1)*x;
    ta[p] %= mod;
    if(L <= l && r <= R)
    {
        tga[p] += x;
        tga[p] %= mod;
        return;
    }
    if(L <= mid) changea(ls,l,mid,L,R,x);
    if(R > mid) changea(rs,mid+1,r,L,R,x);
    return;
}
void changeb(int p,int l,int r,int L,int R,int x)
{
    if(L <= l && r <= R)
    {
        tgb[p] *= x;
        tb[p] *= x;
        tb[p] %= mod;
        return;
    }
    if(L <= mid) changeb(ls,l,mid,L,R,x);
    if(R > mid) changeb(rs,mid+1,r,L,R,x);
    pushupb(p);
    return;
}
void changec(int p,int l,int r,int L,int R,int x)
{
    if(L <= l && r <= R)
    {
        tgc[p] = x;
        tc[p] = (r-l+1)*x % mod;
        return;
    }
    if(L <= mid) changec(ls,l,mid,L,R,x);
    if(R > mid) changec(rs,mid+1,r,L,R,x);
    pushupc(p);
    return;
}
long long querya(int p,int l,int r,int L,int R,int tg)
{
    if(L <= l && r <= R)
    {
        return (ta[p]+tg*(r-l+1)) % mod;
    }
    long long ret = 0;
    if(L <= mid) ret += querya(ls,l,mid,L,R,tg+tga[p]);
    if(R > mid) ret += querya(rs,mid+1,r,L,R,tg+tga[p]);
    return ret % mod;
}
long long queryb(int p,int l,int r,int L,int R,int tg)
{
    if(L <= l && r <= R)
    {
        return tb[p]*tg % mod;
    }
    long long ret = 0;
    if(L <= mid) ret += queryb(ls,l,mid,L,R,tg*tgb[p]);
    if(R > mid) ret += queryb(rs,mid+1,r,L,R,tg*tgb[p]);
    return ret % mod;
}
long long queryc(int p,int l,int r,int L,int R,int tg)
{
    if(L <= l && r <= R)
    {
        if(tg == -1) return tc[p] % mod;
        else return tg*(r-l+1) % mod;
    }
    long long ret = 0;
    if(L <= mid) ret += queryc(ls,l,mid,L,R,tgc[p]);
    if(R > mid) ret += queryc(rs,mid+1,r,L,R,tgc[p]);
    return ret % mod;
}

void subtask1(int n,int m)
{
    for(int qwq=1,tp,l,r,x;qwq<=m;qwq++)
    {
        cin >> tp ;
        if(tp == 1)
        {
            cin >> l >> r;
            for(int i=l;i<=r;i++)
            {
                a[i] += b[i];
                a[i] %= mod;
            }
        }
        if(tp==2)
        {
            cin >> l >> r;
            for(int i=l;i<=r;i++)
            {
                b[i] += c[i];
                b[i] %= mod;
            }
        }
        if(tp == 3)
        {
            cin >> l >> r;
            for(int i=l;i<=r;i++)
            {
                c[i] += a[i];
                c[i] %= mod;
            }
        }
        if(tp == 4)
        {
            cin >> l >> r >> x;
            for(int i=l;i<=r;i++)
            {
                a[i] += x;
                a[i] %= mod;
            }
        }
        if(tp == 5)
        {
            cin >> l >> r >> x;
            for(int i=l;i<=r;i++)
            {
                b[i] *= x;
                b[i] %= mod;
            }
        }
        if(tp == 6)
        {
            cin >> l >> r >> x;
            for(int i=l;i<=r;i++)
            {
                c[i] = x;
                c[i] %= mod;
            }
        }
        if(tp == 7)
        {
            long long resa=0,resb=0,resc=0;
            cin >> l >> r;
            for(int i=l;i<=r;i++)
            {
                resa += a[i];
                resb += b[i];
                resc += c[i];
                resa %= mod;
                resb %= mod;
                resc %= mod;
            }
            cout << resa << ' ' << resb << ' ' << resc << endl;
        }
    }
}

int main()
{
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    memset(tgc,-1,sizeof(tgc));
    memset(tgb,1,sizeof(tgb));
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    build(1,1,n);
    int m;
    cin >> m;
    if(n <= 1000 && m <= 1000) {subtask1(n,m);return 0;}
    for(int i=1,tp,l,r,x;i<=m;i++)
    {
        cin >> tp;
        if(tp == 1 || tp == 2 || tp == 3)
        {
            return 0;
        }
        if(tp == 4)
        {
            cin >> l >> r >> x;
            changea(1,1,n,l,r,x);
        }
        if(tp == 5)
        {
            cin >> l >> r >> x;
            changeb(1,1,n,l,r,x);
        }
        if(tp == 6)
        {
            cin >> l >> r >> x;
            changec(1,1,n,l,r,x);
        }
        if(tp == 7)
        {
            cin >> l >> r;
            cout << (querya(1,1,n,l,r,0)%mod + mod) % mod  << ' ' << (queryb(1,1,n,l,r,1)%mod + mod) % mod << ' ' << (queryc(1,1,n,l,r,-1)%mod + mod) % mod  << endl;
        }
    }
    return 0;
}