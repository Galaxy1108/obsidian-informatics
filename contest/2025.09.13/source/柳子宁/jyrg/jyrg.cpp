#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int T,n,Tag;
int id[100010],pl[100010];
long long a[100010],ans;
pair<long long,int> b[100010];

struct Segtree{
	int l,r;
	long long val,tag;
}tree[400010];
void Pushdown(const int p){
	tree[p<<1].val+=tree[p].tag;
	tree[p<<1|1].val+=tree[p].tag;
	tree[p<<1].tag+=tree[p].tag;
	tree[p<<1|1].tag+=tree[p].tag;
	tree[p].tag=0;
	return;
}
void Build(const int p,const int l,const int r){
	tree[p].l=l,tree[p].r=r,tree[p].tag=0;
	if(l==r) return tree[p].val=a[l]+l,void();
	const int mid=(l+r)>>1;
	Build(p<<1,l,mid),Build(p<<1|1,mid+1,r);
	tree[p].val=max(tree[p<<1].val,tree[p<<1|1].val);
	return;
}
void Modify(const int p,const int l,const int r,const long long tag){
	if(l<=tree[p].l&&tree[p].r<=r){
		tree[p].val+=tag;
		tree[p].tag+=tag;
		return;
	}
	if(tree[p].tag) Pushdown(p);
	const int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid) Modify(p<<1,l,r,tag);
	if(r>mid) Modify(p<<1|1,l,r,tag);
	tree[p].val=max(tree[p<<1].val,tree[p<<1|1].val);
	return;
}
long long Query(const int p,const int l,const int r){
	if(l<=tree[p].l&&tree[p].r<=r) return tree[p].val;
	if(tree[p].tag) Pushdown(p);
	const int mid=(tree[p].l+tree[p].r)>>1;
	long long ans=-inf;
	if(l<=mid) ans=max(ans,Query(p<<1,l,r));
	if(r>mid) ans=max(ans,Query(p<<1|1,l,r));
	return ans;
}

int main()
{
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			b[i]=make_pair(a[i]-i,i);
		}
		sort(b+1,b+n+1),Tag=1;
		for(int i=1;i<n;++i){
			if(b[i].first==b[i+1].first) Tag=0;
		}
		if(!Tag) {cout<<"-1\n";continue;}

		for(int i=1;i<=n;++i){
			id[b[i].second]=n-i+1;
			pl[n-i+1]=b[i].second;
		}
		Build(1,1,n);

		for(int i=n;i>=1;--i){
			int p=pl[i];
			ans=max(ans,a[p]-p-1+Query(1,p+1,n));
			Modify(1,p,p,-inf);
			Modify(1,p+1,n,-2);
		}
		
		// for(int i=n;i>=1;--i){
		// 	for(int j=1;j<i;++j){
		// 		if(id[j]==i){
		// 			swap(id[j],id[j+1]);
		// 			swap(a[j],a[j+1]);
		// 			--a[j],++a[j+1];
		// 			ans=max(ans,a[j]+a[j+1]);
		// 		}
		// 	}
		// }
		memset(tree,0,sizeof(tree));
		cout<<ans<<'\n';
	}
	return 0;
}
