#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n;
long long a[100001],b[100001],sum[100001],cnt=0;
long long t(long long x,long long y){
//	cout<<"x="<<x<<" y="<<y<<" ans="<<(x*(x+1)/2%mod)*(y*(y+1)/2%mod)%mod<<endl;
	return (x*(x+1)/2%mod)*(y*(y+1)/2%mod)%mod;
}
struct node{
	long long l,r,val;
}g[400001];
void pushup(long long p){
	if(a[g[p*2].val]<=a[g[p*2+1].val]) g[p].val=g[p*2].val;
	else g[p].val=g[p*2+1].val;
}
void build(long long p,long long l,long long r){
	g[p].l=l,g[p].r=r;
	if(l==r){
		g[p].val=l;
		return;
	}
	long long mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}
long long query(long long p,long long l,long long r){
	//cout<<p<<" "<<g[p].l<<" "<<g[p].r<<" "<<l<<" "<<r<<" "<<g[p].val<<endl;
	if(l<=g[p].l&&r>=g[p].r){
		return g[p].val;
	}
	long long mid=(g[p].l+g[p].r)/2,ans=0,ans1=0;
	if(l<=mid){
		ans1=query(p*2,l,r);
		if(a[ans]==0||a[ans]>a[ans1]) ans=ans1;
	}
	if(r>mid){
		ans1=query(p*2+1,l,r);
		if(a[ans]==0||a[ans]>a[ans1]) ans=ans1;
	} 
	return ans;
}
long long f(long long l,long long r){
	cnt++;
	//cout<<l<<" "<<r<<endl;
	if(l==r){
		return t(a[l],b[r])%mod;
	}
	long long mi=l,ll=0,rr=0,ans=0;
	mi=query(1,l,r);
	//cout<<l<<" "<<r<<" "<<mi<<endl;
	if(mi>l) ll=f(l,mi-1);
	if(mi<r) rr=f(mi+1,r);
	ans=(ll+rr)%mod+((t((sum[r]-sum[l-1]+mod)%mod,a[mi])+mod-t((sum[mi-1]-sum[l-1]+mod)%mod,a[mi]))%mod+mod-t((sum[r]-sum[mi]+mod)%mod,a[mi]))%mod;
//	cout<<"l="<<l<<" r="<<r<<" mi="<<mi<<" ll="<<ll<<" rr="<<rr<<" ans="<<ans<<endl;
	return ans%mod;
}
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(long long i=1;i<=n;i++){
		cin>>b[i];
		sum[i]=sum[i-1]+b[i];
		sum[i]%=mod;
	}
	build(1,1,n);
//	cout<<endl;
	cout<<f(1,n)<<endl;
	
	return 0;
} 
/*
2 
1 2 
1 2
*/
