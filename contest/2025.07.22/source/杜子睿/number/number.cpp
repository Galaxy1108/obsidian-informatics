#include<bits/stdc++.h>
using namespace std;
int t,n,m;
long long dp[2005][4005],a[2005],book[2005][4005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(dp,0,sizeof dp);
		memset(book,0,sizeof book);
		for(int i=m;i>=1;i--)
			cin>>a[i];
		dp[1][1]=a[1];
		book[1][1]=1;
		for(int i=2;i<=m;i++){
			for(int j=0;j<n;j++){
				if(i>j&&book[i-1][j]){
					dp[i][j+1]=(book[i][j+1])?max(dp[i][j+1],dp[i-1][j]+a[i]):dp[i-1][j]+a[i];
					book[i][j+1]=1;
				}
				if(i>=j&&book[i-1][j+1]){
					dp[i][j]=(book[i][j])?max(dp[i-1][j+1]-a[i],dp[i][j]):dp[i-1][j+1]-a[i];
					book[i][j]=1;
				}
			}
			for(int j=n;j<2*n;j++){
				if(i>j&&book[i-1][j]){
					dp[i][j+1]=(book[i][j+1])?max(dp[i][j+1],dp[i-1][j]-a[i]):dp[i-1][j]-a[i];
					book[i][j+1]=1;
				}
				if(i>=j&&book[i-1][j+1]){
					dp[i][j]=(book[i][j])?max(dp[i][j],dp[i-1][j+1]+a[i]):dp[i-1][j+1]+a[i];
					book[i][j]=1;
				}
			}
			if(book[i][2*n]){
				dp[i][0]=(book[i][0])?max(dp[i][0],dp[i][2*n]):dp[i][2*n];
				book[i][0]=1;
			}
		}
		long long maxx=-1e18;
		for(int i=0;i<=2*n;i++)
			if(book[m][i]) 
				maxx=max(maxx,dp[m][i]);
		cout<<maxx<<endl;
	}
	return 0;
}
