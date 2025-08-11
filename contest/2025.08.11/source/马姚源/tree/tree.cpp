#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct Edge{
	int nxt,to;
}E[N];int h[N],cnt=0;
void add_edge(int u,int v){
	E[++cnt].nxt=h[u];
	E[cnt].to=v;
	h[u]=cnt;
}
int w[N];
int siz[N],sum[N];
double f[N];
double c(int a,int b){
	double t1=a,t2=b;
	return t1/t2*1.00;
}
void dfs2(int u,int fa){
	siz[u]=1,sum[u]=f[u]=w[u];
	for(int i=h[u];i;i=E[i].nxt){
		int v=E[i].to;
		if(v==fa)continue;
		dfs2(v,u);
		siz[u]+=siz[v];
		sum[u]+=sum[v];
	}
}
double dp[N];
void dfs(int u,int fa){
	f[u]=w[u]*1.00;
	int res=w[u],num=1;
	for(int i=h[u];i;i=E[i].nxt){
		int v=E[i].to;
		if(v==fa)continue;
		dfs(v,u);
		res+=sum[v];
		num+=siz[v];
		if((sum[v]+w[u])/(siz[v]+1)<=res/num*1.0){
			f[u]=max(c(res,num),f[u]);
		}
		else{
			res=sum[v]+w[u];
			num=siz[v]+1;
			f[u]=max(c(res,num),f[u]);
		}
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i=2;i<=n;i++){
		int fa;
		cin >> fa;
		add_edge(fa,i);
		add_edge(i,fa);
	}
	for(int i=1;i<=n;i++){
		cin >> w[i];
	}
	dfs2(1,-1);
	for(int i=1;i<=n;i++){
		dfs(i,i);
	}
	
	for(int i=1;i<=n;i++){
//		cout << sum[i] << " " << siz[i] << endl;
		double t=sum[i],t1=siz[i];
		printf("%.9f\n",c(sum[i],siz[i]));
//		printf("%.9f\n\n",f[i]);
	}
	return 0;
}
