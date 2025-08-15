#include<bits/stdc++.h>
#define B 320
#define mod 1000000009
using namespace std;
int n,m,Q,u,d,l,r,x,tot;
int bel[100010];
long long ans[100010];
struct Move{
	int l,r,x;
}mov[100010];
struct Ques{
	int l,r,tag,id;
};
struct Val_Node{
	long long val,his;
}val[100010];
struct Val_Block{
	int l,r;
	long long len,add,sum,hisadd,hissum,tag;
}b[100010];
vector<Ques> ask[100010];
void Pushdown(int x){
	for(int i=b[x].l;i<=b[x].r;++i){
		val[i].his=(val[i].his+b[x].hisadd+b[x].tag*val[i].val)%mod;
		val[i].val=(val[i].val+b[x].add)%mod;
	}
	b[x].add=b[x].hisadd=b[x].tag=0;
	return;
}
void Add(int l,int r,long long x){
	int L=bel[l],R=bel[r];
	if(L==R){
		Pushdown(L);
		for(int i=l;i<=r;++i){
			val[i].val=(val[i].val+x)%mod;
		}
		b[L].sum=(b[L].sum+1ll*(r-l+1)*x)%mod;
	}
	else{
		Pushdown(L);Pushdown(R);
		for(int i=l;i<=b[L].r;++i) val[i].val=(val[i].val+x)%mod;
		b[L].sum=(b[L].sum+1ll*(b[L].r-l+1)*x)%mod;
		for(int i=b[R].l;i<=r;++i) val[i].val=(val[i].val+x)%mod;
		b[R].sum=(b[R].sum+1ll*(r-b[R].l+1)*x)%mod;
		for(int i=L+1;i<=R-1;++i){
			b[i].add=(b[i].add+x)%mod;
			b[i].sum=(b[i].sum+b[i].len*x)%mod;
		}
	}
}
long long Ask(int l,int r,long long x){
	int L=bel[l],R=bel[r];
	long long ans=0;
	if(L==R){
		Pushdown(L);
		for(int i=l;i<=r;++i) ans+=val[i].his;
		ans%=mod;
		return x*ans%mod;
	}
	else{
		Pushdown(L);Pushdown(R);
		for(int i=l;i<=b[L].r;++i) ans+=val[i].his;
		for(int i=b[R].l;i<=r;++i) ans+=val[i].his;
		for(int i=L+1;i<=R-1;++i) ans+=b[i].hissum;
		ans%=mod;
		return x*ans%mod;
	}
}
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=m;++i){
		cin>>mov[i].l>>mov[i].r>>mov[i].x;
	}
	for(int i=1;i<=Q;++i){
		cin>>u>>d>>l>>r;
		ask[d].push_back((Ques){l,r,1,i});
		if(u>=2) ask[u-1].push_back((Ques){l,r,mod-1,i});
	}
	for(int i=1;i<=n;++i){
		if(i%B==1||i==1) bel[i]=bel[i-1]+1;
		else bel[i]=bel[i-1];
		if(b[bel[i]].l==0) b[bel[i]].l=i;
		b[bel[i]].r=i;
	}
	tot=bel[n];
	for(int i=1;i<=tot;++i) b[i].len=b[i].r-b[i].l+1;
	for(int k=1;k<=m;++k){
		l=mov[k].l,r=mov[k].r,x=mov[k].x;
		Add(l,r,x);
		for(int i=1;i<=tot;++i){
			b[i].hisadd=(b[i].hisadd+b[i].add)%mod;
			b[i].hissum=(b[i].hissum+b[i].sum)%mod;
			b[i].tag++;
		}
		for(auto v:ask[k]){
			ans[v.id]+=Ask(v.l,v.r,v.tag);
			if(ans[v.id]>=mod) ans[v.id]-=mod;
			if(ans[v.id]<0) ans[v.id]+=mod;
		}
	}
	for(int i=1;i<=Q;++i) cout<<ans[i]<<'\n';
	return 0;
}
