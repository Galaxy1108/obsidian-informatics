#include<bits/stdc++.h>
using namespace std;
const int mx=3e3+10;
long long inv[mx],fac[mx],f[mx];
int n,p;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b%2==1) res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res;
}
long long getsum(long long x)
{
	long long sum=0;
	for(long long i=1;i<=x;i++) 
	if(x%i==0) sum=(i+sum)%p;
	return sum;
}
long long ans=0;
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	cin>>n>>p;
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;

	for(int i=1;i<=n;i++) inv[i]=ksm(fac[i],p-2);
	for(int i=1;i<=n;i++) f[i]=1;
	for(int i=1;i<=n;i++) 
		for(int j=0;j<=i;j++)
			f[i]=f[i]*fac[i]%p*inv[j]%p*inv[i-j]%p;
	
	for(int i=1;i<=n;i++)
	{
		ans=(ans+getsum(f[i]))%p;
	}
	cout<<ans;
	return 0;
} 
