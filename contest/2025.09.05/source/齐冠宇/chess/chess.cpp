#include <bits/stdc++.h>
using namespace std;
constexpr int N=105,mod=9999973;
int n,m;
int f[2][N][N][N];
int ans;
inline void add(int& x,int y)
{
	x+=y;
	if(x>mod)x-=mod;
}
inline int mul(int x,int y)
{
	return 1ll*x*y%mod;
}
inline int calc(int x)
{
	return (1ll*x*(x-1)/2)%mod;
}
void print(int t)
{
	for(int j=1;j<=m;j++)
		for(int k=1;k+j<=m;k++)
		{
			int l=m-k-j;
			if(f[t][j][k][l])
				cout<<j<<' '<<k<<' '<<l<<":"<<f[t][j][k][l]<<'\n';
		}
	cout<<"\n";
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int t=0;
	f[t][0][0][m]=1;
#define tt t^1
	for(int i=1;i<=n;i++,t^=1)
	{
		for(int j=0;j<=m;j++)
			for(int k=0;k+j<=m;k++)
			{
				int l=m-k-j;
				add(f[tt][j][k][l],f[t][j][k][l]);
				if(l)
					add(f[tt][j][k+1][l-1],mul(f[t][j][k][l],l));
				if(l>1)
					add(f[tt][j][k+2][l-2],mul(f[t][j][k][l],calc(l)));
				if(k)
					add(f[tt][j+1][k-1][l],mul(f[t][j][k][l],k));
				if(k>1)
					add(f[tt][j+2][k-2][l],mul(f[t][j][k][l],calc(k)));
				if(k && l)
					add(f[tt][j+1][k][l-1],mul(f[t][j][k][l],mul(k,l)));
//				print(tt);
		 	}
		for(int j=0;j<=m;j++)
			for(int k=0;k+j<=m;k++)
			{
				int l=m-k-j;
				f[t][j][k][l]=0;
			}
	}
#undef tt
	for(int j=0;j<=m;j++)
		for(int k=0;k+j<=m;k++)
		{
			int l=m-k-j;
			add(ans,f[t][j][k][l]);
		}
	cout<<ans;
	return 0;
}
