#include<bits/stdc++.h>
using namespace std;
#define um unordered_map
//inline bool jiao(int xa,int ya,int xb,int yb){
//	
//}
using ll=long long;
int n,m,p;
unordered_map<int,unordered_map<int,um<int,ll> > >dp,bei,ans;
ll pre[110][110];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>p;
	if(m==1){
		cout<<1%p;return 0;
	}
	if(n==1){
		cout<<(ll)m*(m+1)/2%p;return 0;
	}
	for(int i=1;i<=m;i++)
	for(int j=i;j<=m;j++)dp[1][i][j]=1,pre[i][j]=pre[i][j-1]+1;
	
	for(int i=2;i<=n;i++){
		for(int l=1;l<=m;l++){
			for(int r=l;r<=m;r++){
				for(int k=1;k<=l;k++){
					(dp[i][l][r]+=(pre[k][m]-pre[k][l-1])%p+p)%=p;
				}
				for(int k=l+1;k<=r;k++){
					(dp[i][l][r]+=(pre[k][m]-pre[k][k-1])%p+p)%=p;
				}
			}
		}
		for(int l=1;l<=m;l++){
			for(int r=l;r<=m;r++){
				(pre[l][r]=pre[l][r-1]+dp[i][l][r])%=p;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)(ans+=dp[n][i][j])%=p;
	cout<<ans;
	return 0;
}
