#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
constexpr int N=305,inf=1e18;
bool m1;
int n,q;
int a[N][N];
namespace bf
{
	int f[N][N];
	void solve()
	{
		while(q--)
		{
			int sx,sy,ex,ey;
			cin>>sx>>ex>>sy>>ey;
			for(int i=sx;i<=ex;i++)
				for(int j=sy;j<=ey;j++)
					f[i][j]=inf;
			f[sx][sy]=a[sx][sy];
			for(int i=sx;i<=ex;i++)
				for(int j=sy;j<=ey;j++)
				{
					if(i^ex)
						f[i+1][j]=min(f[i+1][j],f[i][j]+a[i+1][j]);
					if(j^ey)
						f[i][j+1]=min(f[i][j+1],f[i][j]+a[i][j+1]); 
				}
			cout<<f[ex][ey]<<'\n';
		}
	}
}
namespace sub
{
	constexpr int NN=205,Q=1e5+5;
	int l[NN][NN][NN],r[NN][NN][NN];
	int d[NN][NN][NN],f[NN][NN];
	struct node{
		int sx,sy,ex,ey;
	}as[Q];
	void init()
	{
		memset(f,0x3f,sizeof f);
		memset(d,0x3f,sizeof d);
		memset(l,0x3f,sizeof l);
		memset(r,0x3f,sizeof r);
	}
	void calcl(int x,int y)
	{
		l[x][x][y]=a[x][y];
		for(int i=x;i;i--)
		{
			for(int j=y;j;j--)
			{
				if(i)l[x][i-1][j]=min(l[x][i-1][j],a[i-1][j]+l[x][i][j]);
				if(j)l[x][i][j-1]=min(l[x][i][j-1],a[i][j-1]+l[x][i][j]);
			}
		}
	}
	void calcr(int x,int y)
	{
		r[x][x][y]=a[x][y];
		for(int i=x;i<=n;i++)
		{
			for(int j=y;j<=n;j++)
			{
				if(i^n)r[x][i+1][j]=min(r[x][i+1][j],a[i+1][j]+r[x][i][j]);
				if(j^n)r[x][i][j+1]=min(r[x][i][j+1],a[i][j+1]+r[x][i][j]);
			}
		}
	}
	void calc(int x,int y)
	{
		d[y][x][y]=a[x][y];
		for(int i=x;i<=n;i++)
		{
			for(int j=y;j<=n;j++)
			{
				if(i^n)d[y][i+1][j]=min(d[y][i+1][j],a[i+1][j]+d[y][i][j]);
				if(j^n)d[y][i][j+1]=min(d[y][i][j+1],a[i][j+1]+d[y][i][j]);
			}
		}
	}
	void solve()
	{
		init();
		int fl=1,fl1=1;
		for(int i=1;i<=q;i++)
			cin>>as[i].sx>>as[i].ex>>as[i].sy>>as[i].ey,fl&=(as[i].sx==1),fl1&=(as[i].sx<=n/2 && as[i].ex>=n/2);
		if(fl1)
		{
			for(int i=1;i<=n;i++)
				calcl(i,n/2),calcr(i,n/2);
			for(int i=1;i<=q;i++)
			{
				int sx=as[i].sx,sy=as[i].sy,ex=as[i].ex,ey=as[i].ey;
				int ans=inf;
				for(int i=1;i<=n;i++)
					ans=min(ans,l[i][sx][sy]+r[i][ex][ey]-a[i][n/2]);
				cout<<ans<<'\n';
			}
		}
		else if(fl)
		{
			for(int i=1;i<=n;i++)
				calc(1,i);
			for(int i=1;i<=q;i++)
			{
				int sx=as[i].sx,sy=as[i].sy,ex=as[i].ex,ey=as[i].ey;
				cout<<d[sy][ex][ey]<<'\n';
			}
		}
		else
		{
			for(int i=1;i<=q;i++)
			{
				int sx=as[i].sx,sy=as[i].sy,ex=as[i].ex,ey=as[i].ey;
				for(int i=sx;i<=ex;i++)
					for(int j=sy;j<=ey;j++)
						f[i][j]=inf;
				f[sx][sy]=a[sx][sy];
				for(int i=sx;i<=ex;i++)
					for(int j=sy;j<=ey;j++)
					{
						if(i^ex)
							f[i+1][j]=min(f[i+1][j],f[i][j]+a[i+1][j]);
						if(j^ey)
							f[i][j+1]=min(f[i][j+1],f[i][j]+a[i][j+1]); 
					}
				cout<<f[ex][ey]<<'\n';
			}
		}
	}
}
bool m2;
signed main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	cerr<<fabs(&m1-&m2)/1024.0/1024.0<<"MB";
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	if((n<=100 && q<=100) || (200<n))
		return bf::solve(),0;
	else
		return sub::solve(),0;
	return 0;
}
