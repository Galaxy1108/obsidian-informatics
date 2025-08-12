#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& os,__int128 x){
	static char buf[35];
	int cnt=0;
	while(x){
		buf[++cnt]=(x%10)^48;
		x/=10;
	}
	for(int i=cnt;i>=1;i--){
		os<<buf[i];
	}
	return os;
}
constexpr __int128 INF=(((__int128)0x3f3f3f3f3f3f3f3f)<<64ll)+((__int128)0x3f3f3f3f3f3f3f3f);
#define N 105
struct node{
	int v;
	long long w,c;
	node(int v_,long long w_,long long c_):v(v_),w(w_),c(c_){}
};
struct day{
	int id;
	__int128 sum;
	day(int id_,__int128 sum_):id(id_),sum(sum_){}
	friend bool operator<(const day& x,const day& y){
		return x.sum>y.sum;
	}
};
int n,m,q;
long long S;
__int128 dis[N];
vector<node>e[N];
bitset<N>book;
__int128 solve(int st,int ed,long long T){
	for(int i=1;i<=n;i++)dis[i]=INF;
	book.reset();
	priority_queue<day>pq;
	pq.emplace(st,T);
	dis[st]=T;
	pq.emplace(st,dis[st]);
	while(!pq.empty()){
		static int x;x=pq.top().id;
		static long long now;
		static __int128 val;
		pq.pop();
		if(book[x])continue;
		book[x]=true;
		now=dis[x]%S;
		for(auto v:e[x]){
			if(now+v.w<=v.c){
				val=dis[x]+v.w;
			}
			else{
				val=dis[x]-now+S+v.w;
			}
			if(!book[v.v]&&dis[v.v]>val){
				dis[v.v]=val;
				pq.emplace(v.v,dis[v.v]);
			}
		}
	}
	return dis[ed]-T;
}
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>S>>q;
	int _u,_v;
	long long _w,_c,_t;
	for(int i=1;i<=m;i++){
		cin>>_u>>_v>>_w>>_c;
		_u++,_v++;
		e[_u].emplace_back(_v,_w,_c);
		e[_v].emplace_back(_u,_w,_c);
	}
	for(int i=1;i<=q;i++){
		cin>>_u>>_v>>_t;
		_u++,_v++;
		cout<<solve(_u,_v,_t)<<'\n';
	}
	return 0;
}
