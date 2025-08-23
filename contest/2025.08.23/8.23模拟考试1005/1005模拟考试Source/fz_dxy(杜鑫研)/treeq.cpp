#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define re int
inline int read(){
	int x=0,ff=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')ff=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*ff;
}
int n,nt[2000005],to[2000005],h[1000005],tot,vl[2000005],dfn[1000005],sz[1000005],f[1000005];
inline void add(int x,int y,int z){
	nt[++tot]=h[x];h[x]=tot;to[tot]=y;vl[tot]=z;
}
vector<int>qwq[1000005],awa[1000005];
int sf[1000005],pr[1000005];
struct tt{
	int id,x,y;
};
vector<tt>q[1000005];
long long d[2000005];
int cnt;
void pre(int i,int la){
	dfn[i]=++tot;sz[i]=1;
	for(re j=h[i];j;j=nt[j]){
		if(to[j]==la)continue;
		pre(to[j],i);sz[i]+=sz[to[j]];
		d[++cnt]=1ll*vl[j]*(n-sz[to[j]]);
		d[++cnt]=1ll*vl[j]*sz[to[j]];
	}
}
void dfs(int i,int la){int u,v;
	for(re j=h[i];j;j=nt[j]){
		if(to[j]==la)continue;
		dfs(to[j],i);long long x=1ll*vl[j]*(n-sz[to[j]]);
		u=lower_bound(d+1,d+cnt+1,x)-d;
		x=1ll*vl[j]*sz[to[j]];
		v=lower_bound(d+1,d+cnt+1,x)-d;
		qwq[dfn[to[j]]].push_back(u);
		awa[dfn[to[j]]+sz[to[j]]].push_back(u);

		sf[dfn[to[j]]-1]=max(sf[dfn[to[j]]-1],v);
		pr[dfn[to[j]]+sz[to[j]]]=max(pr[dfn[to[j]]+sz[to[j]]],v);

		q[dfn[to[j]]-1].push_back((tt){to[j],u,-1});
		q[dfn[to[j]]+sz[to[j]]-1].push_back((tt){to[j],u,1});
		q[dfn[to[j]]-1].push_back((tt){to[j],v,1});
		q[dfn[to[j]]+sz[to[j]]-1].push_back((tt){to[j],v,-1});
		q[n].push_back((tt){to[j],v,1});
	}
}
priority_queue<int>dl,pl;
int p[2000005];
int main(){
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	n=read();int x,y;
	for(re i=2;i<=n;i++){
		x=read();y=read();add(x,i,y);add(i,x,y);
	}tot=0;
	pre(1,0);sort(d+1,d+cnt+1);cnt=unique(d+1,d+cnt+1)-d-1;
	dfs(1,0);
	for(re i=1;i<=n;i++)pr[i]=max(pr[i-1],pr[i]);
	for(re i=n-1;i;i--)sf[i]=max(sf[i+1],sf[i]);
	for(re i=1;i<=n;i++){
		x=qwq[i].size();
		for(re j=0;j<x;j++)dl.push(qwq[i][j]);
		x=awa[i].size();
		for(re j=0;j<x;j++)pl.push(awa[i][j]);
		while(!pl.empty()&&dl.top()==pl.top())dl.pop(),pl.pop();
		pr[i]=max(pr[i],sf[i]);
		if(!dl.empty())pr[i]=max(pr[i],dl.top());
	}
	for(re i=1;i<=n;i++){
		p[pr[i]]++;
		x=q[i].size();
		for(re j=0;j<x;j++){
			f[q[i][j].id]+=q[i][j].y*p[q[i][j].x];
		}
	}
	x=0;for(re i=1;i<=n;i++)x^=f[i];
	cout<<x<<endl;
	return 0;
}