#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define fINF 0xc0c0c0c0c0c0c0c0ll
int n;
long long a[N][2],f[N],g[N],h[N]/*,sum[N]*/;
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
//		sum[i]=sum[i-1]+a[i][1];
	}
	f[0]=fINF;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],0ll)+a[i][0]+a[i][1];
	}
	g[n+1]=fINF;
	for(int i=n;i>=1;i--){
		g[i]=max(g[i+1],0ll)+a[i][0]+a[i][1];
	}
	h[1]=fINF;
	for(int i=2;i<=n;i++){
		h[i]=max(f[i-1],h[i-1])+a[i][1];
	}
	long long ans=fINF;
	for(int i=2;i<n;i++){
		ans=max(ans,h[i]+g[i+1]);
	}
	cout<<ans;
	return 0;
}

