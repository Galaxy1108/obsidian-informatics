#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,x,p,m,ary[N],fac[N],C[1005][1005];
int ftp(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int inv(int x){return ftp(x,p-2,p);}
int Cx(int n,int m){return fac[n]*inv(fac[m])%p*inv(fac[n-m])%p;}
signed main()
{
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	cin>>n>>x>>p>>m;
	fac[0]=1;
	for(int i=1;i<=1000;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	}
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%p;
	if(m!=0||(n<=1000&&m<=1000))
	{
		for(int i=0;i<=m;i++)cin>>ary[i];
		int ans=0;
		for(int k=0;k<=n;k++)
		{
			int fk=0;
			for(int i=0;i<=m;i++)fk=(fk+ary[i]*ftp(k,i,p)%p)%p;
			int fr=ftp(x,k,p);
			int fc=C[n][k];
			ans+=(fk*fr%p*fc%p);
			ans%=p;
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int k=0;k<=n;k++)
	{
		int fk=ary[0];
		int fr=ftp(x,k,p);
		int fc=Cx(n,k);
		ans+=(fk*fr%p*fc%p);
		ans%=p;
	}
	cout<<ans;
	
	return 0;
}
