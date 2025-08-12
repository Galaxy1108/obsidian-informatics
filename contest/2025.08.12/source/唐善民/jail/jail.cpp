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
constexpr const int N=120000,M=N;
//s[i]:i 为起点的编号 
int n,m,s[N+1],t[N+1];
vector<int>g[N+1],build[M+1];
struct people{
	int s,t;
}a[M+1];
namespace base{
	int father[N+1],depth[N+1];
	void dfs(int x,int fx){
		depth[x]=depth[fx]+1;
		father[x]=fx;
		for(int i:g[x]){
			if(i==fx){
				continue;
			}
			dfs(i,x);
		}
	}
	int main(){
		dfs(1,0);
		return 0;
	}
	void clear(){
		for(int i=1;i<=n;i++){
			g[i].resize(0);
			build[i].resize(0);
		}
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
	}
}
void pre(){
	for(int i=1;i<=m;i++){
		int u=a[i].s,v=a[i].t;
		while(u!=v){
			if(base::depth[u]<base::depth[v]){
				swap(u,v);
			}
			if(s[u]&&s[u]!=i){
				build[s[u]].push_back(i);
			}
			if(t[u]&&t[u]!=i){
				build[i].push_back(t[u]);
			}
			u=base::father[u];
		}
		if(s[u]&&s[u]!=i){
			build[s[u]].push_back(i);
		}
		if(t[u]&&t[u]!=i){
			build[i].push_back(t[u]);
		}
	}
}
bool checkRing(){
	static int in[M+1];
	static bool vis[M+1];
	memset(in,0,sizeof(in));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++){
		for(int j:build[i]){
			in[j]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=m;i++){
		if(!in[i]){
			q.push(i);
		}
	}
	while(q.size()){
		int x=q.front();q.pop();
		vis[x]=true;
		for(int i:build[x]){
			in[i]--;
			if(!in[i]){
				q.push(i);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			return true;
		}
	}
	return false;
} 
int main(){
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		base::clear();
		cin>>n;
//		cerr<<"n="<<n<<endl; 
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		base::main();
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i].s>>a[i].t;
			s[a[i].s]=i,t[a[i].t]=i;
		}
		pre();
		if(checkRing()){
			cout<<"No\n";
		}else{
			cout<<"Yes\n";
		}
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
7
1 2
2 3
3 4
4 5
3 6
6 7
2
4 1
5 7
4
1 2
1 3
1 4
3
2 3
3 4
4 2

Yes
No
*/
