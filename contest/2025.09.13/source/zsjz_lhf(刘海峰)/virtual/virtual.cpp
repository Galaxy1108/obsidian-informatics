#include<cstdio>
using namespace std;
const int N=2e6+10;
void output(bool p)
{
	if(p) putchar('Y'),putchar('e'),putchar('s');
	else putchar('N'),putchar('o');
	putchar('\n');
}
inline char gc()
{
	static char buf[1<<20],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++;
}
inline int rd()
{
	register int a=0,c=0;
	while(c>'9'||c<'0') c=gc();
	while(c>='0'&&c<='9') a=(a<<3)+(a<<1)+(c&15),c=gc();
	return a;
}
struct edge{
	int next,to;
}e[N<<1];
int vis[N],cnt,id[N],f[N],first[N],len;
void merge(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len;
	e[++len]=edge{first[b],a};
	first[b]=len;
}
char c;
int n,L,R,fa[N],p[N];
int getfa(int a){return a==fa[a]?a:(fa[a]=getfa(fa[a]));}
int g(int w)
{
	if(w>id[n]) return n+1;
	if(w<0) w=0;
	return f[w];
}
void dfs(int x)
{
	fa[x]=getfa(x+1);
	int w=id[x];
	for(int i=getfa(g(w-R)+1);i<=g(w-L+1);i=getfa(i)) merge(i,x),dfs(i);
	if(!p[x]) w--;
	for(int i=getfa(g(w+L));i<g(w+R+1);i=getfa(i)) merge(i,x),dfs(i);
}
void dfs2(int x)
{
	for(int i=first[x],y;i;i=e[i].next)
		if(!vis[y=e[i].to]) vis[y]=vis[x],dfs2(y);
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	n=rd(),L=rd(),R=rd();
	while(c!='a'&&c!='b') c=gc();
	for(int i=1;i<=n;i++) p[i]=c-'a',c=gc();
	for(int i=1;i<=n;i++)
		if(!p[i]) id[i]=id[i-1]+1,f[id[i]]=i;
		else id[i]=id[i-1];
	for(int i=1;i<=n+1;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
		if(fa[i]==i) dfs(i);
	for(int i=1;i<=n;i++)
		if(!vis[i]) vis[i]=++cnt,dfs2(i);
	int Q=rd();
	while(Q--) output(vis[rd()]==vis[rd()]);
}