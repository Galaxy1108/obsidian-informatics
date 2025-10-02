#include <bits/stdc++.h>
using namespace std;
int b[1000005];
int c[1000005];//-1Îª²»¹Ì¶¨ 
int d[1000005];
int pk0,pk1;
int use0,use1;
int n;
int solve()
{
	int pos;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<c[i]<<" ";
//	}
//	cout<<'\n'<<use0<<" "<<use1<<'\n';
	int u1=use1,u0=use0;
	
	for(int i=1;i<=n;i++)
	{
		d[i]=c[i];
		if(c[i+1]==1 and c[i-1]==1 and c[i]==-1 and u1>0)
		{
			d[i]=1;
			u1--;
		}
		if(c[i+1]==0 and c[i-1]==0 and c[i]==-1 and u0>0)
		{
			d[i]=0;
			u0--;
		}
	}
	if(d[1]==-1 and d[2]==1)
	{
		d[1]=1;
		u1--;
	}
	if(d[1]==-1 and d[2]==0)
	{
		d[1]=0;
		u0--;
	}
	for(int i=1;i<n;i++)
	{
		if(d[i+1]==-1 and d[i]==1 and u1>0)
		{
			d[i+1]=1;
			u1--;
		}
		if(d[i+1]==-1 and d[i]==0 and u0>0)
		{
			d[i+1]=0;
			u0--;
		}
	}
	if(u0==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==-1)
			{
				d[i]=1;
				u1--;
			 } 
		}
	}
	if(u1==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==-1)
			{
				d[i]=0;
				u0--;
			} 
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=-1)
		{
			pos=c[i];
			break;
		}
	}
	if(pos==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(u1>0 and d[i]==-1)
			{
				d[i]=1;
				u1--;
			}
			else if(u0>0 and d[i]==-1)
			{
				d[i]=0;
				u0--;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(u0>0 and d[i]==-1)
			{
				d[i]=0;
				u0--;
			}
			else if(u1>0 and d[i]==-1)
			{
				d[i]=1;
				u1--;
			}
		}
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		if(d[i]==d[i+1])
		{
			ans++;
		}
	}
	return (n-1)-ans;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		b[i]=x%2;
		if(b[i]==1) pk1++;
		else pk0++;
		c[i]=-1;
	}
	use0=pk0,use1=pk1;
	for(int i=1;i<=m;i++)
	{
		int p,b;
		cin>>p>>b;
		c[p]=b%2;
		if(c[p]==1)
		{
			use1--;
		}
		else
		{
			use0--;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<c[i]<<" ";
//	}
//	cout<<'\n';
	while(q--)
	{
		int t,p;
		cin>>t>>p;
		if(c[p]==1) use1++;
		else if(c[p]==0)
		{
			use0++;
		}
		if(t==1)
		{
			c[p]=-1;
		}
		else
		{
			int x;
			cin>>x;
			c[p]=x%2;
			if(c[p]==1)
			{
				use1--;
			}
			else
			{
				use0--;
			}
		}
		cout<<solve()<<'\n';
	}
	return 0;
}
