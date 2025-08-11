#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e3+5;
typedef long long ll;
int n,m;
int a[N],b[N];
ll f[N][N];
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	memset(f,0x3f,sizeof f);
	f[1][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j+1]=min(f[i][j+1],f[i][j]+a[i]),
			f[i+1][j]=min(f[i+1][j],f[i][j]+b[j]);
	cout<<f[n][m];
	return 0;
}
