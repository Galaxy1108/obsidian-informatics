#include<bits/stdc++.h>
using namespace std;
#define ls (p<<1)
#define rs (p<<1|1)
const int N=2e6+5;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(__int128 x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int n,a[N];
__int128 ans=0,an=0;
struct node{
    int mi,mx,mip;
}t[N<<2];

node up(const node &n1,const node &n2){
    node ans;
    ans.mi=min(n1.mi,n2.mi);
    ans.mx=max(n1.mx,n2.mx);
    if(n1.mi==ans.mi)ans.mip=n1.mip;
    else ans.mip=n2.mip;
    return ans;
}

void build(int p,int l,int r){
    if(l==r){
        t[p].mi=t[p].mx=a[l];t[p].mip=l;return;
    }
    int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    t[p]=up(t[ls],t[rs]);
}

node query(int p,int l,int r,const int &ql,const int &qr){
    if(ql<=l&&r<=qr)return t[p];
    int mid=l+r>>1;
    if(qr<=mid)return query(ls,l,mid,ql,qr);
    if(ql>mid)return query(rs,mid+1,r,ql,qr);
    return up(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}

void solve(int l,int r){
    if(l>r)return;
    node s=query(1,1,n,l,r);
    an=(__int128)s.mi*s.mx*(r-l+1);
    ans=max(ans,an);
    solve(l,s.mip-1);solve(s.mip+1,r);
}

signed main(){
    freopen("drama.in","r",stdin);
    freopen("drama.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    build(1,1,n);
    solve(1,n);
    print(ans);putchar('\n');
    return 0;
}