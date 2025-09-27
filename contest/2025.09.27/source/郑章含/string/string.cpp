#include<bits/stdc++.h>
using namespace std;
//string s;
//int x0,x1,x2,n,dp[500][500];
//bool canx(int l,int r){
//	for(int i=l+1;i<=r;i++){
//		if(s[i]==s[i-1]) return 0;
//	}
//	return 1;
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	memset(dp,0x7f,sizeof(dp));
//	cin>>s;
//	n=s.length();
//	for(int i=0;i<n;i++){
//		s[i]-='0';
//		if(s[i]==0) x0++;
//		if(s[i]==1) x1++;
//		if(s[i]==2) x2++;
//	}
//	if(x0>(n+1)/2||x1>(n+1)/2||x2>(n+1)/2){
//		printf("-1");
//		return 0;
//	}
//	for(int l=1;l<=n;l++){
//		for(int i=1;i<=n-l+1;i++){
//			int j=i+l-1;
//			if(i>j) dp[i][j]=0;
//			if(canx(i,j)) dp[i][j]=0;
//		}
//	}
//	for(int l=1;l<=n;l++){
//		for(int i=1;i<=n-l+1;i++){
//			int j=i+l-1;
//			for(int k=i+1;i<=j;k++){
//				dp[i][j]=min(dp[i][j],1+dp[i][k-2]+dp[k+1][j]);
//			}
//		}
//	}
//	printf("%d",dp[1][n]);
	printf("-1");
	return 0;
}
