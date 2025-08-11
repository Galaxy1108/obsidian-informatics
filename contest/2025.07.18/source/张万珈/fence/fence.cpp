#include <bits/stdc++.h>
using namespace std;
namespace my_std{
#define int long long
int ls(int x) {return x<<1;}
int rs(int x) {return x<<1|1;}
const int N = 1e6+10,mod = 1e9+7;
int t[N<<2],w[N];
int lt[N<<2],rt[N<<2];
bool tag[N<<2];
struct height{
    int h,id;
};
height h[N];
bool cmp(height a,height b)
{
    return a.h < b.h;
}
int times(int a,int b)
{
    int res=0;
    if(b<0) a=-a,b=-b;
    while(b)
    {
        if(b&1) res = (res+a) % mod;
        b >>= 1;
        a = (a+a) % mod;
    }
    return res;
}
int cnt(int x){return (times((times(x,x+1)),500000004)) % mod;}
void pushup(int p)
{
    if(tag[ls(p)])
    {
        if(tag[rs(p)])
        {
            t[p] = (cnt(rt[ls(p)] + lt[rs(p)])) % mod;
            lt[p] = rt[p] = (rt[ls(p)] + lt[rs(p)]) % mod;
            tag[p] = 1;
            return;
        }
        else if(lt[rs(p)])
        {
            t[p] = (((t[rs(p)] - cnt(lt[rs(p)])) % mod) + mod) % mod;
            t[p] = (t[p] + cnt(rt[ls(p)] + lt[rs(p)])) % mod;
            lt[p] = (lt[ls(p)] + lt[rs(p)]) % mod;
            rt[p] = rt[rs(p)] % mod;
            tag[p] = 0;
            return;
        }
        else
        {
            t[p] = (t[rs(p)] + t[ls(p)]) % mod;
            lt[p] = lt[ls(p)] % mod;
            rt[p] = rt[rs(p)] % mod;
            tag[p] = 0;
            return;
        }
    }
    if(tag[rs(p)])
    {
        if(rt[ls(p)])
        {
            t[p] = (((t[ls(p)] - cnt(rt[ls(p)])) % mod) + mod) % mod;
            t[p] = (t[p] + cnt(lt[rs(p)] + rt[ls(p)])) % mod;
            lt[p] = lt[ls(p)];
            rt[p] = (rt[rs(p)] + rt[ls(p)]) % mod;
            tag[p] = 0;
            return;
        }
        else
        {
            t[p] = (t[rs(p)] + t[ls(p)]) % mod;
            lt[p] = lt[ls(p)] % mod;
            rt[p] = rt[rs(p)] % mod;
            tag[p] = 0;
            return;
        }
    }
    if(rt[ls(p)] && lt[rs(p)])
    {
        t[p] = (t[rs(p)] + t[ls(p)]) % mod;
        t[p] = (((t[p] - cnt(rt[ls(p)])) % mod) + mod) % mod;
        t[p] = (((t[p] - cnt(lt[rs(p)])) % mod) + mod) % mod;
		t[p] = (t[p] + cnt(rt[ls(p)] + lt[rs(p)])) % mod;
        lt[p] = lt[ls(p)];
        rt[p] = rt[rs(p)];
        tag[p] = 0;
        return ;
    }
    t[p] = (t[rs(p)] + t[ls(p)]) % mod;
    lt[p] = lt[ls(p)] % mod;
    rt[p] = rt[rs(p)] % mod;
    tag[p] = 0;
    return;
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        t[p] = cnt(w[l]);
        lt[p] = rt[p] = w[l];
        tag[p] = 1;
        return; 
    }
    int mid = (l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    pushup(p);
}
void add(int p,int l,int r,int x)
{
    if(l==r)
    {
        t[p]=0;
        lt[p]=rt[p]=tag[p]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) add(ls(p),l,mid,x);
    if(x>=mid+1) add(rs(p),mid+1,r,x);
    pushup(p);
}
#undef int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> h[i].h;
        h[i].id = i;
    }
    sort(h+1,h+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        cin >> w[i];
    }
    build(1,1,n);
    int nxt = 0;
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(h[i].h > h[i-1].h || i==n) ans = (ans+times(t[1],(((cnt(h[i].h%mod) - cnt(nxt%mod)) % mod) + mod) % mod) % mod) % mod,nxt = h[i].h;
        add(1,1,n,h[i].id);
    }
    cout << ans % mod;
    return 0;
}
}
int main()
{
    return my_std::main();
}
