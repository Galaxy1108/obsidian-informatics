//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
constexpr const int N=5000;
int n,father[N+1],w[N+1];
vector<int>g[N+1];
int a[N+1][N+1],c[N+1][N+1],d[N+1][N+1];
int depth[N+1],dfn[N+1],rnk[N+1],st[N+1][__lg(N+1)+1],rest[N+1][__lg(N+1)+1];
void dfs(int x){
	depth[x]=depth[father[x]]+1;
	static int cnt;
	dfn[x]=++cnt;
	rnk[cnt]=x;
	for(int i:g[x]){
		if(i==father[x]){
			continue;
		}
		dfs(i);
	}
}
inline int lca(int u,int v){
	if(dfn[u]>dfn[v]){
		swap(u,v);
	}
	if(u==v){
		return u;
	}
	int s=__lg(dfn[v]-dfn[u]);
	if(st[dfn[u]+1][s]<st[dfn[v]-(1<<s)+1][s]){
		return father[rest[dfn[u]+1][s]];
	}else{
		return father[rest[dfn[v]-(1<<s)+1][s]];
	}
}
void dfs2(int x){
	for(int j=1;j<=n;j++){
		c[j][x]=d[j][x];
	}
	for(int i:g[x]){
		if(i==father[x]){
			continue;
		}
		dfs2(i);
		for(int j=1;j<=n;j++){
			c[j][x]+=c[j][i];
		}
	}
}
int f[N+1];
inline void pre(){
	dfs(1);
	for(int i=1;i<=n;i++){
		st[i][0]=depth[rnk[i]];
		rest[i][0]=rnk[i];
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int x=1;x+(1<<i-1)<=n;x++){
			if(st[x][i-1]<st[x+(1<<i-1)][i-1]){
				st[x][i]=st[x][i-1];
				rest[x][i]=rest[x][i-1];
			}else{
				st[x][i]=st[x+(1<<i-1)][i-1];
				rest[x][i]=rest[x+(1<<i-1)][i-1];
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			if(j==k){
				continue;
			}
			d[j][lca(j,k)]-=2;
			d[j][j]++;
			d[j][k]++;
		}
	}
	dfs2(1);
	static int Max[N+1]; 
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=w[i]*c[j][i];
			Max[j]=max(Max[j],a[i][j]);
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==Max[j]){
				f[i]++;
			}
		}
	}
}
int main(){
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>father[i]>>w[i];
		g[father[i]].push_back(i);
	}
	pre();
	int ans=0;
	for(int i=2;i<=n;i++){
		ans^=f[i];
	}
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
