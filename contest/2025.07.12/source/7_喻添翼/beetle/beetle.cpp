#include<bits/stdc++.h>
using namespace std;
const int mx=2500010;
const int mod=1e9+7;
long long s[mx];
long long f[mx];
int n,k;
long long ksm(int x,int y)
{
	long long ans=1;
	while(y>0)
	{
		if(y%2!=0) ans*=x;
		ans%=mod;
		x=x*x%mod;
		y/=2;
	}
	return 0;
}
long long Max[mx];
int getmax(int l,int r)
{
	long long ans=0;
	for(int i=l;i<=r;i++) ans=max(ans,s[i]);
	return ans;
}
int main()
{
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin>>n>>k;
	Max[0]=0;
	for(int i=1;i<=n;i++) cin>>s[i],Max[i]=max(s[i],Max[i-1]);
	for(int i=1;i<=n;i++) f[i]=1e18;
	f[1]=s[1];              
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=k-1;j++)
		{
			if(i-j>0)
			{
				if(Max[i-j]!=Max[i])
				f[i]=min(f[i-j]+Max[i],f[i]);
				else
				{
					f[i]=min(f[i-j]+getmax(i-j+1,i),f[i]);
				}
			} 
		}
	
	}
	for(int i=1;i<=n;i++) cout<<f[i]<<endl;
	return 0;
}

