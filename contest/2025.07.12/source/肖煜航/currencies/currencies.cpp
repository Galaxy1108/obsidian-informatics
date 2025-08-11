#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map> 
#define ll long long
using namespace std;
ll read(){
	ll p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=1e5+5;
struct edge{
	int to,nxt;
}e[N<<1];
int head[N],tot;
void add(int u,int v){
	e[++tot]={v,head[u]};
	head[u]=tot;
}
int n,m,q;
pair<int,int> edg[N];
namespace solve1{
	int dep[N],f[N][20];
	void dfs(int u,int fa){
		dep[u]=dep[fa]+1;
		f[u][0]=fa;
		for(int i=1;i<20;i++) f[u][i]=f[f[u][i-1]][i-1];
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(v==fa) continue;
			dfs(v,u);
		}
	}
	vector<ll> op[N];
	unordered_map<ll,int> vis;
	ll p[N],tmp;
	bool can=0;
	void dfs1(int u,int fa){
		p[u]+=p[fa];
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(v==fa) continue;
			dfs1(v,u);
		}
	}
	int lca(int x,int y){
		if(dep[x]<dep[y]) swap(x,y);
		int tmp=dep[x]-dep[y];
		for(int i=19;i>=0;i--){
			if(tmp>=(1<<i)){
				tmp-=(1<<i);
				x=f[x][i];
			}
		}
		if(x==y) return x;
		for(int i=19;i>=0;i--){
			if(f[x][i]!=f[y][i]){
				x=f[x][i];
				y=f[y][i];
			}
		}
		return f[x][0];
	}
	ll a[N];
	int idx;
	void work(int s,int t,ll x,ll y){
		int lc=lca(s,t);
		if(can){
			ll o=p[s]+p[t]-2ll*p[lc];
			ll cnt=y/tmp;
			if((o-cnt)<=x) printf("%lld\n",x-max(0ll,o-cnt));
			else puts("-1");
		}
		else{
			idx=0;
			while(s!=lc){
				for(int i=0;i<op[s].size();i++) a[++idx]=op[s][i];
				s=f[s][0];
			}
			while(t!=lc){
				for(int i=0;i<op[t].size();i++) a[++idx]=op[t][i];
				t=f[t][0];
			}
			sort(a+1,a+idx+1);
			ll sum=0;
			for(int i=1;i<=idx;i++){
				sum+=a[i];
				if(sum>y){
					sum-=a[i];
					int o=idx-i+1;
					if(x>=o) printf("%lld\n",x-o);
					else puts("-1");
					return;
				}
			}
			printf("%lld\n",x);
		}
	}
	void solve(){
		dfs(1,0);
		for(int i=1;i<n;i++) if(dep[edg[i].first]>dep[edg[i].second]) swap(edg[i].first,edg[i].second);
		for(int i=1;i<=m;i++){
			int x=read();
			ll y=read();
			tmp=y;
			vis[y]++;
			op[edg[x].second].push_back(y);
			p[edg[x].second]++;
		}
		if(vis[tmp]==m) can=1;
		dfs1(1,0);
		while(q--){
			int s=read(),t=read();
			ll x=read(),y=read();
			work(s,t,x,y);
		}
	}
} 
int main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	n=read(),m=read(),q=read();
	bool flag=1;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
		edg[i]={x,y};
		if(x!=y-1) flag=0;
	}
	solve1::solve();
	return 0;
} 
