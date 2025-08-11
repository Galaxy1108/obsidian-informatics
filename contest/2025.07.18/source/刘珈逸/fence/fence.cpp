#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=1e9+7;
int calc(int x){
	return x*(x+1)/2%mod;
}
struct Node{
	int mx,se,cnt,tag,sum;
	void upd(int v){
		if(mx<=v)return;
		sum=(sum+cnt*calc(v)-cnt*calc(mx))%mod;
		tag=v;mx=v;
	}
}t[N<<2];
void pushup(int p){
	t[p].sum=(t[p<<1].sum+t[p<<1|1].sum)%mod;
	if(t[p<<1].mx==t[p<<1|1].mx){
		t[p].mx=t[p<<1].mx;t[p].cnt=t[p<<1].cnt+t[p<<1|1].cnt;
		t[p].se=max(t[p<<1].se,t[p<<1|1].se);
	}else if(t[p<<1].mx>t[p<<1|1].mx){
		t[p].mx=t[p<<1].mx;t[p].cnt=t[p<<1].cnt;
		t[p].se=max(t[p<<1].se,t[p<<1|1].mx); 
	}else{
		t[p].mx=t[p<<1|1].mx;t[p].cnt=t[p<<1|1].cnt;
		t[p].se=max(t[p<<1].mx,t[p<<1|1].se);
	}t[p].cnt%=mod;
}
void pushdown(int p){
	if(t[p].tag){
		t[p<<1].upd(t[p].tag);
		t[p<<1|1].upd(t[p].tag);
		t[p].tag=0;
	}
}
void change(int p,int l,int r,int k,int v1,int v2){
	if(l==r){
		t[p].mx=v1;t[p].cnt=v2;t[p].sum=v2*calc(v1)%mod;
		return;
	}int mid=l+r>>1;pushdown(p);
	if(k<=mid)change(p<<1,l,mid,k,v1,v2);
	else change(p<<1|1,mid+1,r,k,v1,v2);
	pushup(p);
}
void chg(int p,int v){
	if(t[p].mx<=v)return;
	if(t[p].se<v){
		t[p].upd(v);
		return;
	}chg(p<<1,v);chg(p<<1|1,v);
	pushup(p);
}
int n,h[N],w[N],ans;
signed main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",h+i);
	for(int i=1;i<=n;i++)scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		chg(1,h[i]);
		ans+=t[1].sum*w[i]%mod;ans%=mod;
		ans+=calc(w[i])*calc(h[i])%mod;ans%=mod;
		change(1,1,n,i,h[i],w[i]);
	}printf("%lld\n",(ans+mod)%mod);
	return 0;
}
/*
扫描线
即为所有位置的最小值的C(x,2)的和 
线段树碾过去 
*/
