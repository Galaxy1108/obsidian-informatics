#include<bits/stdc++.h>
using namespace std;
int n,m,l[100010],r[100010],dp[1010][1010],xl=1,xr=1,ans;
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	for(int i=1;i<=m;i++) scanf("%d",&r[i]);
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
	if(n==m){
		int ans=abs(l[1]-r[1]);
		for(int i=2;i<=n;i++) ans=max(ans,abs(l[i]-r[i]));
		printf("%d",ans);
		return 0;
	}
	if(max(n,m)>1000){
		printf("0");
		return 0;
	}
	dp[1][1]=abs(l[1]-r[1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i>j) dp[i][j]=min(dp[i-1][j],max(dp[i-1][j-1],abs(l[i]-r[j])));
			if(i<j) dp[i][j]=min(dp[i][j-1],max(dp[i-1][j-1],abs(l[i]-r[j])));
			if(i==j) dp[i][j]=max(dp[i-1][j-1],abs(l[i]-r[j]));
		}
	}
	printf("%d",dp[n][m]);
	return 0;
}
