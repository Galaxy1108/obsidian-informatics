#include<bits/stdc++.h>
#define Dis(x,y) (Tree1::dep[x]+Tree1::dep[y]-2ll*Tree1::dep[LCA::LCA(x,y)])
#define inf 1000000000000000000
using namespace std;
int n,tot;
namespace LCA{
	int dfn[500010];
	int st[20][500010];
	int cmp(int x,int y){return (dfn[x]<dfn[y])?x:y;}
	void Init(){
		for(int k=1;k<=__lg(n);++k){
			for(int i=1;i+(1<<(k-1))<=n;++i){
				st[k][i]=cmp(st[k-1][i],st[k-1][i+(1<<(k-1))]);
			}
		}
	}
	int LCA(int x,int y){
		if(x==y) return x;
		x=dfn[x],y=dfn[y];
		if(x>y) swap(x,y);
		++x;int z=__lg(y-x+1);
		return cmp(st[z][x],st[z][y-(1<<z)+1]);
	}
}
namespace Tree1{
	int fa[500010],w[500010];
	vector<int> son[500010];
	long long dep[500010];
	void dfs(int x){
		LCA::dfn[x]=++tot;
		LCA::st[0][tot]=fa[x];
		for(auto v:son[x]) dfs(v);
	}
	void solve(){
		for(int i=2;i<=n;++i){
			scanf("%d",&fa[i]);
			son[fa[i]].push_back(i);
		}
		for(int i=2;i<=n;++i){
			scanf("%d",&w[i]);
			dep[i]=dep[fa[i]]+w[i];
		}
		dfs(1);
	}
}
namespace Tree2{
	int fa[500010],dep[500010];
	long long a[500010],s[500010],val[500010];
	long long ans[500010];
	vector<int> son[500010];
	#define p(x,y) (val[y]-val[x]-s[x]*(dep[y]-dep[x]))
	void calc(int x,int y){
		ans[x]=max(ans[x],Dis(x,y)+p(x,y));
		for(auto v:son[y]){
			calc(x,v);
		}
	}
	void dfs(int x){
		ans[x]=-inf;calc(x,x);
		for(auto v:son[x]) dfs(v);
	}
	void solve(){
		for(int i=2;i<=n;++i){
			scanf("%d",&fa[i]);
			son[fa[i]].push_back(i);
		}
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int i=2;i<=n;++i){
			s[i]=s[fa[i]]+a[fa[i]];
			val[i]=val[fa[i]]+s[i];
			dep[i]=dep[fa[i]]+1;
		}
		dfs(1);
		for(int i=1;i<=n;++i){
			printf("%lld ",ans[i]);
		}
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);

	scanf("%d",&n);
	Tree1::solve();
	LCA::Init();
	Tree2::solve();
	return 0;
}
