#include<bits/stdc++.h>
using namespace std;
const int mx=43;
const int mod=998244353;
int n,w;
long long ksm(long long x,long long y)
{
	long long res=1;
	while(y)
	{
		if(y%2==1) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int p[mx],a[mx];
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin>>n>>w;
	for(int i=1;i<=w;i++) cin>>p[i]>>a[i];
	cout<<ksm(n,mod-2);
	return 0;
}
