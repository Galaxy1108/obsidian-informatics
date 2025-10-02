#include <bits/stdc++.h>
using namespace std;
long long n,h[2000005];
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	int l=1,r=n;
	long long ans=1,mx=0,mn=1e9;
	for(register int i=1;i<=n;i++)
	{
		mx=0,mn=1e9;
		for(register int j=i;j<=n;j++)
		{
			mx=max(h[j],mx);
			mn=min(h[j],mn);
			ans=max(ans,mx*mn*(j-i+1));
		}
	}
	cout<<ans;
	
	
	return 0;
 } 
