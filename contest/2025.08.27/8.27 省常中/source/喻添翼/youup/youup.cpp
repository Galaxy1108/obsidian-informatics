#include<bits/stdc++.h>
using namespace std;
const int mx=3e5+10;
const int mod=998244353;
long long inv[mx],fac[mx];
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b%2==1) res=res*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return res;
}
long long C(int a,int b)
{
	return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
vector<int> e[mx];
int Num,n,x;
int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	cin>>Num;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++) inv[i]=ksm(fac[i],mod-2);
	if(Num==1) 
	{
		cout<<n<<' ';
		for(int i=2;i<=n;i++) cout<<0<<' ';
	}
	if(Num==4)
	{
		if(x==0)
		{
			cout<<n<<' ';
			for(int i=2;i<=n;i++) cout<<0<<' ';
		}
		else if(x==1)
		{
			cout<<n<<' '<<n-1<<' ';
			for(int i=3;i<=n;i++) cout<<0<<' ';
		}
		else if(x>=2)
		{
			for(int i=1;i<=n;i++) cout<<C(n,i)<<' ';
		}
	}
	if(Num==5)
	{
		for(int i=1;i<=min(x,n);i++) cout<<n-i+1<<' ';
		for(int i=x+1;i<=n;i++) cout<<0<<' ';
	}
	return 0;
} 
