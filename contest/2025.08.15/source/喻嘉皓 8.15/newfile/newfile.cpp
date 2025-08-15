#include<bits/stdc++.h>
#define mod 1000000009
#define ll long long
#define ls(p) (p<<1)
#define rs(p) ((p<<1)+1)
#define mid (l+(r-l)/2)
#define pb push_back
using namespace std;
const int N=100010;
int n,m,q;
struct node{
	int l,r,len;
	int sum,laz;
}d[4*N];
void build(int p,int l,int r){
	d[p].l=l; d[p].r=r; d[p].len=r-l+1;
	if(l==r) return;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
void down(int p){
	if(d[p].laz){
		d[ls(p)].laz+=d[p].laz; d[ls(p)].laz%=mod;
		d[rs(p)].laz+=d[p].laz; d[rs(p)].laz%=mod;
		d[ls(p)].sum+=d[ls(p)].len*d[p].laz; d[ls(p)].sum%=mod;
		d[rs(p)].sum+=d[rs(p)].len*d[p].laz; d[rs(p)].sum%=mod;
		d[p].laz=0;
	}
}
void up(int p){
	d[p].sum=d[ls(p)].sum+d[rs(p)].sum;
}
void upd(int p,int l,int r,int s,int t,int w){
	if(s<=l&&r<=t){
		d[p].sum+=(r-l+1)*w; d[p].sum%=mod;
		d[p].laz+=w; d[p].laz%=mod;
		return;
	}
	down(p);
	if(s<=mid) upd(ls(p),l,mid,s,t,w);
	if(t>mid) upd(rs(p),mid+1,r,s,t,w);
	up(p);
}
ll getp(int p,int l,int r,int s,int t){
	if(s<=l&&r<=t) return d[p].sum;
	down(p);
	ll sum=0;
	if(s<=mid) sum=(sum+getp(ls(p),l,mid,s,t))%mod;
	if(t>mid) sum=(sum+getp(rs(p),mid+1,r,s,t))%mod;
	up(p);
	return sum;
}
struct Oper{
	int l,r,x;
}op[N];
struct Qus{
	int u,d,l,r;
}qus[N];
struct Pair{
	int l,r,id,op;
};
struct Ans{
	ll ansl,ansr;
}ans[N];
vector<Pair> g[N];
int now[N],Sum[N];
void solve(){
	build(1,1,n);
	for(int i=1;i<=m;i++){
//		for(int j=1;j<=i;j++){
//			upd(1,1,n,op[j].l,op[j].r,op[j].x);	
//		}
		for(int j=op[i].l;j<=op[i].r;j++){
			now[j]+=op[i].x; now[j]%=mod;
		}
		for(int j=1;j<=n;j++){
			Sum[j]+=now[j]; Sum[j]%=mod;
		}
		for(Pair to:g[i]){
//			if(to.op==1) ans[to.id].ansl=getp(1,1,n,to.l,to.r);
//			else ans[to.id].ansr=getp(1,1,n,to.l,to.r);	
			ll res=0;
			for(int j=to.l;j<=to.r;j++){
				res=(res+Sum[j])%mod;
			}
			if(to.op==1) ans[to.id].ansl=res;
			else ans[to.id].ansr=res;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<((ans[i].ansr-ans[i].ansl)%mod+mod)%mod<<'\n';
	}
}
int main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
//	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=1;i<=m;++i){
		cin>>op[i].l>>op[i].r>>op[i].x;
	} 
	for(int i=1;i<=q;i++){
		cin>>qus[i].u>>qus[i].d>>qus[i].l>>qus[i].r;
		g[max(0,qus[i].u-1)].pb({qus[i].l,qus[i].r,i,1});
		g[qus[i].d].pb({qus[i].l,qus[i].r,i,2});
	}
	solve();
	return 0;
}

