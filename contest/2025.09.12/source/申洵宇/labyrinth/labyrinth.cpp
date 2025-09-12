#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define INF 0x3f3f3f3f
int Tasks,n;
vector<int>e[N],minp;
bitset<N>book;
int siz[N],minn;
void dfs1(int x,int come){
	siz[x]=1;
	for(auto v:e[x]){
		if(v==come||book[v])continue;
		dfs1(v,x);
		siz[x]+=siz[v];
	}
}
void dfs2(int x,int come,int rt){
	int maxn=siz[rt]-siz[x];
	for(auto v:e[x]){
		if(v==come||book[v])continue;
		dfs2(v,x,rt);
		maxn=max(maxn,siz[v]);
	}
	if(maxn<minn){
		minn=maxn;
		minp.clear();
		minp.emplace_back(x);
	}
	else if(maxn==minn){
		minp.emplace_back(x);
	}
}
int getans(int x){
	// cerr<<x<<":";
	dfs1(x,0);
	// cerr<<siz[x]<<'\n';
	minp.clear(),minn=INF;
	dfs2(x,0,x);
	// cerr<<minp[0]<<'\n';
	int res=INF;
	for(auto mp:minp){
		book[mp]=true;
		int ans=0;
		for(auto v:e[mp]){
			if(book[v])continue;
			ans=max(ans,getans(v));
		}
		res=min(res,ans);
		book[mp]=false;
	}
	return res+1;
}
int subl_getans(int x){
	if(x<=1)return 1;
	int t=(x+1)/2;
	return subl_getans(max(x-t,t-1))+1;
}
void solve(){
	cin>>n;
	static int deg[N];
	for(int i=1;i<=n;i++)e[i].clear(),deg[i]=0;
	book.reset();
	int _u,_v;
	for(int i=1;i<n;i++){
		cin>>_u>>_v;
		e[_u].emplace_back(_v);
		e[_v].emplace_back(_u);
		deg[_u]++,deg[_v]++;
	}
	bool subl=true;
	for(int i=1;i<=n;i++){
		if(deg[i]>2){
			subl=false;
			break;
		}
	}
	if(subl){
		cout<<subl_getans(n)<<'\n';
	}
	else{
		cout<<getans(1)<<'\n';
	}
}
int main(){
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	// freopen("t.txt","w",stderr);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>Tasks;
	while(Tasks--){
		// cerr<<Tasks<<':';
		solve();
		// cerr<<'\n';
	}
	return 0;
}