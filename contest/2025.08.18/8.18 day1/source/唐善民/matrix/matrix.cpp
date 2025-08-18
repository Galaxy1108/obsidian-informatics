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
constexpr const int N=100,M=2,K=10,inf=0x3f3f3f3f;
int n,m,k,a[N+1][M+1];
namespace judge1{
	int s[N+1],dp[N+1][K+1];
	int main(){
		memset(dp,0xc0,sizeof(dp));
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i][1];
		}
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			dp[i][0]=0;
			for(int j=1;j<=i&&j<=k;j++){
				dp[i][j]=dp[i-1][j];
				for(int l=1;l<=i;l++){
					dp[i][j]=max(dp[i][j],dp[l-1][j-1]+s[i]-s[l-1]);
				}
			}
		}
		int ans=dp[k][k];
		for(int i=k+1;i<=n;i++){
			ans=max(ans,dp[i][k]);
		}
		return ans;
	}
}
namespace judge2{
	int s[N+1][2],dp[N+1][N+1][K+1];
	int main(){
		for(int i=1;i<=n;i++){
			s[i][1]=s[i-1][1]+a[i][1];
			s[i][2]=s[i-1][2]+a[i][2];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int kk=1;kk<=k&&kk<=i+j;kk++){
					dp[i][j][kk]=max(dp[i-1][j][kk],dp[i][j-1][kk]);
					if(i==j){
						for(int l=0;l<i;l++){
							dp[i][j][kk]=max(dp[i][j][kk],dp[l][l][kk-1]+s[i][1]-s[l][1]+s[j][2]-s[l][2]);
						}
					}
					for(int l=0;l<i;l++){
						dp[i][j][kk]=max(dp[i][j][kk],dp[l][j][kk-1]+s[i][1]-s[l][1]);
					}
					for(int l=0;l<j;l++){
						dp[i][j][kk]=max(dp[i][j][kk],dp[i][l][kk-1]+s[j][2]-s[l][2]);
					}
//					cerr<<"dp["<<i<<"]["<<j<<"]["<<k<<"]="<<dp[i][j][k]<<'\n';
				}
			}
		}
		return dp[n][n][k];
	}
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(m==1){
		cout<<judge1::main()<<'\n';
	}else{
		cout<<judge2::main()<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 1 1
1
-2
3
*/
