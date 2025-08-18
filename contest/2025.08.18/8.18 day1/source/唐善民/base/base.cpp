//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
#define int long long 
typedef long long ll;
constexpr const int N=2000;
int n,a[3][N+1],s[3][N+1],dp[N+1][N+1];
void pre(){
	for(int l=1;l<=n;l++){
		int ans=a[1][l],sum=a[1][l];
		dp[l][l]=ans;
		for(int r=l+1;r<=n;r++){
			sum=min(a[1][r],sum+a[1][r]);
			ans=min(ans,sum);
			dp[l][r]=ans;
		}
	}
}
main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[2][i];
	}
	pre();
	for(int i=1;i<=n;i++){
		s[1][i]=s[1][i-1]+a[1][i];
		s[2][i]=s[2][i-1]+a[2][i];
	}
	ll ans=-(1ll<<62);
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			ans=max(ans,s[2][j]-s[2][i-1] + s[1][j]-s[1][i-1] - dp[i+1][j-1]);
		}
	}
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4
1 3 -4 5
-2 6 -1 7

20
*/
