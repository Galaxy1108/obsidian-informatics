#include <cstdio>
#define decode asdfghj 
#define encode ujgyhy 
using namespace std;
const long long mod = 1e9 + 7;
int n,k,a[212];
struct Node{
	int bas[8];
};
inline int encode(Node x)
{
	int res = 0,fct = 1;
	for (int i=1;i<=k;i++)
	{
		fct *= i;
		res += x.bas[i]*fct;
	}
	return res;
}
inline Node decode(int x)
{
	Node res;
	int fct = 1;
	for (int i=1;i<=k;i++)
	{
		fct *= i;
		res.bas[i] = (x%(fct*(i+1)))/fct;
	}
	return res;
}
inline void upd(long long&x,long long y)
{
	x += y;
	if (x>=mod) x -= mod;
}
Node cur;
long long g[100000+12],f[100000+12];
int fctk,s;
void dfs(int i,int sum)
{
	if (sum<0||sum>k-i+1) return ;
	if (i>k)
	{
		upd(f[encode(cur)],g[s]);
		return ;
	}
	if (cur.bas[i]<k)
	{
		cur.bas[i]++;
		dfs(i+1,sum-1);
		cur.bas[i]--;
	}
	dfs(i+1,sum);
}
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	fctk = 1;
	for (int i=1;i<=k+1;i++) fctk *= i;
	g[0] = 1;
	for (int i=1;i<=n;i++)
	{
		for (s=0;s<fctk;s++)
		{
			if (g[s]==0) continue ;
			cur = decode(s);
			int sum = a[i];
			for (int i=k;i>=2;i--)
			{
				cur.bas[i] = cur.bas[i-1];
				sum -= cur.bas[i-1];
			}
			cur.bas[1] = 0;
			if (sum<0||sum>k) continue ;
			dfs(1,sum);
		}
		for (s=0;s<fctk;s++)
		{
			g[s] = f[s];
			f[s] = 0;
		}
	}
	long long ans = 0;
	for (s=0;s<fctk;s++)
		upd(ans,g[s]);
	printf("%lld",ans);
	return 0;
}
