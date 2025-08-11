#include<bits/stdc++.h>
using namespace std;
int ans=0;
int head[100001];
bool tick[100001];
int lu[100001],dis[100001];
int f[100001];
int n,m,q;
int s,t,x,y;
int o,u;
int a[101000],b[100100];
int find(int x)
{
	int i=x;
	int ans=0;
	while(f[i]!=i)
	{
		i=f[i];
		ans++;
	}
	return ans;
}
void to(int s)
{
	int nx=f[s],p;
	for(int i=1;i<n;i++)
	{
		if(nx==a[i]&&s==b[i]||nx==b[i]&&s==a[i])
		{
			p=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(lu[i]==p)
		{
			if(u>=dis[i])
			{
				u-=dis[i];
			}
			else
			{
				o--;
			}
		}
	}
}
void calc(int st,int end)
{
	int f1=find(st),f2=find(end);
	if(f1>f2)
	{
		int k=f1-f2;
		while(k--)
		{
			to(st);
			st=f[st];
		}
		if(st==end)
		{
			return;
		}
		else
		{
			while(f[st]!=st)
			{
				to(st);
				st=f[st];
			}
			while(f[end]!=end)
			{
				to(end);
				end=f[end];
			}
		}
	}
	if(f1==f2)
	{
		if(st==end)
		{
			return;
		}
		else
		{
			while(f[st]!=st)
			{
				to(st);
				st=f[st];
			}
			while(f[end]!=end)
			{
				to(end);
				end=f[end];
			}
		}
	}
	if(f1<f2)
	{
		int k=f2-f1;
		while(k--)
		{
			to(end);
			end=f[end];
		}
		if(st==end)
		{
			return;
		}
		else
		{
			while(f[st]!=st)
			{
				to(st);
				st=f[st];
			}
			while(f[end]!=end)
			{
				to(end);
				end=f[end];
			}
		}
	}
}
int main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<n;i++)
	{
		cin>>a[i]>>b[i];
		f[b[i]]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>lu[i]>>dis[i];
	}
	int l,r,mid;
	while(q--)
	{
		cin>>s>>t>>x>>y;
		o=x,u=y;
		calc(s,t);
		ans=o;
		o=x,u=y;
		calc(t,s);
		ans=max(ans,o);
		if(ans<0)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<ans<<endl;	
		}
	}
}
