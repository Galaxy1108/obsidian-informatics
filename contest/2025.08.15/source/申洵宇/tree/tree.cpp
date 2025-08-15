#include <bits/stdc++.h>
using namespace std;
#define N 500005
struct node{
	int v,w;
	node(int _v=0,int _w=0):v(_v),w(_w){}
};
int n,_f1[N],f2[N],a[N];
long long ans,st;
long long dis1[5005][5005],dis2[5005][5005]; 
vector<node>e1[N];
vector<int>e2[N];
void dfs1(int x,long long* dis,int come,long long dist){
	dis[x]=dist;
	for(auto v:e1[x]){
		if(v.v==come)continue;
		dfs1(v.v,dis,x,dist+v.w);
	}
}
void dfs2(int x,long long* dis,int come,long long dist,int ce){
	dis[x]=dist;
	for(auto v:e2[x]){
		if(v==come)continue;
		dfs2(v,dis,x,dist+a[v]*ce,ce+1);
	}
}
void dfs3(int x,int fa){
	ans=max(ans,dis1[st][x]+dis2[x][st]);
	for(auto v:e2[x]){
		if(v==fa)continue;
		dfs3(v,x);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int _w;
	for(int i=2;i<=n;i++){
		cin>>_f1[i];
	}
	for(int i=2;i<=n;i++){
		cin>>_w;
		e1[_f1[i]].emplace_back(i,_w);
		e1[i].emplace_back(_f1[i],_w);
	}
	for(int i=2;i<=n;i++){
		cin>>f2[i];
		e2[f2[i]].emplace_back(i);
		e2[i].emplace_back(f2[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs1(i,dis1[i],0,0ll);
		dfs2(i,dis2[i],0,0ll,1);
	}
	for(int i=1;i<=n;i++){
		ans=0xc0c0c0c0c0c0c0c0ll;
		st=i;
		dfs3(i,f2[i]);
		cout<<ans<<' ';
	}
	return 0;
}

