#include <iostream>
using namespace std;
long long n,x,p;
int m;
long long a[1000+12],C[1000+12][1000+12];
long long f(long long x)
{
	long long cur = 1;
	long long ans = 0;
	for (int i=0;i<=m;i++)
	{
		ans = (ans + a[i]*cur%p)%p;
		cur = cur*x%p;
	}
		
	return ans;
}
void work1()
{
	C[0][0] = 1;
	for (int i=1;i<=1000;i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j=1;j<i;j++)
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%p;
	}
	long long cur = 1,sum = 0;
	for (int k=0;k<=n;k++)
	{
		sum = (sum + cur*f(k)%p*C[n][k])%p;
		cur = cur*x%p;
	}
	cout << sum;
}
long long pw(long long x,int k)
{
	long long res = 1;
	while (k)
	{
		if (k&1) res = res*x%p;
		k>>=1;
		x = x*x%p;
	 } 
	return res;
}
void work2()
{
	cout << a[0]*pw((x+1)%p,n)%p;
}
int main()
{
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	cin >> n >> x >> p >> m;
	for (int i=0;i<=m;i++)
		cin >> a[i];
	if (n<=1000&&m<=1000) work1();
	else work2();
	return 0;
}
