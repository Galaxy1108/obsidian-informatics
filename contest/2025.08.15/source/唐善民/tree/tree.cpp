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
#define int long long
using namespace std;
constexpr const int N=5e5;
int n,father[3][N+1],w1[N+1],a[N+1];
vector<int>g[3][N+1];
int depth[N+1];
void dfs0(int x,int fx){
	depth[x]=depth[fx]+1;
	for(int i:g[1][x]){
		dfs0(i,x);
	}
}
int dis(int u,int v){
	int ans=0;
	while(u!=v){
		if(depth[u]<depth[v]){
			swap(u,v);
		}
		ans+=w1[u];
		u=father[1][u];
	}
	return ans;
}
void dfs(int x,int &ans,vector<int>&p,int from){
	p.push_back(x);
	int pl=0;
	for(int i=p.size()-1;i>=0;i--){
		pl+=a[p[i]]*(p.size()-i-1);
	}
	ans=max(ans,dis(x,from)+pl);
	for(int i:g[2][x]){
		dfs(i,ans,p,from);
	}
	p.pop_back();
}
main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>father[1][i];
		g[1][father[1][i]].push_back(i);
	}
	dfs0(1,0);
	for(int i=2;i<=n;i++){
		cin>>w1[i];
	}
	for(int i=2;i<=n;i++){
		cin>>father[2][i];
		g[2][father[2][i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		vector<int>p;
		dfs(i,ans,p,i);
		cout<<ans<<' ';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
