#include <cstdio>
using namespace std;
const int MAXN = 105;
int n,m,k;
long long mod;
long long C[MAXN][MAXN],pw[MAXN*MAXN];
long long a[MAXN][MAXN];
inline void upd(long long&x,long long y)
{
	x += y;
	if (x>=mod) x -= mod;
}
void init()
{
	C[0][0] = 1;
	for (int i=1;i<=100;i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j=1;j<i;j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
	}
	pw[0] = 1;
	for (int i=1;i<=10000;i++) pw[i] = pw[i-1]*2%mod;
	a[0][0] = 1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			for (int t=0;t<=i;t++)
				for (int s=0;s<=j;s++)
					if ((t+s)%2==0) upd(a[i][j],pw[(i-t)*(j-s)]*C[i][t]%mod*C[j][s]%mod);
					else upd(a[i][j],mod-pw[(i-t)*(j-s)]*C[i][t]%mod*C[j][s]%mod);
		}
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d %d %d %lld",&n,&m,&k,&mod);
	if (k==1)
	{
		printf("1");
		return 0;
	}
	init();
	long long ans = 0;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
			upd(ans,C[n][i]*C[m][j]%mod*a[n-i][m-j]%mod*pw[i*j]%mod);
	printf("%lld",ans);
	return 0;
}
