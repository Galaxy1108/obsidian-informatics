#include <cstdio>
using namespace std;
const int MAXN = 20;
const int mod = 1e9 + 7;
int f[MAXN+5][2<<MAXN],g[MAXN+5][2<<MAXN];
inline void upd(int&x,int y)
{
	x += y;
	if (x>=mod) x -= mod;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline int count(int s)
{
	int cnt = 0;
	while (s)
	{
		cnt ++;
		s -= lowbit(s);
	}
	return cnt;
}
int n,s[MAXN];
int main()
{
	freopen("ruin.in","r",stdin);
	freopen("ruin.out","w",stdout);
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		s[x] = 1;
	}
	f[n+1][0] = 1;
	int cnt0=0,cnt1=0;
	for (int i=1;i<=n*2;i++)
	{
		for (int p=0;p<(1<<n);p++)
		{
			if (count(p)!=cnt0) continue ;
			for (int j=n+1;j>=1;j--)
			{
				if (s[i]==0)
				{
					for (int k=1;k<j;k++)
						if ((p&(1<<(k-1)))==0)
							upd(g[j][p|(1<<(k-1))],f[j][p]);
				}
				else 
				{
					if(n-j+1-cnt1>0) upd(g[j][p],1ll*f[j][p]*(n-j+1-cnt1)%mod);
					for (int k=1;k<j;k++)
						upd(g[k][p],f[j][p]);
				}
			}
		}
		if (s[i]==0) cnt0++;
		else cnt1++;
		for (int p=0;p<(1<<n);p++)
			for (int j=n+1;j>=1;j--)
			{
				f[j][p] = g[j][p];
				g[j][p] = 0;
			}
	}
	printf("%d",f[1][(1<<n)-1]);
	return 0;
}
