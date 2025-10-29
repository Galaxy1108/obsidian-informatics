#include <cstdio>
using namespace std;
const int MAXN = 600+12;
const int mod = 1e9 + 7;
int n,a[MAXN],dic[MAXN],cnt;
int tp[MAXN],s[MAXN];
long long f[MAXN][MAXN>>1][MAXN>>1];
//                ·ÙÉÕÂ¯    ÆøÇòÊý 
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout); 
	scanf("%d",&n);
	for (int i=1;i<=(n<<1);i++) scanf("%d",a+i);
	for (int i=1;i<=n;i++)
		if (a[(i<<1)-1]!=-1&&a[i<<1]!=-1)
			dic[a[(i<<1)-1]] = dic[a[i<<1]] = -1;
	for (int i=1;i<=(n<<1);i++)
		if (dic[i]!=-1)
			dic[i] = ++cnt;
	for (int i=1;i<=(n<<1);i++)
		if (a[i]!=-1)
			if (dic[a[i]]!=-1)
				tp[dic[a[i]]] = 1;
	n = cnt;
	for (int i=1;i<=n;i++) s[i] = s[i-1] + tp[i];
	f[0][0][0] = 1;
	for (int i=1;i<=n;i++)
	{
		if (tp[i])
		{
			for (int j=0;j<=(n>>1);j++)
				for (int k=1;k<=(n>>1);k++)
					f[i][j][k-1] = (f[i][j][k-1] + f[i-1][j][k]*k)%mod;
			for (int j=0;j<=(n>>1);j++)
				for (int k=0;k<=(n>>1);k++)
					f[i][j+1][k] = (f[i][j+1][k] + f[i-1][j][k])%mod;
		}
		else
		{
			for (int j=1;j<=(n>>1);j++)
				for (int k=0;k<=(n>>1);k++)
					f[i][j-1][k] = (f[i][j-1][k] + f[i-1][j][k])%mod;
			for (int j=0;j<=(n>>1);j++)
				for (int k=0;k<=(n>>1);k++)
					f[i][j][k+1] = (f[i][j][k+1] + f[i-1][j][k])%mod;
			for (int j=0;j<=(n>>1);j++)
				for (int k=0;k<=(n>>1);k++)
					if (f[i-1][j][k])
					{
						int cnt1 = s[i-1];
						int cnt0 = i-1-cnt1;
						int tar = cnt1 - cnt0;
						int cur = j - k;
						int off = (cur-tar)/2;
						int chs = n/2 - s[n] - off;
						if (chs>0)
							f[i][j+1][k] = (f[i][j+1][k] + f[i-1][j][k]*chs)%mod;
					}
		}
	}
	long long res = f[n][0][0];
	printf("%lld",res);
	return 0;
}
