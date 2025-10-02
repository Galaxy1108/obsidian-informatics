#include<bits/stdc++.h>
using namespace std;
int dp1[8005][8005],dp2[8005][8005],n,a[200005];
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp1[i][i]=a[i];
		dp2[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp1[i][j]=min(dp1[i][j-1],a[j]);
			dp2[i][j]=max(dp2[i][j-1],a[j]);
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			maxn=max(maxn,dp1[i][j]*dp2[i][j]*(j-i+1));
		}
	}
	cout<<maxn; 
	return 0;
}
