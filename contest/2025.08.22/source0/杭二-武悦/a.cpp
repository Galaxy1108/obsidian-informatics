#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define endl "\n"
#define pii pair<int,int>
#define int long long
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
const int N=4e3+5;
int n,m,mod;
int dp[2][N][N],mp[N][N];
signed main(){
	freopen("a.in","r",stdin); 
	freopen("a.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>mod;
	if(n==1){ cout<<m*(m+1)/2%mod<<endl;return 0;}
	else if(m==1){ cout<<1<<endl;return 0;}
	int w=1;
	FOR(i,1,n+1){
		if(i!=1){
			FOR(l,1,m){
				FOR(r,l,m){
					dp[w][l][r]=mp[m][m];
					dp[w][l][r]=(dp[w][l][r]-(mp[m][m]-mp[r][m]-mp[m][r]+mp[r][r]+mod*2)%mod+mod)%mod;
					dp[w][l][r]=(dp[w][l][r]-mp[l-1][l-1]+mod)%mod;
				}
			} 
		}else{
			FOR(l,1,m) FOR(r,l,m) dp[w][l][r]=1;
		}
		FOR(l,1,m) FOR(r,1,m) mp[l][r]=(mp[l-1][r]+mp[l][r-1]-mp[l-1][r-1]+dp[w][l][r]+mod*2)%mod; 
		w^=1;
	}
	cout<<dp[w^1][1][m]<<endl;
	return (0-0);
}

