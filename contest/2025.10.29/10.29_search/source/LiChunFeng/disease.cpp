#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define N 410

using namespace std;
typedef long long llg;

int n,m,d[N][N],now=1,l[N],ans=N,fa[N];
int head[N],next[N<<1],to[N<<1],tt,siz[N];
bool w[N][N];

int getint(){
	int w=0;bool q=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') c=getchar(),q=1;
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}

bool cmp(int x,int y){return siz[x]>siz[y];}
void link(int x,int y){
	to[++tt]=y;next[tt]=head[x];head[x]=tt;
	to[++tt]=x;next[tt]=head[y];head[y]=tt;
}

void dfs(int u){
	l[u+1]=0;
	for(int k=1;k<=l[u];k++)
		if(!w[u][k]){
			for(int i=head[d[u][k]],v;v=to[i],i;i=next[i])
				if(v!=fa[d[u][k]]) d[u+1][++l[u+1]]=v;
		}
	if(l[u+1]<=1){
		ans=min(ans,now);
		return;
	}
	if(now>=ans-l[u+1]+1) return;
	sort(d[u+1]+1,d[u+1]+l[u+1]+1);
	now+=l[u+1]-1;
	for(int i=1;i<=l[u+1];i++){
		w[u+1][i]=1; dfs(u+1);
		w[u+1][i]=0;
	}
	now-=l[u+1]-1;
}

void work(int u){
	siz[u]=1;
	for(int i=head[u],v;v=to[i],i;i=next[i])
		if(!siz[v]) fa[v]=u,work(v),siz[u]+=siz[v];
}

int main(){
	File("disease");
	n=getint(); m=getint();
	while(m--) link(getint(),getint());
	work(1); d[1][++l[1]]=1; dfs(1);
	printf("%d",ans);
}
