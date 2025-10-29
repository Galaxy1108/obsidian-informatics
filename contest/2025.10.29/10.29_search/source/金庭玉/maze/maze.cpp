#include<bits/stdc++.h>
#define pii std::pair<int, int>
#define fi first
#define se second
#define W while
#define fu(i,a,b) for (int i=a; i<=b; i++)

constexpr int N=15;
constexpr int inf=1e6+2;

inline int read () {
	int a=0; char c=getchar();
	W (!isdigit(c))
		c=getchar();
	W (isdigit(c))
		a=(a<<3)+(a<<1)+(c^48),
		c=getchar();
	return a;
}

int n, m, an[N][N], cr[N][N];
int xx[]={-1, 0, 0, 1}, yy[]={0, -1, 1, 0};
bool p[N][N];

pii q[N*N*N];
int l, r;

signed main () {
freopen("maze.in", "r", stdin);
freopen("maze.out", "w", stdout);

	n=read(), m=read();
	int x=read(), y=read();
	fu (i, 1, n)
		fu (j, 1, m)
			an[i][j]=inf,
			p[i][j]=read();
	if (p[1][1]) {
		std::cout<<0;
		return 0;
	}
				
	q[++r]={1, 1}, cr[1][1]=1, an[1][1]=0;
	pii u, v;
	int w;
	W (l<r) {
		u={q[++l].fi, q[l].se}, w=an[u.fi][u.se]+1;
		fu (k, 0, 3) {
			v={u.fi+xx[k], u.se+yy[k]};
			if (v.fi<1||v.se<1||v.fi>n||v.se>m||p[v.fi][v.se])	continue;
			if (w==an[v.fi][v.se])
				cr[v.fi][v.se]+=cr[u.fi][u.se];
			else if (w<an[v.fi][v.se]) {
				q[++r]=v;
				cr[v.fi][v.se]=cr[u.fi][u.se],
				an[v.fi][v.se]=w;
			}
		}
	}
	std::cout<<cr[x][y];

	return 0;
}
/*

*/
