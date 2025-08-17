#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    register int x=0;
    register char ch=cin.get();
    while(!isdigit(ch)) ch=cin.get();
    while(isdigit(ch)) {(x*=10)+=(ch^48);ch=cin.get();}
    return x;
}
const int mod = 1e9+9;
const int N = 1e5+9;
int n,m,q,ans[N];
vector<int>hav[N];
int a[N],sum[N];
struct OP{int l,r,x;}P[N],Q[N];
int main()
{
    ios::sync_with_stdio(0);
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
    n=read(),m=read(),q=read();
    for(register int i(1);i<=m;++i) P[i]={read(),read(),read()};
    for(register int i(1),L,R,l,r;i<=q;++i) 
    {
        L=read(),R=read(),l=read(),r=read();
        for(register int j(L);j<=R;++j) hav[j].push_back(i);
        Q[i]={l,r,i};
    }
    for(register int i(1),l,r,x;i<=m;++i) 
    {
        l=P[i].l,r=P[i].r,x=P[i].x; 
        for(register int j(l);j<=r;++j) a[j]=(a[j]+x)%mod;
        for(register int j(l);j<=n;++j) sum[j]=(sum[j-1]+a[j])%mod;
        for(auto p:hav[i]) ans[p]=(1ll*ans[p]+sum[Q[p].r]-sum[Q[p].l-1]+mod)%mod;
    }
    for(register int i(1);i<=q;++i) printf("%d\n",ans[i]);
    return 0;
}
