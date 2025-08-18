#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(int i(a);i<=b;++i)
#define R(i,a,b) for(int i(a);i>=b;--i)
#define _ 0
using namespace std;
int n,dp[101][11][11][11];
short sum[101][2];
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	scanf("%d",&n);
	F(i,1,n){
		char ch=getchar();
		while(ch<'A'||ch>'C') ch=getchar();
		F(j,0,2) sum[i][j]=sum[i-1][j]+(ch-'A'==j);
	}
	memset(dp,127,sizeof(dp));
	dp[10][sum[10][1]][sum[10][2]][sum[10][3]]=0;
	F(i,10,n) R(j,10,0) R(k,10,0) R(l,10,0){
		if(dp[i][j][k][l]==dp[0][0][0][0]) continue;
		dp[min(i+j,n)][sum[min(i+j,n)][0]-sum[i][0]][k+sum[min(i+j,n)][1]-sum[i][1]][l+sum[min(i+j,n)][2]-sum[i][2]]=min(dp[min(i+j,n)][sum[min(i+j,n)][0]-sum[i][0]][k+sum[min(i+j,n)][1]-sum[i][1]][l+sum[min(i+j,n)][2]-sum[i][2]],dp[i][j][k][l]+1);
		dp[min(i+k,n)][j+sum[min(i+k,n)][0]-sum[i][0]][sum[min(i+k,n)][1]-sum[i][1]][l+sum[min(i+k,n)][2]-sum[i][2]]=min(dp[min(i+k,n)][j+sum[min(i+k,n)][0]-sum[i][0]][sum[min(i+k,n)][1]-sum[i][1]][l+sum[min(i+k,n)][2]-sum[i][2]],dp[i][j][k][l]+1);
		dp[min(i+l,n)][j+sum[min(i+l,n)][0]-sum[i][0]][k+sum[min(i+l,n)][1]-sum[i][1]][sum[min(i+l,n)][2]-sum[i][2]]=min(dp[min(i+l,n)][j+sum[min(i+l,n)][0]-sum[i][0]][k+sum[min(i+l,n)][1]-sum[i][1]][sum[min(i+l,n)][2]-sum[i][2]],dp[i][j][k][l]+1);
	}
	cout<<dp[n][0][0][0];
	return ~~(0^_^0);
} 
