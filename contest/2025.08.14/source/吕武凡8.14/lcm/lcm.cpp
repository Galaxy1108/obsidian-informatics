#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int e[1000100],f[1000100];
int g[1000100];
int p[300];
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	int k=gcd(a,b);
	return a/k*b;
}
void ef(int x)
{
	e[1]=1,f[1]=1;
	for(int i=2;i<=x;i++)
	{
		e[i]=e[i-1]+2*f[i-1];
		f[i]=e[i-1]+f[i-1];
	}
}
void cag(int x)
{
	int pre=1;
	for(int i=1;i<=x;i++)
	{
		g[i]=lcm(pre,f[i]);
		pre=g[i];	
	}	
}
signed main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	int t=0;
	cin>>t;
	int x[300];
	int sum=0;
	int maxn=0;
	for(int i=1;i<=t;i++)
	{
		cin>>x[i]>>p[i];
		maxn=max(maxn,x[i]);
	} 
	ef(maxn);
	cag(maxn);
	sum=0;
	int n,mod;
	for(int i=1;i<=t;i++)
	{
		sum=0;
		n=x[i];
		mod=p[i];
		for(int j=1;j<=n;j++)
		{
			sum+=j*g[j]%mod;
			sum%=mod;
		}
		cout<<sum%mod<<endl;
	}
	
		
} 
