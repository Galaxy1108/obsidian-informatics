#include <bits/stdc++.h>
using namespace std;
long long f[1005],a[1005];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=-1e9;
	while(k--)
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=max(f[i-1]+a[i],a[i]);
			ans=max(f[i],ans);
		}
		cout<<ans;
	}
	return 0;
 } 
