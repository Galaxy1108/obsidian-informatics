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
constexpr const int N=5000,M=5000,V=1e9,P=998244353;
struct solve{
	int u,v,w;
}a[M+1];
int n,m,l[N+1],r[N+1],ans[N+1];
int qpow(int base,int n){
	int ans=1;
	while(n){
		if(n&1){
			ans=1ll*ans*base%P;
		}
		base=1ll*base*base%P;
		n>>=1;
	}
	return ans;
}
vector<int>g[N+1];
int father[N+1][__lg(N+1)+1],dep[N+1];
void dfs(int x,int fx){
	father[x][0]=fx;
	dep[x]=dep[fx]+1;
	for(int i:g[x]){
		if(i==fx){
			continue;
		}
		dfs(i,x);
	} 
}
void lcaPre(){
	dfs(1,0);
	for(int i=1;(1<<i)<=n;i++){
		for(int x=1;x<=n;x++){
			father[x][i]=father[father[x][i-1]][i-1];
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=__lg(dep[u]-dep[v]);i>=0;i--){
		if(dep[father[u][i]]>=dep[v]){
			u=father[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=__lg(dep[u]);i>=0;i--){
		if(father[u][i]!=father[v][i]){
			u=father[u][i],v=father[v][i];
		}
	}
	return father[u][0];
}
int all;
void makeTree(int x){
	if(x>n){
		all++;
		lcaPre();
		for(int i=1;i<=m;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int lcaUV=lca(u,v);
			while(u!=lcaUV){
				ans[u]=(ans[u]+w)%P;
				u=father[u][0];
			}
			while(v!=lcaUV){
				ans[v]=(ans[v]+w)%P;
				v=father[v][0];
			}
		}
		return;
	}
	for(int i=l[x];i<=r[x];i++){
		g[x].push_back(i);
		g[i].push_back(x);
		makeTree(x+1);
		g[x].pop_back();
		g[i].pop_back();
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	makeTree(2);
	for(int i=2,inv=qpow(all,P-2);i<=n;i++){
		ans[i]=1ll*ans[i]*inv%P;
		cout<<ans[i]<<' ';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
