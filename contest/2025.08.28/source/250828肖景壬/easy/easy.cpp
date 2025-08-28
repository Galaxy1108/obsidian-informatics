#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],op,l,r,x;
signed main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= m; i++)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x;
			for(int j = 1; j <= n; j++)
			{
				a[j]=min(a[j],x);
			}
		}
		else if(op==2)
		{
			for(int j = 1; j <= n; j++)
			{
				a[j]+=j;
			}
		}
		else
		{
			cin>>l>>r;
			int ans=0;
			for(int j = l; j <= r; j++)
			{
				ans+=a[j];
			}
			cout<<ans<<endl;
		}
	}
}
