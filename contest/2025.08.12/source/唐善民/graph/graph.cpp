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
constexpr const int N=2e5,M=2e5,K=M;
int n,m;
//vector<int>g[N+1];
vector<vector<vector<int> > >tree;
int k;
struct dsu{
	vector<int>f,size;
//	int f[N+1],size[N+1];
	int find(int x){
		if(f[x]==x){
			return x;
		}
		return f[x]=find(f[x]);
	}
	void build(int n){
		f.resize(n+1);
		size.resize(n+1);
		for(int i=1;i<=n;i++){
			f[i]=i;
			size[i]=1;
		}
	}
	void merge(int x,int y){
		x=find(x),y=find(y);
		if(size[x]<size[y]){
			f[x]=y;
			size[y]+=size[x];
		}else{
			f[y]=x;
			size[x]+=size[y];
		}
	}
};
vector<dsu>dsu;
void resize(int n,int k){
	dsu.resize(k+1);
	for(int i=1;i<=k;i++){
		dsu[i].build(n+1);
	}
	tree.resize(k+1);
	for(int id=1;id<=k;id++){ 
		tree[id].resize(n+1);
		for(int i=1;i<=n;i++){
			tree[id][i].resize(0);
		}
	}
}
void addEdge(int u,int v){
	/*for(int i=1;i<=k;i++){
		if(dsu[i].find(u)!=dsu[i].find(v)){
			tree[i][u].push_back(v);
			tree[i][v].push_back(u);
			dsu[i].merge(u,v);
			break;
		}
	}*/
	int l=1,r=k,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(dsu[mid].find(u)!=dsu[mid].find(v)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(ans!=-1){
		tree[ans][u].push_back(v);
		tree[ans][v].push_back(u);
		dsu[ans].merge(u,v);
	}
}
bool dfs(int x,int fx,int to,int id,vector<int>&ans){
	ans.push_back(x);
	if(x==to){
		return true;
	}
	for(int i:tree[id][x]){
		if(i==fx){
			continue;
		}
		if(dfs(i,x,to,id,ans)){
			return true;
		}
	}
	ans.pop_back();
	return false;
}
namespace debug{
	void dfs1(int x,int fx,int id){
		cerr<<x<<" ";
		for(int i:tree[id][x]){
			if(i==fx){
				continue;
			}
			dfs1(i,x,id);
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		k=(m+n-2)/(n-1);
		resize(n,k);
		while(m--){
			int u,v;
			cin>>u>>v;
			addEdge(u,v);
		}
		bool flag=true; 
		for(int i=1;flag&&i<=n;i++){
			for(int j:tree[k][i]){
				flag=false;
				cout<<i<<' '<<j<<'\n';
				for(int id=1;id<=k;id++){
					vector<int>ans;
					dfs(i,0,j,id,ans);
					cout<<ans.size()<<' ';
					for(int x:ans){
						cout<<x<<' ';
					}
					cout<<'\n';
				}
				break;
			}
		}
		if(flag){
			cout<<"-1\n";
		}
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
3 1
1 3

1 3
2 1 3
*/
/*
1
4 7
1 2
2 3
3 4
4 1
1 3
2 4
1 4

1 4
4 1 2 3 4
2 1 4
2 1 4
*/
/*
3
3 1
1 3
4 7
1 2
2 3
3 4
4 1
1 3
2 4
1 4
5 5
1 2
2 3
3 4
4 5
3 5

1 3
2 1 3
1 4
4 1 2 3 4
2 1 4
2 1 4
3 5
3 3 4 5
2 3 5
*/
