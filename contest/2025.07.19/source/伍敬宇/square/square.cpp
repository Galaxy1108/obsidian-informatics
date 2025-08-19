#include <cstdio>
using namespace std;
const int SIZE = 1<<21;
const long long mod = 1e9 + 7; 
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin);
	return *(iS++);
}
inline int read()
{
	int x = 0;
	char ch = mget();
	while (ch<'0'||ch>'9') ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x;
}
int p[23] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int n,m;
int a[23];
int breakdown(int x)
{
	int s = 0;
	for (int i=0;i<=18;i++)
	{
		if (x%p[i]) continue ;
		while (x%p[i]==0)
		{
			s ^= (1<<i);
			x = x/p[i];
		}
	}
	return s;
}
long long pw(long long x,int k)
{
	long long res = 1;
	while (k)
	{
		if (k&1) res = res*x%mod;
		k>>=1;
		x = x*x%mod;
	}
	return res;
}
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	n = read();
	for (int i=1;i<=n;i++)
	{
		int v = breakdown(read());
		for (int i=18;i>=0;i--)
		{
			if ((v&(1<<i))==0) continue ;
			if (a[i]==0)
			{
				m++;
				a[i] = v;
				break;
			 }
			else v^=a[i];
		}
	}
	printf("%lld",pw(2,n-m)-1);
	return 0;
}
