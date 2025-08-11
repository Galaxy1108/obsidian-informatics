#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10;
const ll INF=1e18;
ll dp1[1000005][10],dp[N][N];
int H,W;
ll h[N],w[N];
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dp,0x3f,sizeof(dp));
	memset(dp1,0x3f,sizeof(dp1));
	cin >> H >> W;
	for(int i=1;i<=H;i++){
		cin >> h[i];
	}
	for(int i=1;i<=W;i++){
		cin >> w[i];
	}if(H<=5000){
		dp[1][1]=dp[1][0]=dp[0][1]=dp[0][0]=0;
		for(int i=1;i<=H;i++){
			
			for(int j=1;j<=W;j++){
				if(i==j&&j==1)continue;
				dp[i][j]=min(dp[i-1][j]+w[j],dp[i][j-1]+h[i]);
	//			cout << dp[i][j] << " ";
			}
	//		cout << endl;
		}	
		cout << dp[H][W];
		return 0;
	}
	
//	cout << endl;
	int flag=0;
//	dp1[1][1]=dp1[1][0]=dp1[0][1]=dp1[0][0]=0;
	for(int i=1;i<=H;i++){
		int ii;
		if(i%2==1)ii=1;
		else ii=2;
		for(int j=1;j<=W;j++){
			if(i==1&&j==1)dp1[ii][j]=0;
			if(ii==2){
//				dp1[ii-1][j]=dp1[ii][j];
//				cout << dp1[ii][j] << ":";
//				dp1[ii][j]=INF;
//				cout << dp1[ii-1][j] << "   ";
			}
			else{
//				dp1[ii+1][j]=dp1[ii][j];
//				cout << dp1[ii][j] << ":";
//				dp1[ii][j]=INF;
//				cout << dp1[ii+1][j] << "   ";
			}
			
		}
//		cout << endl;
		for(int j=1;j<=W;j++){
			if(i==1&&j==1)dp1[ii][j]=0;
			else{
				if(ii==2){
					dp1[ii][j]=min(dp1[ii][j-1]+h[i],dp1[ii-1][j]+w[j]);	
				}
				else{
					dp1[ii][j]=min(dp1[ii][j-1]+h[i],dp1[ii+1][j]+w[j]);	
				}
//				cout << dp1[ii][j] << " ";
			}
		}
//		cout << endl;
		for(int j=1;j<=W;j++){
			if(ii==2){
				dp1[ii-1][j]=dp1[ii][j];
			}
			else{
				dp1[ii+1][j]=dp1[ii][j];
			}
//			dp1[ii][j]=INF;
//			cout << dp1[ii-1][j] << " ";
		}
		if(i==H&&H>=5001)cout << dp1[ii][W] << " ";
//		cout << ii;
//		cout << endl<< endl;
	}
	
	return 0;
}
