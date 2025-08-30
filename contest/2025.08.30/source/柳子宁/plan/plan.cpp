#include<bits/stdc++.h>
using namespace std;
int n,k,x,y,tot;
long long ans;
int a[510],tag[510][510],sum[510],siz[510],dfn[510];
int prime[100010],cntp,id[1000010],id2[1000010];
long long f[510][510],F[510][510],G[510][510];
vector<int> line[510];
void upd(int x){
	for(int j=sum[x];j>=1;--j){
		for(int r=1;r<=cntp;++r){
			if(tag[x][j]%prime[r]) continue;
			int y=id[tag[x][j]/prime[r]];
			for(int k=0;k<siz[x];++k){
				F[k][y]=max(F[k][y],F[k][j]);
			}
		}
	}
	return;
}
void dfs(int x,int fa){
	dfn[x]=++tot;siz[x]=1;
	for(auto v:line[x]){
		if(v==fa) continue;
		dfs(v,x);
		siz[x]+=siz[v];
	}
	for(int i=0;i<=siz[x];++i) memset(F[i],-0x3f,sizeof(F[i]));
	siz[x]=1;

	sort(tag[x]+1,tag[x]+sum[x]+1);
	F[0][sum[x]]=0;
	for(int i=1;i<=sum[x];++i) id[tag[x][i]]=i;
	cntp=0;
	for(int i=2;i<=sum[x];++i){
		int Tag=1;
		for(int j=1;j<=cntp;++j){
			if(tag[x][i]%prime[j]==0) Tag=0;
		}
		if(Tag) prime[++cntp]=tag[x][i];
	}

	for(auto v:line[x]){
		if(v==fa) continue;
		upd(x);
		for(int i=0;i<siz[x]+siz[v];++i) memset(G[i],-0x3f,sizeof(G[i]));
		for(int i=1;i<=sum[v];++i) id2[tag[v][i]]=i;
		for(int i=0;i<siz[x];++i){
			for(int j=0;j<siz[v];++j){
				long long val=-1000000000000000000;
				for(int k=1;k<=sum[v];++k) val=max(val,f[j+dfn[v]][k]+tag[v][k]);
				for(int k=1;k<=sum[x];++k){
					if(id2[tag[x][k]]) G[i+j][k]=max(G[i+j][k],F[i][k]+f[j+dfn[v]][id2[tag[x][k]]]);
					G[i+j+1][k]=max(G[i+j+1][k],F[i][k]+val);
				}
			}
		}
		for(int i=1;i<=sum[v];++i) id2[tag[v][i]]=0;
		siz[x]+=siz[v];
		for(int i=0;i<siz[x];++i){
			for(int j=1;j<=sum[x];++j) F[i][j]=G[i][j];
		}
	}
	upd(x);
	for(int i=dfn[x];i<=dfn[x]+siz[x]-1;++i){
		memset(f[i],-0x3f,sizeof(f[i]));
		for(int j=1;j<=sum[x];++j) f[i][j]=F[i-dfn[x]][j];
	}
	return;
}
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		line[x].push_back(y);
		line[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(int j=1;j*j<=a[i];++j){
			if(a[i]%j==0){
				tag[i][++sum[i]]=j;
				if(j*j<a[i]) tag[i][++sum[i]]=a[i]/j;
			}
		}
	}
	dfs(1,0);
	for(int i=1;i<=sum[1];++i){
		ans=max(ans,f[k+1][i]+tag[1][i]);
	}
	printf("%lld\n",ans);
	return 0;
}
