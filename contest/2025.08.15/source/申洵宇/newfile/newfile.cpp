#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
#define N 100005
int n,m,q;
class d_seg_tree{
#define ls(x) (tree[x].ls)
#define rs(x) (tree[x].rs)
#define val(x) (tree[x].val)
#define tag(x) (tree[x].tag)
#define mid ((tl+tr)>>1)
public:
	struct node{
		int ls=0,rs=0;
		long long val=0,tag=0;
	}tree[N<<6];
	int root[N]={0},cnt=0;
	int newnode(){
		return ++cnt;
	}
	void pushdown(int id,int tl,int tr){
		if(tag(id)!=0){
			val(ls(id))=(val(ls(id))+1ll*(tr-mid)*tag(id)%MOD)%MOD;
			val(rs(id))=(val(rs(id))+1ll*(mid-tl+1)*tag(id)%MOD)%MOD;
			tag(ls(id))=(tag(ls(id))+tag(id))%MOD;
			tag(rs(id))=(tag(rs(id))+tag(id))%MOD;
			tag(id)=0;
		}
	}
	void pushup(int id){
		val(id)=(val(ls(id))+val(rs(id)))%MOD;
	}
	void add(int tl,int tr,int &nid,int oid,int l,int r,long long k){
		if(!nid)nid=newnode();
		tree[nid]=tree[oid];
		if(tl>=l&&tr<=r){
			val(nid)=(val(nid)+1ll*(tr-tl+1ll)*k%MOD)%MOD;
			tag(nid)=(tag(nid)+k)%MOD;
			return ;
		}
		if(tl==tr)return ;
		ls(nid)=newnode();
		rs(nid)=newnode();
		tree[ls(nid)]=tree[ls(oid)];
		tree[rs(nid)]=tree[rs(oid)];
		pushdown(nid,tl,tr);
		if(l<=mid)add(tl,mid,ls(nid),ls(oid),l,r,k);
		if(r>mid)add(mid+1,tr,rs(nid),rs(oid),l,r,k);
		pushup(nid);
	}
	long long query(int tl,int tr,int id,int l,int r){
		if(!id)return 0;
		if(tl>=l&&tr<=r){
			return val(id);
		}
		if(tl==tr)return 0;
		static int tls,trs;
		tls=ls(id);
		trs=rs(id);
		ls(id)=newnode();
		rs(id)=newnode();
		tree[ls(id)]=tree[tls];
		tree[rs(id)]=tree[trs];
		pushdown(id,tl,tr);
		if(r<=mid)return query(tl,mid,ls(id),l,r);
		else if(l>mid)return query(mid+1,tr,rs(id),l,r);
		else return (query(tl,mid,ls(id),l,r)+query(mid+1,tr,rs(id),l,r))%MOD;
	}
#undef ls
#undef rs
#undef val
#undef tag
#undef mid
}st;
int main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	int u,d,l,r,x;
	for(int i=1;i<=m;i++){
		cin>>l>>r>>x;
		st.add(1,n,st.root[i],st.root[i-1],l,r,x);
	}
	long long ans;
	while(q--){
		cin>>u>>d>>l>>r;
		ans=0;
		for(int i=u;i<=d;i++){
			ans=(ans+st.query(1,n,st.root[i],l,r))%MOD;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

