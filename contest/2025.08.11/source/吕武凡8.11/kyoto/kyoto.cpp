#include<bits/stdc++.h>
using namespace std;
long long h,w;
long long a[1000100],b[1000100];
long long f[1000100];
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=w;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=w;i++)
	{
		f[i]=(i-1)*a[1];
	}
	for(int i=2;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(j==1)
			{
				f[j]=f[j]+b[j];
			}
			else f[j]=min(f[j]+b[j],f[j-1]+a[i]);
		}
	}
	cout<<f[w];
}
/*
5 5 
7 1 5 2 8 
7 2 4 1 6
*/
