#include<bits/stdc++.h>
using namespace std;
int n,m,mod;
int add(int x,int y){
	x+=y;
	if(x>=mod) x-=mod;
	return x;
}
int mis(int x,int y){
	x-=y;
	if(x<0) x+=mod;
	return x;
}
template<typename T>
int getsum(const T& sum,int l,int r,int L,int R){return add(mis(mis(sum[r][R],sum[l-1][R]),sum[r][L-1]),sum[l-1][L-1]);}
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin >> n >> m >> mod;
	if(n==1){
		cout << (1ll*m*(m+1)/2)%mod << endl;
		return 0;
	}
	vector<vector<vector<int>>> dp(n,vector<vector<int>>(m+1,vector<int>(m+1,0)));
	vector<vector<vector<int>>> sum(n,vector<vector<int>>(m+1,vector<int>(m+1,0)));
	for(int L=1;L<=m;++L){
		for(int R=1;R<=m;++R){
			if(L<=R) dp[0][L][R]=1;
			sum[0][L][R]=add(mis(add(sum[0][L-1][R],sum[0][L][R-1]),sum[0][L-1][R-1]),dp[0][L][R]);
		}
	}
	for(int i=1;i<n;++i){
		for(int L=1;L<=m;++L){
			for(int R=1;R<=m;++R){
				if(L<=R) dp[i][L][R]=add(getsum(sum[i-1],1,L,L,m),getsum(sum[i-1],L+1,R,1,m));
				sum[i][L][R]=add(mis(add(sum[i][L-1][R],sum[i][L][R-1]),sum[i][L-1][R-1]),dp[i][L][R]);
			}
		}
	}
	int ans=0;
	for(int L=1;L<=m;++L){
		for(int R=L;R<=m;++R) ans=add(ans,dp[n-1][L][R]);
	}
	cout << ans << endl;
	return 0;
}
