#include<bits/stdc++.h>
#define il inline
#define cs const
#define ri register
#define int long long
#define F(s) freopen(#s".in","r",stdin),freopen(#s".out","w",stdout);
using namespace std;
namespace Q{
	il int rd(){
		ri int x=0,f=1;ri char c=getchar();
		while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
		while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
		return x*f;
	}
	il void wt(int x){
		if(x<0) x=-x,putchar('-');
		if(x>=10) wt(x/10);
		return putchar(x%10+48),void();
	}
}
using namespace Q;
cs int mod=998244353,N=505;
int n,x,as; 
int a[N];
il bool ck(int c){
	int t=0;
	while(c>1){
		int cnt=0;
		t+=c-1;
		for(ri int i=1;i<=n;++i){
			cnt+=(a[i]-t>0);
		}
		c=cnt;		
	}
	return (c==0);
}
il void dfs(int t,int c){
	if(t>n){
		as+=ck(c);
		as%=mod;
		return;
	}
	for(ri int i=1;i<=x;++i){
		a[t]=i;
		dfs(t+1,c+(i!=0));
	}
}
il int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
signed main(){
	F(arena)
	n=rd(),x=rd();
	if(n==2) return wt(x),0;
	if(x==1) return putchar('1'),0;
	if(n>x) return wt(qpow(x,n)),0;
	if(n==x){
		as=(qpow(x,n)-n*qpow(x-1,n-1)%mod)%mod;
		wt((as+mod)%mod);
		return 0;
	}
	if(n==3){
		for(ri int i=1,j=1;i<=x;++i){
			as+=j,j+=(i&1)*6,j%=mod,as%=mod;
		}
		wt(as);
		return 0;
	}
	dfs(1,0);
	wt(as);
	return 0;
}
