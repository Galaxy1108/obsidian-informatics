#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,anslt,ary[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ary[i];
	for(int i=1;i<=n;i++)
	{
		int mx=0,xr=0;
		for(int j=i;j<=n;j++)
		{
			mx=max(mx,ary[j]);
			xr^=ary[j];
			if(xr<=mx)anslt++;
		}
	}
	cout<<anslt;
	
	return 0;
} 
