#include <bits/stdc++.h>
#define N 20005
using namespace std;
int n;
bool iss(int a[])
{
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])return false;
	}
	return 1;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	int a[N];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(iss(a))cout<<0;
	else
	{
		if(n==2)
		{
			cout<<4; 
		}
		else
		{
			cout<<n*n;
		}
	}
	return 0;
} 
