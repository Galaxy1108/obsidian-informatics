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
cs int N=505,mod=998244353;
il int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
int c[N][N];
il void init(int n){
	c[0][0]=1;
	for(ri int i=1;i<=n;++i){
		for(ri int j=1;j<=i;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}
signed main(){	
	int n,x;
	n=rd(),x=rd();
	init(n);
	int ans=((qpow(x,n)-n*qpow(x-1,n-1)%mod)%mod+mod)%mod;
	for(ri int i=n+1;i<=x;++i){
		for(ri int j=2;j<=n;++j){
			ans+=c[n][j]*qpow(x-1,n-j)%mod;
			ans%=mod;
		}
		ans+=n*qpow(x-n,n-1)%mod;
		ans%=mod;
	}
	wt(ans);
	return 0;
}
