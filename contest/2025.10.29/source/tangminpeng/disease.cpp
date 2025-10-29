#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int n,p;
int head[400];
int head2[1000];
struct ways{
	int now,next;
}way[1001],way2[10000];
int ap=1,bp=0,ap1=0;
int fa[400];
int q[400];
int d[400];
int tag[400];
int siz[400],dep[400];
int dis[400];
int S,T;
/*inline bool spfa()
{
	int i,j;
  for(i=1;i<=T;i++)
		{dep[i]=0;}
  for()
	} */
inline void link(int u,int v)
{
  way[++ap].now=u;way[ap].next=head[v];head[v]=ap;
  way[++ap].now=v;way[ap].next=head[u];head[u]=ap;
}
void dfs(int now)
{
	register int y,to,w=0;siz[now]=1;dep[now]=dep[fa[now]]+1;
  for(y=head[now];to=way[y].now,y;y=way[y].next)
		if(fa[now]==to)continue;
    else {d[now]++;dfs(to);siz[now]+=siz[to];}
  for(y=head[now];to=way[y].now,y;y=way[y].next)
    if(fa[now]==to)continue;
		else w=max(siz[to],w);
	 siz[now]-=siz[to];
}
int st[400],top=0;
inline void cut(int x)
{tag[x]=1;
  register int y;
  for(y=head[x];y;y=way[y].next)
		if(fa[x]!=way[y].now)
			cut(way[y].now);
}
void work()
{
  scanf("%d%d",&n,&p);
  int i,j,u,v,x,y,to;
  for(i=1;i<=n;i++)
		{
			scanf("%d%d",&u,&v);
			link(u,v);
    }
  int fir=1,las=1;
  for(fa[q[1]=1]=0;fir<=las;fir++)
		{x=q[fir];
      for(y=head[x];to=way[y].now,y;y=way[y].next)
				if(fa[x]!=to){fa[to]=x;q[++las]=to;}
    }
  dfs(1);
		int maxdep=0,pos;
  for(i=1;i<=n;i++){
		maxdep=max(dep[i],maxdep);
		//printf("i=%d fa=%d dep=%d\n",i,fa[i],dep[i]);
  }
	for(i=1;i<=n;i++)//greedy
		{pos=0;
			for(j=2;j<=maxdep;j++)
				if(dep[j]==dep[i]&&!tag[j])
					if(pos==0||siz[pos]<siz[j])
						pos=j;
			cut(pos);
			}
	  int ans=0;
		for(i=1;i<=n;i++)
			if(dep[i]&&!tag[i])ans++;
		/*for(i=2;i<=maxdep;i++)
		door[i]=++bp;
  for(i=1;i<=n;i++)
		if(dep[i]==0)ans++;
		else {in[i]=++bp;out[i]=++bp;}
  S=++bp;T=++bp;
  for(i=1;i<=n;i++)
		if(dep[i]){
			link(S,in[i],siz[i]);Link(in[i],out[i],0);
			link(out[i],door[dep[i]],0);
   }
  while(SPFA())
	ans+=PICK();*/
  printf("%d\n",ans);
}

int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	work();
  fclose(stdin);
  fclose(stdout);
	return 0;
}
