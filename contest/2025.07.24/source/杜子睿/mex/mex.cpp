#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,s[5005];;
long long ans=1,f[5005][5005];
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cnt+=s[i]^1;
	}
	if(m>=n){
		for(int i=0;i<cnt;i++)
			ans=ans*m%mod;
		cout<<ans;
		return 0;
	} 
	f[0][m+1]=1;
	for(int i=1;i<=n;i++){
		if(s[i]){
			int j=i-1,k=1;
			while(s[i+1]&&i<n){
				i++;
				k++;
			}
			for(int l=m+1;l>=k;l--)
				f[i][l-k]=f[j][l];
			continue;
		}
		for(long long j=0;j<=m+1;j++)
			if(f[i-1][j]){
				f[i][j]=(f[i][j]+f[i-1][j]*(m+1-j)%mod)%mod;
				if(j)
					f[i][j-1]=(f[i][j-1]+f[i-1][j]*(j-1)%mod)%mod;	
			}
	}
	ans=0;
	for(int i=0;i<=m+1;i++)
		ans=(ans+f[n][i])%mod;
	cout<<ans;
	return 0;
} 
