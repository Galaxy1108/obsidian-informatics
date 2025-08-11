#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;
struct Matrix{
	long long a[10][10];
}tran,ini,emt;
Matrix operator*(Matrix x,Matrix y)
{
	Matrix z;
	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++)
		{
			z.a[i][j] = 0;
			for (int k=0;k<10;k++)
				z.a[i][j] = (z.a[i][j] + x.a[i][k]*y.a[k][j]%mod)%mod;
		}
	return z;
}
long long k;
Matrix pw(Matrix x,long long k)
{
	Matrix res = emt;
	while (k)
	{
		if (k&1) res = res*x;
		k>>=1;
		x = x*x;
	}
	return res;
}
int main()
{
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	scanf("%lld",&k);
	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++)
			tran.a[i][j] = (abs(i-j)<=2);
	for (int i=0;i<10;i++)
		emt.a[i][i] = 1;
	for (int i=1;i<10;i++)
		ini.a[0][i] = 1;
	ini = ini*pw(tran,k-1);
	long long ans = 0;
	for (int i=0;i<10;i++)
		ans = (ans + ini.a[0][i])%mod;
	printf("%lld",ans);
	return 0;
}
