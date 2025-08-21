#include<bits/stdc++.h>
#define ll long long
#define add(x,y) x=(x+y%mod)%mod
using namespace std;
const int mod=1000000007;
int n;
int a[5010];
//ll f[2][1000010];
//ll s[2][1000010];
//int maxx;
ll qpow(int d,int z){
	ll res=1,now=d;
	while(z){
		if(z&1) res=res*now%mod;
		now=now*now%mod; z>>=1;
	}
	return res;
}
inline ll dec(ll x,ll y){
	return ((x-y)%mod+mod)%mod;
}
inline ll Inv(int num){
	return qpow(num,mod-2);
}
//void solve1(){
//	int now=1,las=0;
//	f[now][0]=1; s[now][0]=1;
//	for(int i=1;i<=maxx;i++) s[now][i]=s[now][i-1];
//	ll tot=1;
//	for(int i=1;i<=n;i++){
//		tot=tot*a[i]%mod;
//		swap(now,las);
//		s[now][0]=0; 
//		for(int j=1;j<=a[i];j++){
////			if(j<=a[i]) f[now][j]=(s[las][(j>a[i-1])?a[i-1]:j]+f[las][j]*(j-1)%mod)%mod;
//			f[now][j]=(s[las][(j>a[i-1])?a[i-1]:j]+f[las][j]*(j-1)%mod)%mod;
//			s[now][j]=s[now][j-1]+f[now][j];
//		}
//	}
//	tot=Inv(tot);
//	ll ans=0;
//	for(int i=1;i<=maxx;i++){
//		cout<<f[now][i]<<' ';
//		add(ans,f[now][i]*tot%mod*i);
//	}
//	cout<<ans;
//}
//int f[1000010];
void solve2(){
	ll sum=1,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i-1]+1;j<=a[i];j++){
//			f[j]=sum*dec(qpow(j,n-i+1),qpow(j-1,n-i+1))%mod;
			add(ans,sum*dec(qpow(j,n-i+1),qpow(j-1,n-i+1))%mod*j);
//			cout<<f[j]<<' ';
		}
		sum=sum*a[i]%mod;
	}	
	sum=Inv(sum);
	ans=ans*sum%mod;
	cout<<ans;
}
signed main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
//	if(n<=500) solve1();
//	else if(n<=5000) solve2();
	
	solve2();
	return 0;
}

