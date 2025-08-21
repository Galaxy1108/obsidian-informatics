#include <bits/stdc++.h>
using namespace std;
constexpr int N=45,M=65;
constexpr long long MOD=998244353ll;
int n,m;
long long l[N],r[N],ans[N];
long long dp[N][(1<<15)];
bool ishw(long long x){
	static int a[55],cnt;
	cnt=0;
	while(x){
		a[++cnt]=x&1;
		x>>=1;
	}
	for(int i=cnt+1;i<=m;i++)a[i]=0;
	for(int i=1,j=m;i<j;i++,j--){
		if(a[i]!=a[j])return false;
	}
	return true;
}
int main(){
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<m);j++){
			if(dp[i-1][j]==0)continue;
			for(long long k=l[i];k<=r[i];k++){
				dp[i][j^k]=(dp[i][j^k]+dp[i-1][j])%MOD;
			}
		}
	}
	for(int j=0;j<(1<<m);j++){
		if(ishw(j)){
			for(int i=1;i<=n;i++){
				ans[i]=(ans[i]+dp[i][j])%MOD;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

