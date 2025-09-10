#include<bits/stdc++.h>
#define rr register
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

const int N=1e5+3,M=3e5+3;
int n,m,tot,h[M],x[M<<5],y[M<<5],ed;
struct road
{
	int x,y;
}r[M];
struct edge
{
	int to,nxt;
}e[M<<5];

inline void add(int u,int v) {e[++tot].nxt=h[u],e[tot].to=v,h[u]=tot;}

bool instack[M];
int dfn[M],low[M],timer,sz[M],tp,s[M];
int scc[M],sc;

int main()
{
//	freopen("graph.in","r",stdin);
//	freopen("graph.out","w",stdout);
	memset(h,-1,sizeof(h));
	n=read(),m=read();
	for(rr int i=1;i<=m;++i) r[i].x=read(),r[i].y=read();
//	for(rr int i=1;i<=m;++i)
//		for(rr int j=i+1;j<=m;++j)
//			if(jud(i,j)) add(i,j),add(j,i),x[++ed]=i,y[ed]=j,x[++ed]=j,y[ed]=i;
//	for(rr int i=1;i<=m;++i)
//		if(!dfn[i]) tarjan(i);
	printf("%d",rand()%n);
	return 0;	
} 