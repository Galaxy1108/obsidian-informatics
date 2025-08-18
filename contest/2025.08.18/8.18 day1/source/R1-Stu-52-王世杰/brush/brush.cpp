#include<bits/stdc++.h>
using namespace std;
const int mem=10000000;
int n,m,ans;
int v[10003];
int f[10002][102];
int fm[10002];

int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>v[i];
		ans+=v[i];
	}
	v[n+1]=0;
	if(m==2)
	{
		cout<<ans;
		return 0;
	}
	for(int s=2;s<=m;s++)
	{
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<=m;j++) f[i][j]=mem;
			fm[i]=mem;
		}
		for(int i=1;i<s;i++) 
		{
			f[s][1]=min(f[s][1],v[s]+v[i]);
		}
		fm[s]=f[s][1];
		for(int i=s+2;i<=n+1;i++)
		{
			for(int j=2;j<=m&&i-j>=s;j++)
			{
				for(int k=i-1;k>i-j;k--) f[i][j]=min(f[i][j],v[i]+v[k]+fm[i-j]);
				fm[i]=min(fm[i],f[i][j]);
			}
		}
		ans=min(ans,fm[n+1]);
	}
	cout<<ans;
	return 0;
}
