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
constexpr const int N=10;
int n,f[1<<N|1][1<<N|1],c[1<<N|1];
//0:A,1:B
bool mode[1<<N|1],modeStart[1<<N|1];
ll ans=1ll<<62;
int cntNode,root;
vector<int>g[(1<<N|1)<<2|1];
int build(int l,int r){
	if(l==r){
		return l;
	}
	int x=++cntNode;
	int mid=l+r>>1;
	int lChild=build(l,mid);
	int rChild=build(mid+1,r);
	g[x].push_back(lChild);
	g[x].push_back(rChild);
	return x;
}
int father[(1<<N|1)<<2|1][__lg((1<<N|1)<<2|1)+1],dep[(1<<N|1)<<2|1];
void dfs0(int x,int fx){
	father[x][0]=fx;
	dep[x]=dep[fx]+1;
	for(int i:g[x]){
		if(i==fx){
			continue;
		}
		dfs0(i,x);
	}
}
void lcaPre(){
	dfs0(1<<n|1,0);
	for(int i=1;(1<<i)<=cntNode;i++){
		for(int x=1;x<=cntNode;x++){
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
int cnt[(1<<N|1)<<1|1][2];
void update(){
	queue<int>q;
	for(int i=1;i<=(1<<n);i++){
		q.push(i);
	}
	while(q.size()>1){
		int u=q.front();q.pop();
		int v=q.front();q.pop();
		cnt[father[u][0]][0]=cnt[u][0]+cnt[v][0];
		cnt[father[u][0]][1]=cnt[u][1]+cnt[v][1];
		q.push(father[u][0]);
	}
}
int cost(int i,int j){
	if(i>j){
		swap(i,j);
	}
	int p=lca(i,j);
	int nA=cnt[p][0],nB=cnt[p][1];
	if(nA<nB){
		if(!mode[i]&&!mode[j]){
			return 2*f[i][j];
		}else if(!mode[i]&&mode[j]){
			return f[i][j];
		}else if(mode[i]&&!mode[j]){
			return f[i][j];
		}else{
			return 0;
		}
	}else{
		if(!mode[i]&&!mode[j]){
			return 0;
		}else if(!mode[i]&&mode[j]){
			return f[i][j];
		}else if(mode[i]&&!mode[j]){
			return f[i][j];
		}else{
			return 2*f[i][j];
		}
	}
	return ans;
}
void dfs(int p){
	if(clock()>=1.95*CLOCKS_PER_SEC){
		cout<<'0'<<endl;
		exit(0);
	}
	if(p>(1<<n)){
		update();
		ll pl=0;
		for(int i=1;i<=(1<<n);i++){
			if(mode[i]^modeStart[i]){
				pl+=c[i];
			}
		}
		for(int i=1;i<=(1<<n);i++){
			for(int j=i+1;j<=(1<<n);j++){
				pl+=cost(i,j);
			}
		}
		ans=min(ans,pl);
		return;
	}
	mode[p]=0;
	cnt[p][0]=1;
	cnt[p][1]=0;
	dfs(p+1);
	mode[p]=1;
	cnt[p][1]=1;
	cnt[p][0]=0;
	dfs(p+1);
}
int main(){
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	cntNode=1<<n;
	for(int i=1;i<=(1<<n);i++){
		cin>>modeStart[i];
		mode[i]=modeStart[i];
	}
	for(int i=1;i<=(1<<n);i++){
		cin>>c[i];
	}
	build(1,1<<n);
	lcaPre();
	for(int i=1;i<=(1<<n);i++){
		for(int j=i+1;j<=(1<<n);j++){
			cin>>f[i][j];
		}
	}
	dfs(1);
	if(ans==(1ll<<62)){
		ans=0;
	} 
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
