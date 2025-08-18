#include<bits/stdc++.h>
using namespace std;
const int mx=1e4+100;
int n,m,a[mx],q[mx];
long long f[mx],ans=1e18;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<=t&&i-q[h]>=m) h++;
		f[i]=f[q[h]]+a[i];
		while(h<=t&&f[q[t]]>=f[i]) t--;
		q[++t]=i;
	}
	for(int i=n-m+2;i<=n;i++) ans=min(ans,f[i]);
	cout<<ans;
	return 0;
} 
