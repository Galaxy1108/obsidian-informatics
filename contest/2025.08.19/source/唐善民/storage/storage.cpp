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
constexpr const int N=1000000;
constexpr const ll inf=0x3f3f3f3f3f3f3f3f;
int n,x[N+1],p[N+1],c[N+1];
ll dp[N+1];
int main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>p[i]>>c[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		ll pl=0;
		for(int j=1;j<i;j++){
			pl+=(x[i]-x[j])*p[j];
		}
		dp[i]=pl;
		for(int j=1;j<i;j++){
			pl-=(x[i]-x[j])*p[j];
			dp[i]=min(dp[i],dp[j]+pl);
		}
		dp[i]+=c[i];
	}
	cout<<dp[n]<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
0 5 10
5 3 100
9 6 10

32
*/
