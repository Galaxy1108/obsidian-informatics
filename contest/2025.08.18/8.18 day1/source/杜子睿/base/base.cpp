#include<bits/stdc++.h>
using namespace std;
int n;
long long a[2][2005],s[2][2005],f[2005],ff[2005];
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[0][i];
		s[0][i]=s[0][i-1]+a[0][i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
		s[1][i]=s[1][i-1]+a[1][i];
	}
	fill(f,f+n+3,-1e18);
	fill(ff,ff+n+3,-1e18);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--)
			f[i]=max(f[i],s[0][i]-s[0][j-1]+s[1][i]-s[1][j-1]);
		for(int j=i;j<=n;j++)
			ff[i]=max(ff[i],s[0][j]-s[0][i-1]+s[1][j]-s[1][i-1]);
	}		
	long long maxn=-1e18;
	for(int i=2;i<=n-1;i++)
		for(int j=i;j<=n-1;j++)
			maxn=max(maxn,f[i-1]+ff[j+1]+s[1][j]-s[1][i-1]);
	cout<<maxn;
	return 0;
}

