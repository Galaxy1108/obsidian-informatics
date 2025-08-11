#include<bits/stdc++.h>
using namespace std;
int n,a[150005],b[150005],c[150005],ans=-1;
int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j==i) continue;
			for(int k = 1; k <= n; k++)
			{
				//cout<<i<<" "<<j<<" "<<k<<endl;
				if(k==i||k==j) continue;
				if(a[i]<=a[j]||a[i]<=a[k]) continue;
				if(b[j]<=b[i]||b[j]<=b[k]) continue;
				if(c[k]<=c[i]||c[k]<=c[j]) continue;
				ans=max(ans,a[i]+b[j]+c[k]);
			}
		}
	}
	cout<<ans<<endl;
}
