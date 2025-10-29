#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mx=200005;
int f[mx],ff[mx],g[mx],gg[mx],sum[mx];
int raw[mx],n,ans=0x3f3f3f3f3f3fll;
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&raw[i]),sum[i]=sum[i-1]+raw[i];
	sum[n+1]=sum[n];
	for(int i=1;i<=n;i++){
		f[i]=min(f[i-1]+((raw[i]>2)?(raw[i]%2):(2-raw[i])),sum[i-1]+raw[i]%2);
		ff[i]=min(abs(raw[i]-1)%2+ff[i-1],f[i]);
	} 
	for(int i=n;i>=1;i--){
		g[i]=min(g[i+1]+((raw[i]>2)?(raw[i]%2):(2-raw[i])),sum[n]-sum[i]+raw[i]%2);
		gg[i]=min(abs(raw[i]-1)%2+gg[i+1],g[i]);
	}
	for(int i=0;i<=n;i++)ans=min(ans,min(f[i]+gg[i+1],ff[i]+g[i+1]));
	cout<<ans<<endl;
	return 0;
}
