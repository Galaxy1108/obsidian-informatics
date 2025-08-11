#include <bits/stdc++.h>
using namespace std;
/*
f[i]=min(j=i-k~i-1){f[j]+max(k=j+1~i){s[k]}}
*/
#define N 2500005
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007ll
int n,k,s[N];
long long f[N],pw[N];
int main(){
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	pw[0]=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		f[i]=INF;
		pw[i]=pw[i-1]*23ll%MOD;
	}
	int mx=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		mx=s[i];
		for(int j=i-1;j>=i-k&&j>=0;j--){
			f[i]=min(f[i],f[j]+mx);
			mx=max(mx,s[j]);
		}
//		cerr<<f[i]<<' ';
		ans+=f[i]*pw[n-i]%MOD;
		if(ans>=MOD)ans-=MOD;
	}
	cout<<ans;
	return 0;
}

