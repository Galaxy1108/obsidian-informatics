#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,Q;
long long a[310][310],f[310][310];
long long ans[200010];
struct Segtree{
	int l,r;
	vector<int> id;
}tree[2010];
struct Qry{
	int x,y,p,q;
}qry[200010];
void Build(const int p,const int l,const int r){
	if(l>r) return;
	tree[p].l=l,tree[p].r=r;
	const int mid=(l+r)>>1;
	Build(p<<1,l,mid-1);Build(p<<1|1,mid+1,r);
	return;
}
void Modify(const int p,const int l,const int r,const int id){
	const int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid&&mid<=r){
		tree[p].id.push_back(id);
		return;
	}
	if(r<=mid) Modify(p<<1,l,r,id);
	else Modify(p<<1|1,l,r,id);
	return;
}
void Query(const int p,const int l,const int r){
	if(l>r) return;
	const int mid=(tree[p].l+tree[p].r)>>1;
	for(int k=1;k<=n;++k){
		memset(f,0x3f,sizeof(f));
		f[mid][k]=a[mid][k];
		for(int i=mid;i<=tree[p].r;++i){
			for(int j=k;j<=n;++j){
				if(i==mid&&j==k) continue;
				f[i][j]=min(f[i][j-1],f[i-1][j])+a[i][j];
			}
		}
		for(int i=mid;i>=tree[p].l;--i){
			for(int j=k;j>=1;--j){
				if(i==mid&&j==k) continue;
				f[i][j]=min(f[i][j+1],f[i+1][j])+a[i][j];
			}
		}
		for(auto v:tree[p].id){
			if(!(qry[v].y<=k&&k<=qry[v].q)) continue;
			ans[v]=min(ans[v],f[qry[v].x][qry[v].y]+f[qry[v].p][qry[v].q]-a[mid][k]);
		}
	}
	Query(p<<1,l,mid-1);Query(p<<1|1,mid+1,r);
	return;
}
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	Build(1,1,n);
	for(int i=1;i<=Q;++i){
		cin>>qry[i].x>>qry[i].p>>qry[i].y>>qry[i].q;
		Modify(1,qry[i].x,qry[i].p,i);
		ans[i]=inf;
	}
	Query(1,1,n);
	for(int i=1;i<=Q;++i) cout<<ans[i]<<'\n';
	return 0;
}
