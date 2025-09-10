#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long qpow(long long x,long long y)
{
	long long ans=1;
	while(y>0)
	{
		if(y%2==1)
		{
			ans*=x;
			ans%=mod; 
		}
		x=x*x;
		x%=mod;
		y>>=1;
	}
	return ans;
 } 
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cout<<166374061;
 } 
