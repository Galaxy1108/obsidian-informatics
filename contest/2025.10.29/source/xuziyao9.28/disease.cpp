#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define N 305
#define orz 2000000000
using namespace std;
inline int read( )
{
  int sum=0;char c=getchar( );bool f=0;
  while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
	return sum;
}
int n,m,maxd;
struct ex{int num,next;}map[N*2];
int head[N],len;
inline void link(int x,int y)
{
	len++;map[len].num=y;map[len].next=head[x];head[x]=len;
	len++;map[len].num=x;map[len].next=head[y];head[y]=len;
}
int son[N][N],ls[N];
int dek[N][N],ld[N];
inline void dfs(int k,int p,int d)
{
	maxd=max(maxd,d);
	dek[d][++ld[d]]=k;
	int i,x;
	for(i=head[k];i;i=map[i].next)
		{
			x=map[i].num;
			if(x==p) continue;
			dfs(x,k,d+1);
			son[k][++ls[k]]=x;
		}
}
bool gr[N];
int ans=orz;
inline void DFS(int d,int inc)
{
	int i,j,x,sum=0;
	for(i=1;i<=ld[d];i++)
		{
			x=dek[d][i];
			if(gr[x])
				{
					sum++;
					for(j=1;j<=ls[x];j++) gr[son[x][j]]=1;
				}
		}
	if(!sum||d==maxd) {ans=min(ans,inc+sum);return;}
	if(inc+sum>=ans) return;
	inc=inc+sum;
	for(i=1;i<=ld[d];i++)
		{
			x=dek[d][i];
			if(gr[x])
				for(j=1;j<=ls[x];j++)
					{
						gr[son[x][j]]=0;
						DFS(d+1,inc);
						gr[son[x][j]]=1;
					}
		}
	for(i=1;i<=ld[d];i++)
		{
			x=dek[d][i];
			if(gr[x])
				for(j=1;j<=ls[x];j++) gr[son[x][j]]=0;
		}
}

int main( )
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	int i,j,x,y;
	n=read( );m=read( );
	for(i=1;i<=m;i++) x=read( ),y=read( ),link(x,y);
	dfs(1,1,1);
	gr[1]=1;DFS(1,0);
	printf("%d",ans);
	return 0;
}
