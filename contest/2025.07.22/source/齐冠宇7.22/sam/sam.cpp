#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=1e9+7;
int k;
struct mat{
	int a[10][10];
	mat(){memset(a,0,sizeof a);}
	void set(){for(int i=0;i<=9;i++)a[i][i]=1;}
}ans,base;
inline mat operator*(const mat& x,const mat& y)
{
	mat res;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
	return res;
}
mat qpow(mat a,int b)
{
	mat res;
	res.set();
	while(b)
	{
		if(b&1)
			res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int sum;
void init()
{
	for(int i=1;i<=9;i++)
		ans.a[i][0]=1;
	for(int i=0;i<=9;i++)
		for(int j=max(i-2,0ll);j<=min(i+2,9ll);j++)
			base.a[i][j]=1;
}
signed main()
{
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	cin>>k;
	init();
	ans=qpow(base,k-1)*ans;
	for(int i=0;i<=9;i++)
		sum=(sum+ans.a[i][0])%mod;
	cout<<sum;
	return 0;
}
