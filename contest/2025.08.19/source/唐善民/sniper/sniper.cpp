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
constexpr const int N=8000,U=20+1,T=25000+1,inf=0x3f3f3f3f;
constexpr const int value[]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
//dp[i][j]:µÚ i Ê±¿Ì,j Î»ÖÃ 
int n,dp[T+1+1][U+2+1][2],w[T+1+1][U+2+1],is[T+1+1];
struct zjj2024{
	int w,u,t;
}a[N+1];
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].u>>a[i].t;
		a[i].u++;a[i].t++;
		w[a[i].t][a[i].u]=value[a[i].w];
		if(a[i].w==15){
			is[a[i].t]=a[i].u;
		}
	}
	for(int i=1;i<=a[n].t;i++){
		for(int j=1;j<=U;j++){
			if(is[i]&&j!=is[i]){
				continue;
			}
			if(!is[i]){
				for(int k=max(j-2,1);k<=min(j+2,U);k++){
					dp[i][j][0]=max(dp[i][j][0],dp[i-1][k][0]);
				}
				if(i>=2){
					for(int k=max(j-2,1);k<=min(j+2,U);k++){
						dp[i][j][0]=max(dp[i][j][0],dp[i-2][k][1]);
					}
				}
			}
			for(int k=max(j-2,1);k<=min(j+2,U);k++){
				dp[i][j][1]=max(dp[i][j][1],dp[i-1][k][0]);
			}
			if(i>=2){
				for(int k=max(j-2,1);k<=min(j+2,U);k++){
					dp[i][j][1]=max(dp[i][j][1],dp[i-2][k][1]);
				}
			}
			dp[i][j][1]+=w[i][j];
//			cerr<<"w["<<i<<"]["<<j<<"]="<<w[i][j]<<'\n';
//			cerr<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
		}
	}
	int ans=-inf;
	for(int i=1;i<=U;i++){
		ans=max({ans,dp[a[n].t][i][0],dp[a[n].t][i][1]});
	}
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5
9 1 1
8 1 2
15 3 4
2 2 4
21 6 8

134
*/
