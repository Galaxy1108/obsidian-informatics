#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctime>
#define N 1005
using namespace std;
int n,ans,head[N],len,siz[N],sz[N],w[N][N],m[N],f[N];
struct way{ int num,next;}G[N*2+5];
void dfs(int t,int fa)
{
	int i; sz[t]=1,siz[t]=0,f[t]=fa;
	for(i=head[t];i;i=G[i].next)
		if(G[i].num!=fa){
			dfs(G[i].num,t);
			sz[t]+=sz[G[i].num];
			siz[t]=max(siz[t],sz[G[i].num]);
		  }
}
bool cmp(int x,int y){ return sz[x]-siz[x]>sz[y]-siz[y];}
void search(int t,int sum)
{
	int i,S=0,p,j;
	if(clock()>0.93*CLOCKS_PER_SEC) return; 
	for(i=1;i<=m[t];i++)
		S+=sz[w[t][i]]-1;
	if(!S){ ans=max(ans,sum); return ;}
	if(S+sum<=ans) return ;
	m[t+1]=0;
	for(i=1;i<=m[t];i++)
		for(j=head[w[t][i]];j;j=G[j].next)
			if(G[j].num!=f[w[t][i]])
				w[t+1][++m[t+1]]=G[j].num;
	sort(w[t+1]+1,w[t+1]+m[t+1]+1,cmp);
	for(i=1;i<=m[t+1];i++){
		p=w[t+1][i];
		for(j=i;j<m[t+1];j++)
			w[t+1][j]=w[t+1][j+1];
		m[t+1]--;
		search(t+1,sum+sz[p]);
		m[t+1]++;
		for(j=m[t+1];j>i;j--)
			w[t+1][j]=w[t+1][j-1];
		w[t+1][i]=p;
	  }
}
int main()
{
	int i,x,y,xyk;
	freopen("disease.in","r", stdin);
	freopen("disease.out","w",stdout);
	scanf("%d %d",&n,&xyk);
	for(i=1;i<=xyk;i++){
		scanf("%d %d",&x,&y);
		G[++len]=(way){y,head[x]},head[x]=len;
		G[++len]=(way){x,head[y]},head[y]=len;
	  }
	dfs(1,0);
	w[1][m[1]=1]=1;
	search(1,0);
	cout<<n-ans;
	return 0;
}
