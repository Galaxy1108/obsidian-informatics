#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,p;
int ud[10000007],lr[10000007];

signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>p;
	if(n==1){
		cout<<(m*(m+1)/2)%p<<endl;
		return 0;
	}
	int dp[2][m+5][m+5];
	memset(dp,0,sizeof(dp));
	int nw=1;
	for(int l=1;l<=m;l++){
		for(int r=l;r<=m;r++){
			dp[1-nw][l][r]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m+1;j++){
			ud[j]=lr[j]=0;
		}
		int sm=0;
		for(int l=1;l<=m;l++){
			for(int r=l;r<=m;r++){
				sm=(sm+dp[1-nw][l][r])%p;
				ud[l]=(ud[l]+dp[1-nw][l][r])%p;
			}
		}
		for(int l=m;l>=1;l--){
			ud[l]=(ud[l]+ud[l+1])%p;
		}
		
		for(int r=1;r<=m;r++){
			for(int l=1;l<=r;l++){
				lr[r]=(lr[r]+dp[1-nw][l][r])%p;
			}
		}
		for(int r=1;r<=m;r++){
			lr[r]=(lr[r-1]+lr[r])%p;
		}
		for(int l=1;l<=m;l++){
			for(int r=l;r<=m;r++){
				dp[nw][l][r]=(2*p+sm-lr[l-1]-ud[r+1])%p;
			}
		}
		nw=1-nw;
	}
	int ans=0;
	for(int l=1;l<=m;l++){
		for(int r=l;r<=m;r++){
			ans=(ans+dp[1-nw][l][r])%p;
		}
	}
	cout<<ans<<endl;
	return 0;
}
