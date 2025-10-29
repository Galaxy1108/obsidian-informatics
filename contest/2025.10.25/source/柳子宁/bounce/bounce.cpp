#include<bits/stdc++.h>
using namespace std;
int n,Q,op,x;
int f[21][1000010],usd[21];
namespace Segtree{
	struct Node{
		int l,r;
		int sum;
	}tree[4000010];
	void Build(const int p,const int l,const int r){
		tree[p].l=l,tree[p].r=r;
		if(l==r) return tree[p].sum=1,void();
		const int mid=(l+r)>>1;
		Build(p<<1,l,mid),Build(p<<1|1,mid+1,r);
		tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
		return;
	}
	void Modify(const int p,const int l,const int r){
		if(l<=tree[p].l&&tree[p].r<=r) return tree[p].sum=0,void();
		const int mid=(tree[p].l+tree[p].r)>>1;
		if(l<=mid) Modify(p<<1,l,r);
		if(r>mid) Modify(p<<1|1,l,r);
		tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
		return;
	}
	int Query(const int p,const int l,const int r,const int val){
		if(tree[p].l==tree[p].r) return tree[p].l;
		if(tree[p<<1].sum>=val) return Query(p<<1,l,r,val);
		return Query(p<<1|1,l,r,val-tree[p<<1].sum);
	}
}
int main()
{
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>Q;
	for(int m=2;m<=20;++m){
		f[m][1]=1;
		for(int i=2;i<=n;++i){
			int x=i-((i-1)/m+1);
			int y=x-f[m][x]+1;
			f[m][i]=y+((y-1)/(m-1)+1);
		}
	}
	Segtree::Build(1,1,n);
	for(int i=1;i<=Q;++i){
		cin>>op>>x;
		if(op==1){
			if(usd[x]) continue;
			usd[x]=1;
			for(int k=1;k<=n;k+=x) Segtree::Modify(1,k,k);
		}
		if(op==2){
			for(int k=1;k<=Segtree::tree[1].sum;k+=x-1){
				int y=Segtree::Query(1,1,n,k);
				Segtree::Modify(1,y,y);
			}
		}
		if(op==3){
			int N=Segtree::tree[1].sum;
			if(N) cout<<Segtree::Query(1,1,n,f[x][N])<<'\n';
			else cout<<"-1\n";
		}
	}
	return 0;
}
