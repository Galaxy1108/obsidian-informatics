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
typedef long long ll;
constexpr const int N=1e3,M=1e3;
int n,m,a[N+1],b[M+1];
ll dp[N+1][M+1];
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1+(i==1);j<=m;j++){
			dp[i][j]=min(dp[i-1][j]+b[j],dp[i][j-1]+a[i]);
		}
	}
	cout<<dp[n][m]<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
