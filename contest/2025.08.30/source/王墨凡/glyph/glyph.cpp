
#include<iostream>

using namespace std;
long long ma[210][210],dp[210][210][210],x1[100086],x2[100086],y1[100086],y2[100086],n,q;
bool flag2=1,flag3=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);	
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> ma[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin >> x1[i] >> x2[i] >> y1[i] >> y2[i];
		if(x1[i]!=1)flag2=0;
		if(x1[i]>n/2 or x2[i]<n/2 or y1[i]>n/2 or y2[i]<n/2)flag3=0;
	}
	if(flag2){
//		cout << '!';
		for(int i=1;i<=n;i++){
			dp[1][i][i]=ma[1][i];
			for(int j=1;j<=n;j++){
				for(int k=i;k<=n;k++){
					if(j!=1&&k!=i){
						dp[j][k][i]=min(dp[j][k-1][i],dp[j-1][k][i])+ma[j][k];
					}
					else if(j==1&&k!=i)dp[j][k][i]=dp[j][k-1][i]+ma[j][k];
					else if(j!=1&&k==i)dp[j][k][i]=dp[j-1][k][i]+ma[j][k];
				}
			}
		}
		for(int i=1;i<=q;i++){
			cout << dp[x2[i]][y2[i]][y1[i]] << '\n';
		}
	}
	else if(flag3){
		for(int i=1;i<=n;i++){
			dp[n/2][i][i]=ma[n/2][i];
			for(int j=n/2;j<=n;j++){
				for(int k=i;k<=n;k++){
					if(j!=n/2&&k!=i){
						dp[j][k][i]=min(dp[j][k-1][i],dp[j-1][k][i])+ma[j][k];
					}
					else if(j==n/2&&k!=i)dp[j][k][i]=dp[j][k-1][i]+ma[j][k];
					else if(j!=n/2&&k==i)dp[j][k][i]=dp[j-1][k][i]+ma[j][k];
				}
			}
			for(int j=n/2;j>=1;j--){
				for(int k=i;k>=1;k--){
					if(j!=n/2&&k!=i){
						dp[j][k][i]=min(dp[j][k+1][i],dp[j+1][k][i])+ma[j][k];
					}
					else if(j==n/2&&k!=i)dp[j][k][i]=dp[j][k+1][i]+ma[j][k];
					else if(j!=n/2&&k==i)dp[j][k][i]=dp[j+1][k][i]+ma[j][k];
				}
			}
		}
		for(int i=1;i<=q;i++){
			long long ans=1e15;
			for(int j=y1[i];j<=y2[i];j++){
				ans=min(ans,dp[x1[i]][y1[i]][j]+dp[x2[i]][y2[i]][j]-ma[n/2][j]);
			}
			cout << ans << '\n';
		}
	}
	else{
		for(int i=1;i<=q;i++){
			int x3=x1[i],x4=x2[i],y3=y1[i],y4=y2[i];
			dp[x3][y3][1]=ma[x3][y3];
			for(int j=x3;j<=x4;j++){
				for(int k=y3;k<=y4;k++){
					if(j!=x3&&k!=y3){
						dp[j][k][1]=min(dp[j][k-1][1],dp[j-1][k][1])+ma[j][k];
					}
					else if(j==x3&&k!=y3)dp[j][k][1]=dp[j][k-1][1]+ma[j][k];
					else if(j!=x3&&k==y3)dp[j][k][1]=dp[j-1][k][1]+ma[j][k];
				}
			}
			cout << dp[x4][y4][1] << '\n';
		}
	}
	return 0;
}
