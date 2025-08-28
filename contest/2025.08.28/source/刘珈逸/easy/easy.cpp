#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int,int>pii;
const int N=2e5+5,M=500;
int n,m,a[N],tim;
bool del[N];
namespace solve1{//区间加等差 
	int siz[N<<2],cnt[N<<2],sum[N<<2];
	pii rv[N<<2],lv[N<<2];
	int tk[N<<2],tb[N<<2];
	void pushup(int p){
		siz[p]=siz[p<<1]+siz[p<<1|1];
		cnt[p]=cnt[p<<1]+cnt[p<<1|1];
		sum[p]=sum[p<<1]+sum[p<<1|1];
		if(rv[p<<1|1].se)rv[p]=rv[p<<1|1];
		else rv[p]=rv[p<<1];
		if(lv[p<<1].se)lv[p]=lv[p<<1];
		else lv[p]=lv[p<<1|1];
	}
	int V=0x3f3f3f3f3f3f3f3f; 
	void upd(int p,int k,int b){
		tk[p]=k;tb[p]=b;
		sum[p]=k*siz[p]+b*cnt[p];
		rv[p].fi=b+k*rv[p].se;
		lv[p].fi=b+k*lv[p].se;
	}
	void pushdown(int p){
		if(tk[p]!=1){
			upd(p<<1,tk[p],tb[p]);
			upd(p<<1|1,tk[p],tb[p]);
			tk[p]=1;
		}
	}
	void change(int p,int v){
		V=min(V,v);
		if(!lv[p].se)return;
		if(lv[p].fi+tim*lv[p].se>=v){
			upd(p,-tim,v);
			return;
		}
		if(rv[p].fi+tim*rv[p].se<=v)return;
		pushdown(p);
		change(p<<1,v);
		change(p<<1|1,v);
		pushup(p);
	}
	void insert(int p,int l,int r,int k,int v){
		if(l==r){
			lv[p]=rv[p]={v-tim*l,l};
			cnt[p]=1;
			siz[p]=l;
			sum[p]=v-tim*l;
			return;
		}int mid=l+r>>1;pushdown(p);
		if(k<=mid)insert(p<<1,l,mid,k,v);
		else insert(p<<1|1,mid+1,r,k,v);
		pushup(p);
	}
	int query(int p,int l,int r,int l1,int r1){
		if(l1<=l&&r<=r1)return sum[p]+siz[p]*tim;
		int mid=l+r>>1,ans=0;pushdown(p);
		if(l1<=mid)ans+=query(p<<1,l,mid,l1,r1);
		if(r1>mid)ans+=query(p<<1|1,mid+1,r,l1,r1);
		return ans;
	}
	void init(){
		memset(sum,0,sizeof(sum));
		memset(siz,0,sizeof(siz));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n*4;i++)tk[i]=1;
	}
}
namespace solve2{
	#define x(u) u
	#define y(u) a[u]
	struct BIT{
		int bit[N];
		BIT(){
			memset(bit,0,sizeof(bit)); 
		} 
		void chg(int p,int v){
			while(p<=n)bit[p]+=v,p+=p&-p;
		}
		int qry(int p){
			int ans=0;
			while(p)ans+=bit[p],p&=p-1;
			return ans;
		}
	}t1,t2;
	int L[M],R[M],pos[N],B,tot;
	int h[M],t[M],q[M][M];
	int getsum(int l,int r){
		return (t1.qry(r)-t1.qry(l-1))*tim+(t2.qry(r)-t2.qry(l-1));
	}
	int calc(int pos){
		return x(pos)*tim+y(pos);
	}
	long double get(int u,int v){
		return (long double)(y(u)-y(v))/(x(u)-x(v));
	}
	void rebuild(int id){
		h[id]=1,t[id]=0;
		for(int i=L[id];i<=R[id];i++)if(!del[i]){
			while(t[id]>=2&&get(q[id][t[id]-1],q[id][t[id]])<get(q[id][t[id]],i))t[id]--;
			q[id][++t[id]]=i;
		}
	}
	void getmx(int id){
		while(h[id]+1<=t[id]&&calc(q[id][h[id]])<=calc(q[id][h[id]+1]))h[id]++;
	}
	void change(int v){
		for(int i=1;i<=tot;i++){
			while(1){
				getmx(i);
				if(h[i]>t[i]||calc(q[i][h[i]])<v)break;
				int id=q[i][h[i]];del[id]=1;t1.chg(id,-x(id));t2.chg(id,-y(id));
				solve1::insert(1,1,n,id,v);
				rebuild(i);
			}
		}
	}
	void init(){
		B=sqrt(n);
		for(int i=1;i<=n;i++)t1.chg(i,x(i)),t2.chg(i,y(i));
		for(int i=1;i<=n;i++)pos[i]=(i-1)/B+1;tot=pos[n];
		for(int i=1;i<=tot;i++)L[i]=(i-1)*B+1,R[i]=i*B;R[tot]=n;
		for(int i=1;i<=tot;i++)rebuild(i);
	}
	#undef x
	#undef y
}
signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	solve2::init();solve1::init();
	while(m--){
		int op;scanf("%lld",&op);
		if(op==1){
			int v;scanf("%lld",&v);
			solve1::change(1,v);solve2::change(v);
		}
		if(op==2){
			tim++;
		}
		if(op==3){
			int l,r;scanf("%lld%lld",&l,&r);
			int ans=0;
			printf("%lld\n",solve1::query(1,1,n,l,r)+solve2::getsum(l,r));
		}
	}
	return 0;
}
/*
把所有进行过1操作的位置提出来
分块,每个块内维护凸包 
*/
