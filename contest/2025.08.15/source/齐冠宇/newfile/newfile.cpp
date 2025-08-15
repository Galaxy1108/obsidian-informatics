#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
using namespace std;
constexpr int N=1e5+5,mod=1e9+9;
int n,m,q;
int ans[N];
struct ask{
	int f,l,r,id;
	ask(){}
	ask(int f,int l,int r,int id):f(f),l(l),r(r),id(id){}
};
vector<ask>ak[N];
struct op{
	int l,r,x;
	op(){}
	op(int l,int r,int x):l(l),r(r),x(x){} 
}s[N];
struct tree{
	int sm,tg,hsm,htg,cnt;
}tr[N<<2];
#define ls k<<1
#define rs k<<1|1
inline void pu(int k)
{
	tr[k].sm=(tr[ls].sm+tr[rs].sm)%mod;
	tr[k].hsm=(tr[ls].hsm+tr[rs].hsm)%mod;
}
inline void mt(int k,int l,int r,int val)
{
	(tr[k].sm+=1ll*(r-l+1)*val%mod)%=mod,(tr[k].tg+=val)%=mod;
}
inline void mth(int k,int l,int r,int val,int cnt)
{
	(tr[k].hsm+=(1ll*tr[k].sm*cnt%mod+1ll*val*(r-l+1)%mod)%mod)%=mod;
	(tr[k].cnt+=cnt)%=mod;
	(tr[k].htg+=(1ll*tr[k].tg*cnt%mod+1ll*val%mod)%mod)%=mod;
}
inline void pd(int k,int l,int r)
{
	int mid=l+r>>1;
	mth(ls,l,mid,tr[k].htg,tr[k].cnt);
	mth(rs,mid+1,r,tr[k].htg,tr[k].cnt);
	mt(ls,l,mid,tr[k].tg);
	mt(rs,mid+1,r,tr[k].tg);
	tr[k].tg=tr[k].htg=tr[k].cnt=0;
}
void upd(int k,int l,int r,int L,int R,int val)
{
	if(r<L || R<l)
		return;
	if(L<=l && r<=R)
	{
		mt(k,l,r,val);
		return;
	}
	int mid=l+r>>1;
	pd(k,l,r);
	upd(ls,l,mid,L,R,val);
	upd(rs,mid+1,r,L,R,val);
	pu(k);
}
int query(int k,int l,int r,int L,int R)
{
	if(r<L || R<l)
		return 0;
	if(L<=l && r<=R)
		return tr[k].hsm;
	int mid=l+r>>1;
	pd(k,l,r);
	return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R))%mod;
}
#undef ls
#undef rs
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
		cin>>s[i].l>>s[i].r>>s[i].x;
	for(int i=1;i<=q;i++)
	{
		int u,d,l,r;
		cin>>u>>d>>l>>r;
		ak[u-1].pb(ask(-1,l,r,i));
		ak[d].pb(ask(1,l,r,i));
	}
	for(int i=1;i<=m;i++)
	{
		upd(1,1,n,s[i].l,s[i].r,s[i].x);
		mth(1,1,n,0,1);
//		cout<<i<<":"<<query(1,1,n,2,6)<<'\n';
		for(auto v:ak[i])
			(ans[v.id]+=(v.f*query(1,1,n,v.l,v.r)+mod)%mod)%=mod;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
