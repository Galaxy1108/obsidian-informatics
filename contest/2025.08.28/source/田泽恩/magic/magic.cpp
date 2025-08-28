#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[250114],b[250114],c[250114],n,m;
struct mtrx{
	long long m[4][4],r,c;
}o[7],tag[250114<<2],t[250114<<2],mpt,mpt2,ans;
inline mtrx operator *(mtrx x,mtrx y){
	mtrx z=mpt;
	z.r=x.r;
	z.c=x.c;
	for(int i=0;i<z.r;++i){
		for(int j=0;j<z.c;++j){
			for(int k=0;k<x.c;++k) z.m[i][j]=(z.m[i][j]+x.m[i][k]*y.m[k][j]%mod)%mod;
		}
	}
	return z;
}
inline mtrx pushup(mtrx lson,mtrx rson){
	mtrx res;
	res.r=lson.r;
	res.c=rson.c;
	res.m[0][0]=(lson.m[0][0]+rson.m[0][0])%mod;
	res.m[0][1]=(lson.m[0][1]+rson.m[0][1])%mod;
	res.m[0][2]=(lson.m[0][2]+rson.m[0][2])%mod;
	res.m[0][3]=(lson.m[0][3]+rson.m[0][3])%mod;
	return res;
}
inline void pushdown(int now){
	tag[now<<1]=tag[now<<1]*tag[now];
	t[now<<1]=t[now<<1]*tag[now];
	tag[now<<1|1]=tag[now<<1|1]*tag[now];
	t[now<<1|1]=t[now<<1|1]*tag[now];
	tag[now]=o[6];
}
inline void build(int now,int l,int r){
	tag[now]=o[6];
	if(l==r){
		t[now].r=1;
		t[now].c=4;
		t[now].m[0][0]=a[l];
		t[now].m[0][1]=b[l];
		t[now].m[0][2]=c[l];
		t[now].m[0][3]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	t[now]=pushup(t[now<<1],t[now<<1|1]);
}
inline void edit(int now,int l,int r,int L,int R,mtrx M){
	if(L<=l&&r<=R){
		tag[now]=tag[now]*M;
		t[now]=t[now]*M;
		return;
	}
	pushdown(now);
	int mid=(l+r)>>1;
	if(L<=mid) edit(now<<1,l,mid,L,R,M);
	if(R>mid) edit(now<<1|1,mid+1,r,L,R,M);
	t[now]=pushup(t[now<<1],t[now<<1|1]);
}
inline mtrx query(int now,int l,int r,int L,int R){
	if(r<L||R<l) return mpt2;
	if(L<=l&&r<=R) return t[now];
	int mid=(l+r)>>1;
	pushdown(now);
	return pushup(query(now<<1,l,mid,L,R),query(now<<1|1,mid+1,r,L,R));
}
inline void init(){
	for(register int i=0;i<7;++i){
		o[i].r=o[i].c=4;
		for(int j=0;j<4;++j) o[i].m[j][j]=1;
	}
	mpt2.r=1;
	mpt2.c=4;
	o[0].m[1][0]=1;
	o[1].m[2][1]=1;
	o[2].m[0][2]=1;
	o[5].m[2][2]=0;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>n;
	for(register int i=1;i<=n;++i) cin>>a[i]>>b[i]>>c[i];
	build(1,1,n);
	cin>>m;
	while(m--){
		int opt,l,r,v;
		cin>>opt>>l>>r;
		if(opt==1){
			edit(1,1,n,l,r,o[0]);
		}
		else if(opt==2){
			edit(1,1,n,l,r,o[1]);
		}
		else if(opt==3){
			edit(1,1,n,l,r,o[2]);
		}
		else if(opt==4){
			cin>>v;
			o[3].m[3][0]=v;
			edit(1,1,n,l,r,o[3]);
		}
		else if(opt==5){
			cin>>v;
			o[4].m[1][1]=v;
			edit(1,1,n,l,r,o[4]);
		}
		else if(opt==6){
			cin>>v;
			o[5].m[3][2]=v;
			edit(1,1,n,l,r,o[5]);
		}
		else{
			ans=query(1,1,n,l,r);
			cout<<ans.m[0][0]<<" "<<ans.m[0][1]<<" "<<ans.m[0][2]<<endl;
		}
	}
	return 0;
} 
