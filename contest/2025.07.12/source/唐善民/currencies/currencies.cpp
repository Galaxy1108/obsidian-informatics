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
//#define DEBUG
using namespace std;
typedef long long ll;
constexpr const int N=1e5,M=1e5;
int n,m;
vector<int>g[N+1],cost[N+1];
int father[N+1],depth[N+1],dfn[N+1],reDfn[N+1],st[N+1][__lg(N)+1],rest[N+1][__lg(N)+1];
pair<int,int>edge[N+1];
void dfs(int x,int fx){
	father[x]=fx;
	depth[x]=depth[fx]+1; 
	static int cnt;
	dfn[x]=++cnt;
	reDfn[cnt]=x;
	for(int i:g[x]){
		if(i==fx){
			continue;
		}
		dfs(i,x);
	}
}
void lca_pre(){
	dfs(1,0);
	for(int i=1;i<=n;i++){
		st[i][0]=depth[reDfn[i]];
		rest[i][0]=reDfn[i];
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int x=1;x+(1<<i)-1<=n;x++){
			if(st[x][i-1]<st[x+(1<<i-1)][i-1]){
				st[x][i]=st[x][i-1];
				rest[x][i]=rest[x][i-1];
			}else{
				st[x][i]=st[x+(1<<i-1)][i-1];
				rest[x][i]=rest[x+(1<<i-1)][i-1];
			}
		}
	}
}
int lca(int u,int v){
	if(u==v){
		return u;
	}
//	[u+1,v]ȡmin
	if(dfn[u]>dfn[v]){
		swap(u,v);
	}
	int l=dfn[u]+1,r=dfn[v];
	int s=__lg(r-l+1);
	if(st[l][s]<st[r-(1<<s)+1][s]){
		return father[rest[l][s]];
	}else{
		return father[rest[r-(1<<s)+1][s]];
	}
}
int query(int s,int t,int x,ll y){
	int lcaSt=lca(s,t);
	vector<ll>c;
	while(s!=lcaSt){
		if(cost[s].size()){
			for(int i:cost[s]){
				c.push_back(i);
			}
		}
		s=father[s];
	}
	while(t!=lcaSt){
		if(cost[t].size()){
			for(int i:cost[t]){
				c.push_back(i);
			}
		}
		t=father[t];
	}
	sort(c.begin(),c.end());
	#ifdef DEBUG
	cerr<<"c={";
	for(int i:c){
		cerr<<i<<' ';
	}
	cerr<<"}"<<endl;
	#endif
	for(int i=1;i<c.size();i++){
		c[i]+=c[i-1];
	}
	int p=upper_bound(c.begin(),c.end(),y)-c.begin()-1;
	x-=c.size()-p-1;
	if(x>=0){
		return x;
	}
	return -1;
}
int main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int q;
	cin>>n>>m>>q;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		edge[i]={u,v};
	}
	lca_pre();
	for(int i=1;i<=m;i++){
		int p,c;
		cin>>p>>c;
		int u=edge[p].first,v=edge[p].second;
		if(u==father[v]){
			swap(u,v);
		}
//		p : (u,father[u])
		cost[u].push_back(c);
	}
	while(q--){
		int s,t,x;
		ll y;
		cin>>s>>t>>x>>y;
		#ifdef DEBUG
		cout<<"::";
		#endif
		cout<<query(s,t,x,y)<<'\n';
	}
	
	cout.flush(); 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
