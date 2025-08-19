#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,k;
long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}
long long dfs(long long x,long long l)
{
	if(x==k+1)
	{
		return l;
	}
	long long s=1;
	for(long long i=1;i<=n;i++)
	{
		s*=dfs(x,lcm(l,i));
		s%=mod; 
	}
	return s;
}
long long jc(long long n)
{
	if(n==1) return 1;
	return n%mod*jc(n-1)%mod; 
}
int main()
{
//	freopen("lcm.in","r",stdin);
//	freopen("lcm.out","w",stdout);
	long long t;
	cin>>t; 
	while(t--)
	{
		cin>>n>>k;
		if(n==1)
		{
			cout<<1<<endl;
		}
		else if(k==1)
		{
			cout<<jc(n)<<endl;
		}
		else if(n==2)
		{
			cout<<pow(2,(int)pow(2,k)-1)<<endl;
		}
		else
		{
			cout<<dfs(1,1)<<endl;
		}
	}
}
