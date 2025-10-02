#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int p,b;
int a[1000005][2];
int ans;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i][0];
	for(int i=1;i<=n;i++)
		a[i][0]=a[i][0]%2;
	for(int i=1;i<=m;i++)
	{
		cin>>p>>b;
		a[p][0]=b%2;
		a[p][1]=1;
	}
	a[1][0]=0;
	if(a[1][1]==0)
	{
		int i=2;
		while(a[i][1]==0&&i<=n)
			i++;
		if(i<n+1)
			a[1][0]=a[i][0];
	}
	for(int i=2;i<=n;i++)
		if(a[i][1]==0)
			a[i][0]=a[i-1][0];
	for(int i=2;i<=n;i++)
		if(a[i][0]!=a[i-1][0])
			ans++;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			cin>>p;
			if(a[p][1]==1)
			{
				a[p][1]=0;
				if(a[p][0]!=a[p+1][0]&&p==1)
					ans--,a[p][0]=a[p+1][0];
				else if(a[p][0]!=a[p-1][0]&&p==n)
					ans--,a[p][0]=a[p-1][0];
				if(a[p][0]!=a[p-1][0]&&a[p][0]!=a[p-1][0])
					ans-=2,a[p][0]=a[p-1][0];
			}	
		}
		else
		{
			cin>>p>>b;
			a[p][0]=b%2;
			a[p][1]=1;
			if(a[p][0]!=a[p+1][0]&&p==1)
			{
				ans++;
				int i=p+1;
				while(a[i][1]==0&&i<=n)
				{
					a[i][0]=a[p][0];
					i++;
				}
			}
			else if(a[p][0]!=a[p-1][0]&&p==n)
			{
				ans++;
				int i=p+1;
				while(a[i][1]==0&&i<=n)
				{
					a[i][0]=a[p][0];
					i++;
				}
			}
			if(a[p][0]!=a[p-1][0]&&a[p][0]!=a[p-1][0])
			{
				int i=p+1;
				while(a[i][1]==0&&i<n)
				{
					a[i][0]=a[p][0];
					i++;
				}
				if(a[i][0]!=a[p][0])
					ans+=2;
			}
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
