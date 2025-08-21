#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	int n;
	cin>>n;
	if(n<=10)
	{
		int sum=1;
		for(int i=2;i<=n;i++)
		{
			sum=sum*i/__gcd(sum,i);
		}
		cout<<sum<<" ";
		for(int i=2;i<=n;i++)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		for(int i=2;i<=n;i++)
		{
			cout<<1<<" "<<i<<endl;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cout<<i<<" ";
		}
		for(int j=2;j<=n;j++)
		{
			if(j*2<=n)
			{
				cout<<j<<" "<<j*2<<endl;
			}
			else
			{
				cout<<1<<" "<<j<<endl;
			}
		}
	}
	return 0; 
} 
