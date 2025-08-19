#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int f[1000010];
int x[1000010],t,num[1000010],c[1000010];
int dis[1000010];
int n;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>t>>c[i];
		num[i]=num[i-1]+t;
		dis[i]=dis[i-1]+num[i-1]*(x[i]-x[i-1]);
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		int mxn=1e18;
		for(int j=0;j<i;j++)
		{
			f[i]=min(f[i],f[j]+dis[i]-dis[j]-num[j]*(x[i]-x[j]));	
		}
		f[i]+=c[i];
	}
	cout<<f[n];	
}
/*
399358890
1284482264
*/
