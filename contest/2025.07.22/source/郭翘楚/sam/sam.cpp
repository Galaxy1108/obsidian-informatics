#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
struct matrix{
	long long v[10][10];
};
matrix operator * (const matrix a,const matrix b)
{
	matrix c;
	memset(c.v,0,sizeof(c.v));
	for(int k=0;k<=9;k++)
	{
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			{
				c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j]%mod)%mod;
			}
		}
	}
	return c;
}
matrix qpow(matrix a,long long v)
{
	matrix r;
	memset(r.v,0,sizeof(r.v));
	for(int i=0;i<=9;i++)
	{
		r.v[i][i]=1;
	}
	while(v)
	{
		if(v&1) r=r*a;
		a=a*a;
		v>>=1;
	}
	return r;
}
matrix a,d;
int main()
{
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	long long k,ans=0;
	cin>>k;
	if(k==1)
	{
		cout<<10;
		return 0;
	}
	memset(a.v,0,sizeof(a.v));
	memset(d.v,0,sizeof(d.v));
	for(int i=0;i<=9;i++)
	{
		a.v[0][i]=1;
	}
	for(int i=0;i<=9;i++)
	{
		for(int j=max(0,i-2);j<=min(9,i+2);j++)
		{
			d.v[j][i]=1;
		}
	}
	a=a*qpow(d,k-1);
	for(int i=1;i<=9;i++)
	{
		ans+=a.v[0][i];
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}
