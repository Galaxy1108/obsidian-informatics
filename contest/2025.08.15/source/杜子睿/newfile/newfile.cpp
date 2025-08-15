#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+9;
int n,m,q;
long long a[5005][5005],s[5005][5005];
int main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		for(int j=x;j<=y;j++)
			a[i][j]=(a[i-1][j]+z)%mod;
		for(int j=1;j<=n;j++){
			if(!a[i][j])
				a[i][j]=a[i-1][j];
			s[i][j]=(s[i][j-1]+a[i][j])%mod;
		}
	} 
	for(int i=0;i<q;i++){
		int u,d,l,r;
		cin>>u>>d>>l>>r;
		long long ans=0;
		for(int j=u;j<=d;j++)
			ans=(ans+s[j][r]+mod-s[j][l-1])%mod;
		cout<<ans<<endl;
	}
	return 0;
}

