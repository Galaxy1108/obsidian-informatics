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
constexpr const int N=50,M=500;
int n,m,a[N+1][N+1],dp[N+1][N+1][M+1];
int main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=j;k<=m;k++){
				for(int l=0;l<=j+1;l++){
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][l][k-j]);
				}
				for(int l=1;l<=j;l++){
					dp[i][j][k]+=a[l][i];
				}
			}
		} 
	}
	cout<<max(dp[n][0][m],dp[n][1][m])<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 5 
2 2 3 4
8 2 7
2 3
4

19
*/
