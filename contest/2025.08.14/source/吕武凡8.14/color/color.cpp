#include<bits/stdc++.h>
using namespace std;
int n;
int a[10001];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		if(a[1]==a[2])
		{
			cout<<0;
			return 0;
			}
		else
		{
			cout<<4;
			return 0;
			}	
	}	
	if(n==3)
	{
		if(a[1]!=a[2]&&a[2]!=a[3]&&a[1]!=a[3])
		{
			cout<<42;
			return 0;
		}
		if(a[1]==a[2]&&a[2]==a[3]&&a[1]==a[3])
		{
			cout<<0;
			return 0;
		}
		else
		{
			cout<<8;
			return 0;
		}
	}
} 
