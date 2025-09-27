#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=450; 
string s;
ll dp[N][N][3][3],cnt=0,mina=INT_MAX;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	getline(cin,s);
	s='#'+s;
	ll n=s.size()-1;
	memset(dp,0x3f,sizeof(dp));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			for(ll k1=0;k1<=2;k1++){
				for(ll k2=0;k2<=2;k2++){
					dp[i][j][k1][k2]=0;
				}
			}
		} 
	}
	for(ll i=1;i<=n;i++){
		dp[i][i][s[i]-'0'][s[i]-'0']=0;
		if(s[i]=='0') cnt++;
	}
	if(cnt>(n-1)/2+1){
		cout<<-1<<endl;
		return 0;
	}
	for(ll i=1;i<n;i++){
		if(s[i]==s[i+1]) continue ;
		dp[i][i+1][s[i]-'0'][s[i+1]-'0']=0;
		dp[i][i+1][s[i+1]-'0'][s[i]-'0']=1;
	}
	for(ll len=3;len<=n;len++){
		for(ll i=1;i+len-1<=n;i++){
			ll j=i+len-1;
			for(ll k1=0;k1<=2;k1++){
				for(ll k2=0;k2<=2;k2++){
					dp[i][j][k1][k2]=min(dp[i][j][k1][k2],dp[i+1][j][s[i]-'0'][k2]+1);
				}
			}
			for(ll k1=0;k1<=2;k1++){
				for(ll k2=0;k2<=2;k2++){
					dp[i][j][k1][k2]=min(dp[i][j][k1][k2],dp[i][j-1][k1][s[j]-'0']+1);
				}
			}
			for(ll k1=0;k1<=2;k1++){
				for(ll k2=0;k2<=2;k2++){
					if(k1!=s[i]-'0'){
						dp[i][j][s[i]-'0'][k2]=min(dp[i][j][s[i]-'0'][k2],dp[i+1][j][k1][k2]);
					}
				}
			}
			for(ll k1=0;k1<=2;k1++){
				for(ll k2=0;k2<=2;k2++){
					if(k2!=s[j]-'0'){
						dp[i][j][k1][s[j]-'0']=min(dp[i][j][k1][s[j]-'0'],dp[i][j-1][k1][k2]);
					}
				}
			}
		}
	}
	for(ll k1=0;k1<=2;k1++){
		for(ll k2=0;k2<=2;k2++){
			mina=min(mina,dp[1][n][k1][k2]);
		}
	}
	if(mina>=n*n) cout<<-1<<endl;
	else cout<<mina<<endl;
	return 0;
}
