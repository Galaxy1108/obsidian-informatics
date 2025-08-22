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
typedef long long ll;
constexpr const ll inf=0x3f3f3f3f3f3f3f3f;
constexpr const int N=2000,W=1e9;
int n,w[N+1][N+1];
namespace judge0{
	vector<int>g[N+1];
	bool vis[N+1];
	int flag[N+1];
	void dfs(int x,int cnt,ll sum,int minEdge,ll &ans){
		if(sum>=ans){
			return;
		}
		ans=min(ans,sum + 1ll*(n-cnt)*minEdge);
		flag[x]=minEdge;
		vis[x]=true;
		for(int i:g[x]){
			if(vis[i]){
				continue;
			}
			dfs(i,cnt+1,sum + min(minEdge,w[x][i]),min(minEdge,w[x][i]),ans);
		}
		vis[x]=false;
	}
	ll query(int t){
		ll ans=inf;
		memset(flag,0x3f,sizeof(flag));
		dfs(t,1,0,W+1,ans);
		return ans;
	}
	int id;
	int main(){
		for(int i=1;i<=n;i++){
			g[i].resize(n);
			for(int j=0;j<n;j++){
				g[i][j]=j;
			}
			id=i;
			sort(g[i].begin(),g[i].end(),[](int a,int b){
				return w[id][a]<w[id][b];
			});
		}
		for(int i=1;i<=n;i++){
			cout<<query(i)<<'\n';
		}
		return 0;
	} 
}
namespace judge1{
	bool check(){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(w[i][j]!=1&&w[i][j]!=W){
					return false;
				}
			}
		}
		return true;
	}
	int bfs(int s){
		queue<int>q;
		q.push(s);
		static bool vis[N+1];
		static int dis[N+1];
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		while(q.size()){
			int x=q.front();q.pop();
			if(vis[x]){
				continue;
			}
			vis[x]=true;
			for(int i=1;i<=n;i++){
				if(vis[i]){
					continue;
				}
				if(w[x][i]==1){
					return dis[x];
				}
				dis[i]=dis[x]+1;
				q.push(i);
			}
		}
		return n-1;
	}
	ll query(int t){
		int cnt=bfs(t);
		return (n-cnt-1)+1ll*cnt*W;
	}
	int main(){
		for(int i=1;i<=n;i++){
			cout<<query(i)<<'\n';
		}
		return 0;
	}
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	memset(w,0x3f,sizeof(w));
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			cin>>w[i][i+j];
			w[i+j][i]=w[i][i+j];
//			cerr<<"("<<i<<","<<i+j<<") = "<<w[i][i+j]<<'\n';
		}
	}
	if(judge1::check()){
		judge1::main();
	}else{
		judge0::main();
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6
2 9 9 6 6
7 1 9 10
9 2 5
4 10
8

6
5
7
5
7
11
*/
/*
4
1 1000000000 1000000000
1 1000000000
1000000000

3
3
3
1000000002
*/
