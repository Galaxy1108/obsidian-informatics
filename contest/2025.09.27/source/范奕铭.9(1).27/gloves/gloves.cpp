#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100500];
long long b[100500];
long long head=0;
long long tail=0;
long long ans;
bool check(long long x)
{
	int cnt=0;
	if(n>m)
	{
		for(int i=1;i<=n;i++)
		{
			if(abs(a[i]-b[cnt+1])<=x)
			{
				cnt++;
			}
		}
		return cnt==m;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(abs(b[i]-a[cnt+1])<=x)
			{
				cnt++;
			}
		}
		return cnt==n;
	}
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>tail)
		{
			tail=a[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		if(b[i]>tail)
		{
			tail=b[i];
		}
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	while(head<=tail)
	{
		long long mid=(head+tail)/2;
		if(check(mid))
		{
			ans=mid;
			tail=mid-1;
		} 
		else
		{
			head=mid+1;
		}
	}
	cout<<ans;
	return 0;
} 
