#include<bits/stdc++.h>
using namespace std;
const int mod=9999973,inv=4999987;
int n,m;
long long f[105][105][105];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=m;k++){
				if(j+k>m)
					continue;
				f[i][j][k]=f[i-1][j][k]; 
				if(k>0)
					f[i][j][k]=(f[i][j][k]+f[i-1][j][k-1]*(m-j-k+1)%mod)%mod;
				if(j>0)	
					f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k+1]*(k+1)%mod)%mod;
				if(k>1)
					f[i][j][k]=(f[i][j][k]+f[i-1][j][k-2]*(m-j-k+2)%mod*(m-j-k+1)%mod*inv%mod)%mod;
				if(j>0)
					f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k]*k%mod*(m-j-k+1)%mod)%mod;
				if(i>1)
					f[i][j][k]=(f[i][j][k]+f[i-1][j-2][k+2]*(k+2)%mod*(k+1)%mod*inv%mod)%mod;
			}
	long long ans=0;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++){
			if(i+j>m)
				continue;
			ans=(ans+f[n][i][j])%mod;
		}
	cout<<ans;		
	return 0;
} 
