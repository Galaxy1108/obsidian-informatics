#include<iostream>
using namespace std;
unsigned long long h[2000005];
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	unsigned long long n,i,j,minh,maxh,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	    cin>>h[i];
	for(i=1;i<=n;i++)
	{
		maxh=0;
		minh=2e9;
		for(j=i;j<=n;j++)
		{
			maxh=max(maxh,h[j]);
			minh=min(minh,h[j]);
			ans=max(ans,(j-i+1)*maxh*minh);
		}
	}
	cout<<ans;
	return 0;
 } 
