#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
int n,n1;
deque<int>p;
deque<int>q;
int getmax()
{
	int sum=-1,flag=0,ans=0;
	if(!p.empty()&&sum<a[p.front()])
	{
		sum=a[p.front()];
		ans=p.front();
		flag=1;
	}
	if(!q.empty()&&sum<a[q.front()])
	{
		sum=a[q.front()];
		ans=q.front();
		flag=2;
	}
	if(flag==1)
		p.pop_front();
	if(flag==2)
		q.pop_front();
	return ans;
}
int getmin()
{
	int sum=LONG_LONG_MAX,flag=0,ans=0;
	if(!p.empty()&&sum>a[p.back()])
	{
		sum=a[p.back()];
		ans=p.back();
		flag=1;
	}
	if(!q.empty()&&sum>a[q.back()])
	{
		sum=a[q.back()];
		ans=q.back();
		flag=2;
	}
	if(flag==1)
		p.pop_back();
	if(flag==2)
		q.pop_back();
	return ans;
}
int getmin1()
{
	int sum=LONG_LONG_MAX,ans=0;
	if(!p.empty()&&sum>a[p.back()])
	{
		sum=a[p.back()];
		ans=p.back();
	}
	if(!q.empty()&&sum>a[q.back()])
	{
		sum=a[q.back()];
		ans=q.back();
	}
	return ans;
}
int work()
{
	int ans=n1;
	while(!p.empty())
		p.pop_front();
	while(!q.empty())
		q.pop_front();
	for(int i=1;i<=n;i++)
		p.push_front(i);
	while(1)
	{
		int maxn=getmax();
		int minn=getmin();
		if(a[maxn]>a[minn])
		{
			int k=getmin1();
			if(k==0)
			{
				ans--;
				break;
			}
			else
			{
				if(a[maxn]-a[minn]>a[k])
				{
					q.push_back(maxn);
					a[maxn]-=a[minn];
					ans--;
				}
				else if(a[maxn]-a[minn]==a[k]&&maxn>k)
				{
					q.push_back(maxn);
					a[maxn]-=a[minn];
					ans--;
				}
				else
					break;
			}
		}
		else if(a[maxn]==a[minn])
		{
			int k=getmin1();
			if(k==0)
				ans--;
			break;
		}
		else
			break;
		if(ans==1)
			break;
	}
	return ans;
}
signed main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	cin>>t;
	a[0]=-1;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(i==1)
		{
			n1=n;
			for(int j=1;j<=n;j++)
				cin>>a[j];
			int ans=work();
			cout<<ans<<'\n';
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			int ans=work();
			cout<<ans<<'\n';
		}
	}
	return 0;
}
