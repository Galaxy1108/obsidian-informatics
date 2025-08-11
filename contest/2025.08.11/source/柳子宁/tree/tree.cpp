#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,cnt;
int fa[500010],siz[500010];
long long w[500010];
long long F[500010],f[1010][1010];
long double ans[1010];
vector<int> son[500010];
void dfs(int x){
	for(int i=0;i<=n;++i) f[x][i]=-inf;
	f[x][1]=w[x];
	siz[x]=1;
	for(auto v:son[x]){
		dfs(v);
		for(int i=1;i<=siz[x]+siz[v];++i){
			F[i]=-inf;
		}
		for(int i=1;i<=siz[x];++i){
			for(int j=1;j<=siz[v];++j){
				F[i+j]=max(F[i+j],f[x][i]+f[v][j]);
			}
		}
		for(int i=1;i<=siz[x]+siz[v];++i){
			f[x][i]=max(F[i],f[x][i]);
		}
		siz[x]+=siz[v];
	}
	for(int i=1;i<=siz[x];++i){
		ans[x]=max(ans[x],((long double)(f[x][i]))/i);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		scanf("%d",&fa[i]);
		son[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&w[i]);
	}
	dfs(1);
	for(int i=1;i<=n;++i) printf("%.9Lf\n",ans[i]);
	return 0;
}
