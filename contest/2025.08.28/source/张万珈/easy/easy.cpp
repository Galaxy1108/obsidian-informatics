#include <bits/stdc++.h>
using namespace std;
#define ls (p<<1)
#define rs (p<<1|1)
#define mid ((l+r)>>1)
#define int unsigned long long
long long a[200010];
long long t[1000010],tag[1000010];
long long mx1[1000010],mx2[1000010],cnt1[1000010],cnt2[1000010];

void pushup(int p)
{
    t[p] = t[ls] + t[rs];
    mx1[p] = mx2[p] = 0;
    cnt1[p] = cnt2[p] = 0;
    if(mx1[ls] > mx1[p])
    {
        mx2[p] = mx1[p];
        cnt2[p] = cnt1[p];
        mx1[p] = mx1[ls];
        cnt1[p] = cnt1[ls];
    }
    else if(mx1[ls] == mx1[p])
    {
        cnt1[p] += cnt1[ls];
    }
    else if(mx1[ls] > mx2[p])
    {
        mx2[p] = mx1[ls];
        cnt2[p] = cnt1[ls];
    }
    else if(mx1[ls] == mx2[p])
    {
        cnt2[p] += cnt1[ls];
    }
    if(mx2[ls] > mx1[p])
    {
        mx2[p] = mx1[p];
        cnt2[p] = cnt1[p];
        mx1[p] = mx2[ls];
        cnt1[p] = cnt2[ls];
    }
    else if(mx2[ls] == mx1[p])
    {
        cnt1[p] += cnt2[ls];
    }
    else if(mx2[ls] > mx2[p])
    {
        mx2[p] = mx2[ls];
        cnt2[p] = cnt2[ls];
    }
    else if(mx2[ls] == mx2[p])
    {
        cnt2[p] += cnt2[ls];
    }
    if(mx1[rs] > mx1[p])
    {
        mx2[p] = mx1[p];
        cnt2[p] = cnt1[p];
        mx1[p] = mx1[rs];
        cnt1[p] = cnt1[rs];
    }
    else if(mx1[rs] == mx1[p])
    {
        cnt1[p] += cnt1[rs];
    }
    else if(mx1[rs] > mx2[p])
    {
        mx2[p] = mx1[rs];
        cnt2[p] = cnt1[rs];
    }
    else if(mx1[rs] == mx2[p])
    {
        cnt2[p] += cnt1[rs];
    }
    if(mx2[rs] > mx1[p])
    {
        mx2[p] = mx1[p];
        cnt2[p] = cnt1[p];
        mx1[p] = mx2[rs];
        cnt1[p] = cnt2[rs];
    }
    else if(mx2[rs] == mx1[p])
    {
        cnt1[p] += cnt2[rs];
    }
    else if(mx2[rs] > mx2[p])
    {
        mx2[p] = mx2[rs];
        cnt2[p] = cnt2[rs];
    }
    else if(mx2[rs] == mx2[p])
    {
        cnt2[p] += cnt2[rs];
    }    
}
void pushdown(int p,int l,int r)
{
    if(!tag[p]) return;
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    t[ls] += tag[p]*(mid-l+1);
    t[rs] += tag[p]*(r-mid);
    mx1[ls] += tag[p];
    mx2[ls] += tag[p];
    mx1[rs] += tag[p];
    mx2[rs] += tag[p];
    tag[p] = 0;
    return;
}
void build(int p,int l,int r)
{
    if(l == r)
    {
        t[p] = a[l];
        mx1[p] = a[l];
        cnt1[p] = 1;
        mx2[p] = 0;
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
long long query(int p,int l,int r,int L,int R)
{
    pushdown(p,l,r);
    if(L <= l && r <= R)
    {
        return t[p];
    }
    long long ret=0;
    if(L <= mid) ret += query(ls,l,mid,L,R);
    if(R > mid) ret += query(rs,mid+1,r,L,R);
    return ret;
}
void add(int p,int l,int r)
{
    pushdown(p,l,r);
    if(l == r)
    {
        t[p] += l;
        mx1[p] += l;
        return;
    }
    t[p] += ((l+r)*(r-l+1))>>1;
    add(ls,l,mid);
    add(rs,mid+1,r);
    pushup(p);
}
void mn(int p,int l,int r,int L,int R,long long x)
{
    pushdown(p,l,r);
    if(l == r)
    {
        t[p] = min(t[p],x);
        mx1[p] = t[p];
        return;
    }
    if(mx1[p] <= x) return;
    else
    {
        mn(ls,l,mid,L,R,x);
        mn(rs,mid+1,r,L,R,x);
        pushup(p);
    }
}
signed main()
{
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    for(int i=1,tp;i<=q;i++)
    {
        cin >> tp;
        if(tp == 1)
        {
            int v;
            cin >> v;
            mn(1,1,n,1,n,v);
        }
        else if(tp==2)
        {
            add(1,1,n);
        }
        else if(tp==3)
        {
            int l,r;
            cin >> l >> r;
            cout << query(1,1,n,l,r) << endl;
        }
        // for(int i=1;i<=n;i++)cout << query(1,1,n,i,i) << ' ';
        // cout << endl << endl;
    }
}