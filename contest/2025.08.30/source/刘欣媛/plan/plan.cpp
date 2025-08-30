#include <bits/stdc++.h>
using namespace std;
int x[505],y[505],a[505];
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>x[i]>>y[i];
		
	}
	for(int i =1;i<=n;i++) cin>>a[i];
	if(k==n-1)
	{
		long long ans=0;
		for(int i=1;i<=n;i++) ans+=a[i];
		cout<<ans;
	}
	
	
	return 0;
} 
