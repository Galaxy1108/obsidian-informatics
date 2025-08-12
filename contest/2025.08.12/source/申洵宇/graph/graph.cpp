#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 200005 
struct edge{
	int u,v;
}eg[M];
int n,m,f[N];
vector<int>e[1005][1005]; 
vector<int>ans;
bitset<M>book;
bitset<N>can,in;
int findf(int x){
	return f[x]==x?x:f[x]=findf(f[x]);
}
bool dfs(int x,int ed,int come,vector<int>* e){
	if(x==ed){
		ans.emplace_back(x);
		return true;
	}
	for(auto v:e[x]){
		if(v==come)continue;
		if(dfs(v,ed,x,e)){
			ans.emplace_back(x);
			return true;
		}
	}
	return false;
}
void solve(){
	cin>>n>>m;
	static int K,I;K=(m+n-2)/(n-1);
	for(int i=1;i<=m;i++){
		cin>>eg[i].u>>eg[i].v;
	}
	for(int i=1;i<=n;i++)can[i]=true;
	for(int i=1;i<=K;i++){
		for(int j=1;j<=n;j++)e[i][j].clear();
	}
	book.reset();
	for(I=1;I<=K;I++){
		for(int i=1;i<=n;i++)f[i]=i;
		in.reset();
		static int u,v;
		for(int i=1;i<=m;i++){
			if(book[i])continue;
			u=findf(eg[i].u);v=findf(eg[i].v);
			if(u==v)continue;
			f[u]=v;
			in[eg[i].u]=in[eg[i].v]=book[i]=true;
			e[I][eg[i].u].emplace_back(eg[i].v);
			e[I][eg[i].v].emplace_back(eg[i].u);
		}
//		cerr<<m-book.count()<<"TT\n";
//		for(int i=1;i<=n;i++){
//			cerr<<in[i]<<' ';
//		}
//		cerr<<endl;
		can&=in;
		if((int)book.count()==m)break; 
	}
//	for(int i=1;i<=n;i++){
//		cerr<<can[i]<<' ';
//	}
//	cerr<<endl;
	if(can.count()>=2&&I>=K){
		static int a,b;
		a=0,b=0;
		for(int i=1;i<=n;i++){
			if(can[i]){
				a=b;
				b=i;
			}
			if(a!=0&&b!=0)break;
		}
		cout<<a<<' '<<b<<'\n';
		for(int i=1;i<=K;i++){
			ans.clear();
			dfs(a,b,0,e[i]);
			cout<<ans.size()<<' ';
			for(int i=((int)ans.size())-1;i>=0;i--){
				cout<<ans[i]<<' ';
			}
			cout<<'\n';
		}
	}
	else{
		cout<<"-1\n";
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
