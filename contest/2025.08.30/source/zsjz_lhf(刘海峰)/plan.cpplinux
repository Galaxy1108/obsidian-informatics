#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=501,M=1e6+10,inf=1044266559;
struct edge{
	int next,to;
}e[N<<1];
int first[N],len,tr[N][N],b[N],id[M],a[N];
void add(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len;
}
struct node{
	int x,y,v;
}tt[N*N];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void getmax(int &a,int b){if(a<b) a=b;}
int cnt,tot;
void work(int a,int x)
{
	cnt=tot=0;
	for(int i=1;i*i<=a;i++)
		if(a%i==0)
		{
			b[id[i]=++cnt]=i;
			if(i*i!=a) b[id[a/i]=++cnt]=a/i;
		}
	for(int i=1;i<=cnt;i++) tr[i][0]=i;
	for(int i=1;i*i<=x;i++)
		if(x%i==0)
		{
			tot++;
			for(int j=1;j<=cnt;j++)
				tr[j][tot]=id[gcd(i,b[j])];
			if(i*i==x) break;
			tot++;
			for(int j=1;j<=cnt;j++)
				tr[j][tot]=id[gcd(x/i,b[j])];
		}
}
int siz[N],K,f[N][N-1][241],g[N][N],fa[N],ans;
void init(int x)
{
	cnt=0;
	for(int i=1;i*i<=x;i++)
		if(x%i==0)
		{
			b[++cnt]=i;
			if(i*i!=x) b[++cnt]=x/i;
		}
}
void dfs(int x)
{
	siz[x]=1;
	f[x][0][1+(a[x]>1)]=0;
	for(int i=first[x],y;i;i=e[i].next)
		if((y=e[i].to)!=fa[x])
		{
			fa[y]=x,dfs(y);
			work(a[x],a[y]);
			len=0;
			for(int i=0;i<=siz[x];i++)
				for(int j=0;j<=cnt;j++)
				{
					g[i][j]=f[x][i][j],f[x][i][j]=-inf;
					if(g[i][j]>=0) tt[++len]=(node){i,j,g[i][j]};
				}
			for(int j=0;j<=siz[y];j++)
				for(int q=0;q<=tot;q++)
					if(f[y][j][q]>=0)
						for(int i=1;i<=len;i++)
							if(tt[i].x+j>K) break;
							else getmax(f[x][tt[i].x+j][tr[tt[i].y][q]],tt[i].v+f[y][j][q]);
			siz[x]=min(siz[x]+siz[y],K);
		}
	init(a[x]);
	if(x!=1)
	{
		for(int i=0;i<siz[x];i++)
			for(int j=1;j<=cnt;j++)
				getmax(f[x][i+1][0],f[x][i][j]+b[j]);
	}
	else
	{
		for(int i=1;i<=len;i++)
			getmax(ans,f[x][K][i]+b[i]);
	}
}
int main()
{
	memset(f,-0x3f,sizeof(f));
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	int n,x,y;
	scanf("%d%d",&n,&K);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=-inf,dfs(1);
	printf("%d",ans);
}