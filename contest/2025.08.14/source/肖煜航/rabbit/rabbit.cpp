#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=105,M=1e4+5;
const int mod=998244353;
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
struct edge{
	int to,nxt,w;
}e[M];
int head[N],tot;
void add(int u,int v,int w){
	e[++tot]={v,head[u],w};
	head[u]=tot;
}
int n,m,s,t;
int ind[N],d[N];
int f[N];
bool vis[N];
void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt) dfs(e[i].to);
}
int main(){
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	bool flag=1; 
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		if(z==1) flag=0;
		d[x]++;
		ind[y]++;
	}
	if(flag){
		printf("0 0");
		return 0;
	}
	dfs(s);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			for(int j=head[i];j;j=e[j].nxt){
				int o=e[j].to;
				ind[o]--;
			}
		}
	}
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			ind[v]--;
			int op=f[u]+1;
			if(e[i].w==0) op=0;
			f[v]=(f[v]+1ll*op*qpow(d[u],mod-2)%mod)%mod;
			if(!ind[v]){
				q.push(v);
			}
		}
	}
	printf("%d",f[t]);
	return 0;
} 
