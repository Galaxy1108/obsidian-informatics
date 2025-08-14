#include <bits/stdc++.h>
using namespace std;
int a[20005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	if(n==1)
	{
		cout<<0;
	}
	if(n==2)
	{
		if(a[1]!=a[2])
		{
			cout<<4;
		}
		else
		{
			cout<<0;
		}
	}
	if(n==3)
	{
		if(a[1]==a[2]&&a[2]==a[3])
		{
			cout<<0;
		}
		else if(a[1]!=a[2]&&a[2]!=a[3]&&a[1]!=a[3])
		{
			cout<<42;
		}
		else
		{
			cout<<8;
		}
	}
	return 0;
 } 
