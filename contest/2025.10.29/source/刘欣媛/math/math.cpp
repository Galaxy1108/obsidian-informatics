#include <bits/stdc++.h>
using namespace std;
long long  a,b;
inline long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
inline long long lcm(long long a,long long b)
{
	long long l=a*(b/gcd(a,b));
	
	return l;
}
long long tot,c[100005];
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a>>b;
	long long o=2;
	int e=gcd(a,b);
	a/=e,b/=e;
	while(1)
	{
		if(a==1)
		{
			c[++tot]=b;
			break;
		}
		long long p=b/a;
		while(o<p)
		{
			o*=2;
		}
		
		c[++tot]=o;
		p=lcm(o,b);
		a*=(p/b);
		b=p,a-=p/o;
		p=gcd(a,b),a/=p,b/=p;
	}
	cout<<tot<<"\n";
	for(int i=1;i<=tot;i++) cout<<c[i]<<" ";
	
	
	return 0;
 } 
