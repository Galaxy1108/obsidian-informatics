#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read(){
	int p=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p*w;
}
const int N=5e5+5;
struct edge{
	int to,nxt;
}e[N];
int head[N],tot;
void add(int u,int v){
	e[++tot]={v,head[u]};
	head[u]=tot;
}
int n,a[N],sz[N],fa[N];
int ls[N],rs[N];
ll f[1005][1005];
ll tmp[1005];
void dfs(int u){
	f[u][1]=a[u];
	sz[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		dfs(v);
		memcpy(tmp,f[u],sizeof tmp);
		for(int j=1;j<=sz[u];j++) for(int k=1;k<=sz[v];k++) f[u][j+k]=max(f[u][j+k],tmp[j]+f[v][k]);
		sz[u]+=sz[v];
	}
}
namespace solveA{
	pair<ll,int> ans[N];
	void dfs(int u){
		ans[u]={a[u],1};
		if(ls[u]) dfs(ls[u]);
		if(rs[u]) dfs(rs[u]);
		if(ls[u]){
			if(1.0*ans[u].first/ans[u].second<1.0*(ans[ls[u]].first+a[u])/(ans[ls[u]].second+1)){
				ans[u]={ans[ls[u]].first+a[u],ans[ls[u]].second+1};
			}
		}
		if(rs[u]){
			if(1.0*ans[u].first/ans[u].second<1.0*(ans[rs[u]].first+a[u])/(ans[rs[u]].second+1)){
				ans[u]={ans[rs[u]].first+a[u],ans[rs[u]].second+1};
			}
		}
		if(ls[u]&&rs[u]){
			if(1.0*ans[u].first/ans[u].second<1.0*(ans[ls[u]].first+a[u]+ans[rs[u]].first)/(ans[ls[u]].second+1+ans[rs[u]].second)){
				ans[u]={ans[ls[u]].first+a[u]+ans[rs[u]].first,ans[ls[u]].second+1+ans[rs[u]].second};
			}
		}
	}
	void solve(){
		for(int i=2;i<=n;i++){
			if(ls[fa[i]]){
				rs[fa[i]]=i;
			}
			else ls[fa[i]]=i;
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			if(ans[i].second==0){
				i++;
				i--;
			}
			printf("%.10lf\n",1.0*ans[i].first/ans[i].second);
		}
		
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	bool flag=0;
	for(int i=2;i<=n;i++){
		int x=read();
		add(x,i);
		fa[i]=x;
		if(x!=(i/2)) flag=0;
	}
	for(int i=1;i<=n;i++) a[i]=read();
	if(flag){
		solveA::solve();
		return 0;
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		double ans=0;
		for(int j=1;j<=n;j++){
			ans=max(ans,1.0*f[i][j]/j);
		}
		printf("%.10lf\n",ans);
	}
	return 0;
} 
