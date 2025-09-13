#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100001];
bool check()
{
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i+1])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]<a[i+1])
			{
				f=1;
				break;
			}
		}
		if(!f)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(n==2)
		{
			if(a[1]+1==a[2])
			{
				cout<<-1<<endl;
				continue;
			}
			else
			{
				cout<<a[1]+a[2]<<endl;
				continue;
			}
		}
		else
		{
			int maxn=0;
			while(check())
			{
				if(a[1]+a[2]<a[2]+a[3])
				{
					maxn=max(maxn,a[1]+a[2]);
					swap(a[1],a[2]);
					a[1]--;
					a[2]++;
					if(!check())
					{
						break;
					}
					maxn=max(maxn,a[2]+a[3]);
					swap(a[2],a[3]);
					a[2]--;
					a[3]++;
					if(!check())
					{
						break;
					}
				}
				else
				{
					
					maxn=max(maxn,a[2]+a[3]);
					swap(a[2],a[3]);
					a[2]--;
					a[3]++;
					if(!check())
					{
						break;
					}
					maxn=max(maxn,a[1]+a[2]);
					swap(a[1],a[2]);
					a[1]--;
					a[2]++;
					if(!check())
					{
						break;
					}
				}
			}
			cout<<maxn<<endl;
			continue;
		}
	}
}
