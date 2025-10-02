#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	unsigned long long n,h[2000005],maxn,minn,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++)
	{
		maxn=0,minn=2e9;
		for(int j=i;j<=n;j++)
		{
			maxn=max(maxn,h[j]);
			minn=min(minn,h[j]);
			ans=max(ans,(j-i+1)*maxn*minn);
		}
	}
	cout<<ans;
	return 0;
}
