#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],dp[2][105][105];
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp[0],0x3f3f3f3f,sizeof dp[0]);
	for(int i=1;i<m;i++)
		for(int j=i+1;j<=m;j++)
			dp[0][m-i][m-j]=a[i]+a[j];
	int id=0;
	for(int i=m+1;i<=n;i++){
		id^=1;
		memset(dp[id],0x3f3f3f3f,sizeof dp[id]);
		for(int j=1;j<m;j++)
			for(int k=0;k<j;k++){
				if(j!=m-1)
					dp[id][j+1][k+1]=dp[id^1][j][k];
				dp[id][k+1][0]=min(dp[id][k+1][0],dp[id^1][j][k]+a[i]);
			}
	}
	int minn=INT_MAX;
	for(int i=1;i<m;i++)
		for(int j=0;j<i;j++)
			minn=min(minn,dp[id][i][j]);
	cout<<minn;
	return 0;
}

