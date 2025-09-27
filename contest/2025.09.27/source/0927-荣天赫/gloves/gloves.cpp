#include<iostream>
#include<algorithm>
using namespace std;
int l[100005],r[100005];
int ans=-1,ans1=-1,ans2=-1;
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>r[i];
	}
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,abs(l[i]-r[i]));
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=min(m,n);i++)
	{
		ans1=max(ans,abs(l[i]-r[i]));
	}
	int del=abs(n-m);
	if(n>m)
	{
		for(int i=1;i<=m;i++)
		{
			ans2=max(ans2,abs(r[i]-l[i+del]));
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans2=max(ans2,abs(l[i]-r[i+del]));
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}
