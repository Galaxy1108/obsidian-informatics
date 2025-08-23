#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt,rp[10000005],p[10000005],n,f[10000005],sz[10000005],c[10000005],maxn[10000005];
long long a[10000005];
struct node{
	long long maxn;
	int id,l,r;
}tr[40000005];
vector<int> e[10000005],w[10000005];
void dfs(int x,int fa){
	sz[x]=1;	
	int maxx=0;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=fa){
			c[e[x][i]]=w[x][i];
			dfs(e[x][i],x);
			sz[x]+=sz[e[x][i]];
			if(sz[e[x][i]]>=maxx){
				maxx=sz[e[x][i]];
				maxn[x]=e[x][i];
			}
		}
	if(x!=1)
		a[x]=1ll*c[x]*sz[x];
}
void tree(int x,int fa){
	p[x]=++cnt;
	rp[cnt]=x;
	if(!maxn[x])
		return;
	tree(maxn[x],x);
	for(int i:e[x])
		if(i!=fa&&i!=maxn[x])
			tree(i,x);
}
void build(int p,int l,int r){
	if(l==r){
		tr[p].maxn=a[rp[l]];
		tr[p].id=l;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	if(tr[p<<1].maxn>tr[p<<1|1].maxn){
		tr[p].maxn=tr[p<<1].maxn;
		if(tr[p<<1].id)
			tr[p].id=tr[p<<1].id;
		else
			tr[p].l=1;
	}
	else if(tr[p<<1].maxn<tr[p<<1|1].maxn){
		tr[p].maxn=tr[p<<1|1].maxn;
		if(tr[p<<1|1].id)
			tr[p].id=tr[p<<1|1].id;
		else
			tr[p].r=1;
	}
	else{
		tr[p].maxn=tr[p<<1|1].maxn;
		tr[p].l=1;
		tr[p].r=1;
	}
}
void modify(int p,int l,int r,int x,long long y){
	if(l==r){
		tr[p].maxn=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		modify(p<<1,l,mid,x,y);
	else
		modify(p<<1|1,mid+1,r,x,y);
	tr[p].id=tr[p].l=tr[p].r=0;
	if(tr[p<<1].maxn>tr[p<<1|1].maxn){
		tr[p].maxn=tr[p<<1].maxn;
		if(tr[p<<1].id)
			tr[p].id=tr[p<<1].id;
		else
			tr[p].l=1;
	}
	else if(tr[p<<1].maxn<tr[p<<1|1].maxn){
		tr[p].maxn=tr[p<<1|1].maxn;
		if(tr[p<<1|1].id)
			tr[p].id=tr[p<<1|1].id;
		else
			tr[p].r=1;
	}
	else{
		tr[p].maxn=tr[p<<1|1].maxn;
		tr[p].l=1;
		tr[p].r=1;
	}
}
void check(int p,int l,int r){
	if(tr[p].id){
		f[tr[p].id]++;
		return;
	}
	int mid=(l+r)>>1;
	if(tr[p].l)
		check(p<<1,l,mid);
	if(tr[p].r)
		check(p<<1|1,mid+1,r);
}
void ans(int x,int fa){
	if(x!=1)
		modify(1,1,n,p[x],1ll*c[x]*(n-sz[x]));
	check(1,1,n);
	for(int i:e[x])
		if(i!=fa)
			ans(i,x);
	if(x!=1)
		modify(1,1,n,p[x],1ll*c[x]*sz[x]);
}
int main(){
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		int x,y;
		cin>>x>>y;
		e[i].push_back(x);
		e[x].push_back(i);
		w[x].push_back(y);
		w[i].push_back(y);
	}
	dfs(1,0);
	tree(1,0);
	a[1]=-1e18;
	build(1,1,n);
	ans(1,0);
	int num=f[2];
	for(int i=3;i<=n;i++)
		num^=f[i];
	cout<<num;
	return 0;
}

