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
constexpr const int N=100,V=10;
int n;
char a[N+1];
int dp[N+1][V+1][V+1][V+1];
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=(a[i]=='A');j<=V;j++){
			for(int k=(a[i]=='B');j+k<=V;k++){
				for(int l=(a[i]=='C');j+k+l<=V;l++){
					switch(a[i]){
						case 'A':
							dp[i][j][k][l]=dp[i-1][j-1][k][l];
							break;
						case 'B':
							dp[i][j][k][l]=dp[i-1][j][k-1][l];
							break;
						case 'C':
							dp[i][j][k][l]=dp[i-1][j][k][l-1];
							break;
					}
				} 
			}
		}
		for(int j=0;j<=V;j++){
			for(int k=0;j+k<=V;k++){
				for(int l=0;j+k+l<=V;l++){
					dp[i][0][k][l]=min(dp[i][0][k][l],dp[i][j][k][l]+1);
					dp[i][j][0][l]=min(dp[i][j][0][l],dp[i][j][k][l]+1);
					dp[i][j][k][0]=min(dp[i][j][k][0],dp[i][j][k][l]+1);
				}
			}
		}
	}
	cout<<dp[n][0][0][0]<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
11
A
B
C
A
B
C
A
B
C
A
B
*/
