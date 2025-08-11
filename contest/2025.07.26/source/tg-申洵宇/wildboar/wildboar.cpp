#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define L 100005
#define v first
#define w second
#define INF 0x3f3f3f3f3f3f3f3f
struct node{
	int x;
	long long val;
	node(int x_,long long val_):x(x_),val(val_){}
	friend bool operator<(const node& x,const node& y){
		return x.val>y.val;
	}
};
int n,m,l,p[L];
int nto,ncome;
long long dis[N];
vector<pair<int,int>>e[N];
long long val[15][15][15];
long long f[15][15][15]; 
bitset<N>book;
long long dij(int s,int t){
	static priority_queue<node>pq;
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;i++)dis[i]=INF;
	book.reset();
	dis[s]=0;
	for(auto v:e[s]){
		if((!book[v.v])&&dis[v.v]>dis[s]+v.w){
			if(v.v==nto)continue;
			dis[v.v]=dis[s]+v.w;
			pq.emplace(v.v,dis[v.v]);
		}
	}
	while(!pq.empty()){
		static int x;x=pq.top().x;
		pq.pop();
		if(book[x])continue;
		book[x]=true;
		for(auto v:e[x]){
			if((!book[v.v])&&dis[v.v]>dis[x]+v.w){
				if(v.v==t&&x==ncome)continue;
				dis[v.v]=dis[x]+v.w;
				pq.emplace(v.v,dis[v.v]);
			}
		}
	}
	return dis[t];
}
void solve(){
	for(int i=1;i<l;i++){
		for(int j=0;j<e[p[i]].size();j++){
			nto=e[p[i]][j].v;
			for(int k=0;k<e[p[i+1]].size();k++){
				ncome=e[p[i+1]][k].v;
				val[i][nto][ncome]=dij(p[i],p[i+1]);
//				cerr<<"val:"<<i<<','<<nto<<','<<ncome<<':'<<val[i][nto][ncome]<<endl;
			}
		}
	}
	for(int j=0;j<e[p[1]].size();j++){
		for(int k=0;k<e[p[2]].size();k++){
			f[1][j][k]=val[1][e[p[1]][j].v][e[p[2]][k].v];
//			cerr<<1<<','<<e[p[1]][j].v<<','<<e[p[2]][k].v<<':'<<f[1][j][k]<<'\n';
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=2;i<l;i++){
//		cerr<<i<<"I,";
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int p=1;p<=n;p++){
					f[i][j][k]=min(f[i][j][k],f[i-1][p][j]+val[i][j][k]);
				}
//				cerr<<i<<','<<j<<','<<k<<':'<<f[i][j][k]<<'\n'; 
			}
		}
	}
	long long ans=INF;
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			ans=min(ans,f[l-1][j][k]);
		}
	}
	if(ans==INF){
		printf("-1\n");
	}
	else{
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	int T;
	scanf("%d%d%d%d",&n,&m,&T,&l);
	int _u,_v,_w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&_u,&_v,&_w);
		e[_u].emplace_back(_v,_w);
		e[_v].emplace_back(_u,_w);
	}
	for(int i=1;i<=l;i++){
		scanf("%d",&p[i]);
	}
	int _p,_q;
	while(T--){
		scanf("%d%d",&_p,&_q);
		p[_p]=_q;
		solve();
	}
	return 0;
}
