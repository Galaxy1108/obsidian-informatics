#include <bits/stdc++.h>
using namespace std;
long long len[114514],tag[114514];
const long long mod=1e9+7;
struct edit{
	int l,r,x;
}a[114514];
struct Qry{
	int u,d,l,r;
	long long resr,resl;
}b[114514];
struct qry{
	int vr,l,r,w,id;
}c[114514<<1];
bool cmp(qry p,qry q){
	if(p.vr!=q.vr) return p.vr<q.vr;
	else return p.l<q.l;
}
struct SegTree{
	long long sum;
}t[114514<<2];
inline void pushup(int now){
	t[now].sum=(t[now<<1].sum+t[now<<1|1].sum)%mod;
}
inline void build(int now,int l,int r){
	len[now]=r-l+1;
	if(len[now]==1) return;
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
}
inline void pushdown(int now){
	if(tag[now]){
		tag[now<<1]=(tag[now<<1]+tag[now])%mod;
		tag[now<<1|1]=(tag[now<<1|1]+tag[now])%mod;
		t[now<<1].sum=((t[now<<1].sum+(tag[now]*len[now<<1]%mod+mod)%mod)%mod+mod)%mod;
		t[now<<1|1].sum=((t[now<<1|1].sum+(tag[now]*len[now<<1|1]%mod+mod)%mod)%mod+mod)%mod;
		tag[now]=0;
	}
}
inline void add(int now,int l,int r,int L,int R,long long k){
	if(L<=l&&r<=R){
		tag[now]=(tag[now]+k)%mod;
		t[now].sum=((t[now].sum+(len[now]*k%mod+mod)%mod)%mod+mod)%mod;
		return;
	}
	pushdown(now);
	int mid=(l+r)>>1;
	if(L<=mid) add(now<<1,l,mid,L,R,k);
	if(R>mid) add(now<<1|1,mid+1,r,L,R,k);
	pushup(now);
}
inline long long query(int now,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return t[now].sum%mod;
	}
	pushdown(now);
	long long mid=(l+r)>>1,res=0;
	if(L<=mid) res=((res+query(now<<1,l,mid,L,R))%mod+mod)%mod;
	if(R>mid) res=((res+query(now<<1|1,mid+1,r,L,R))%mod+mod)%mod;
	return res;
}
int n,m,Q;
int main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>Q;
	build(1,1,n);
	for(int i=1;i<=m;++i){
		cin>>a[i].l>>a[i].r>>a[i].x;
	}
	for(int i=1;i<=Q;++i){
		cin>>b[i].u>>b[i].d>>b[i].l>>b[i].r;
		c[2*i-1].id=i;
		c[2*i-1].l=c[2*i].l=b[i].l;
		c[2*i-1].r=c[2*i].r=b[i].r;
		c[2*i-1].w=-1;
		c[2*i-1].vr=b[i].u-1;
		c[2*i].id=i;
		c[2*i].w=1;
		c[2*i].vr=b[i].d;
	}
	sort(c+1,c+2*Q+1,cmp);
	int now=1;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=i;++j) add(1,1,n,a[j].l,a[j].r,a[j].x);
		for(;c[now].vr<=i&&now<=2*Q;++now){
			if(c[now].vr==i){
				long long rs=query(1,1,n,c[now].l,c[now].r);
				//cout<<c[now].id<<"_"<<c[now].l<<"_"<<c[now].r<<"_"<<c[now].vr<<"_"<<c[now].w<<endl;
				//cout<<rs<<endl;
				if(c[now].w>0){
					b[c[now].id].resr=rs;
				}
				else{
					b[c[now].id].resl=rs;
				}
			}
		}
	}
	for(int i=1;i<=Q;++i){
		//cout<<b[i].resl<<"_"<<b[i].resr<<endl;
		cout<<(b[i].resr-b[i].resl%mod+mod)%mod<<endl;
	}
	return 0;
}
