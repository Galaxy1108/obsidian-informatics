#include <bits/stdc++.h>
using namespace std;
int n,p,uu,vv,ans;
int sz[310],ntt[310<<1],to[310<<1],h[310],f[310],ds[310],cnt,d2[310][310],pr[310];
bool vis[310];
void add(){
	cnt++;
	ntt[cnt]=h[uu];
	h[uu]=cnt;
	to[cnt]=vv;
	cnt++;
	ntt[cnt]=h[vv];
	h[vv]=cnt;
	to[cnt]=uu;
	return;
} 
int dfs2(int u,int fa,int d){
	ds[u]=d;
	if(!d2[d][0]) d2[0][0]++;
	d2[d][++d2[d][0]]=u;
	sz[u]++;
	for(int i=h[u];i;i=ntt[i]){
		int v=to[i];
		if(v==fa) continue;
		f[v]=u;
		sz[u]+=dfs2(v,u,d+1);
	}
	return sz[u];
}
void deletett(int u,int fa){
	vis[u]=1;
	for(int i=h[u];i;i=ntt[i]){
		int v=to[i];
		if(v==fa) continue;
		deletett(v,u);
	}
	return;
}
void redel(int u,int fa){
	vis[u]=0;
	for(int i=h[u];i;i=ntt[i]){
		int v=to[i];
		if(v==fa) continue;
		redel(v,u);
	}
	return;
}
void dfs1(int d,int sum){
	if(d==d2[0][0]+1){
		ans=max(ans,sum);
		return;
	}
	if(sum+pr[d2[0][0]]-pr[d-1]<ans) return;
	for(int i=1;i<=d2[d][0];i++){
		if(!vis[d2[d][i]]){
			deletett(d2[d][i],f[d2[d][i]]);
			dfs1(d+1,sum+sz[d2[d][i]]);
			redel(d2[d][i],f[d2[d][i]]);
		}
		else ans=max(ans,sum);
	}
	return;
}
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=p;i++){
		scanf("%d%d",&uu,&vv);
		add();
	}
	dfs2(1,0,1);
	for(int i=1;i<=d2[0][0];i++){
		uu=0;
		for(int j=1;j<=d2[i][0];j++){
			uu=max(uu,sz[d2[i][j]]);
		}
		pr[i]=pr[i-1]+uu;
	}
	dfs1(2,0);
	printf("%d",sz[1]-ans);
	return 0;
} 
