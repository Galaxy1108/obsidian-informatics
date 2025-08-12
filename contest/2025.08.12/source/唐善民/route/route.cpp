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
constexpr const int N=90;
constexpr const ll S=1e15,inf=0x3f3f3f3f3f3f3f3f;
struct edge{
	int v;
	ll l,c;
};
int n;
ll s;
vector<edge>g[N+1];
inline ll all(ll t){
	return t*s;
}
inline ll day(ll t){
	return t/s;
}
inline ll tick(ll t){
	return t%s;
}
static bool vis[N+1];
static ll dis[N+1];
static int tagVis[N+1],tagDis[N+1],Tag;
struct cmp{
	bool operator ()(const int &a,const int &b){
		return dis[a]>dis[b];
	}
};
inline ll Dijkstra(int u,int v,ll t){
	priority_queue<int,vector<int>,cmp>q;
//	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	Tag++;
	dis[u]=t;tagDis[u]=Tag;
	q.push(u);
	while(q.size()){
		int x=q.top();q.pop();
		if(tagVis[x]!=Tag){
			tagVis[x]=Tag;
			vis[x]=false;
		}
		if(vis[x]){
			continue;
		}
		vis[x]=true;
		if(x==v){
			return dis[v];
		}
		for(auto &i:g[x]){
			if(tagVis[i.v]!=Tag){
				tagVis[i.v]=Tag;
				vis[i.v]=false;
			}
			if(vis[i.v]){
				continue;
			}
			if(tagDis[i.v]!=Tag){
				tagDis[i.v]=Tag;
				dis[i.v]=inf;
			}
			if(tick(dis[x])+i.l<=i.c){
				if(dis[x]+i.l<dis[i.v]){
					dis[i.v]=dis[x]+i.l;
					q.push(i.v);
				}
			//第二天 
			}else{
				ll pl=all(day(dis[x])+1)+i.l;
				if(pl<dis[i.v]){
					dis[i.v]=pl;
					q.push(i.v);
				}
			}
		}
	}
}
/*
ll SPFA(int u,int v,ll t){
	static ll dis[N+1];
	static bool in[N+1];
	memset(in,0,sizeof(in));
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	q.push(u);
	in[u]=true;
	dis[u]=t;
	while(q.size()){
		int x=q.front();q.pop();
		in[x]=false;
		for(auto i:g[x]){
			if(tick(dis[x])+i.l<=i.c){
				if(dis[x]+i.l<dis[i.v]){
					dis[i.v]=dis[x]+i.l;
					if(!in[i.v]){
						in[i.v]=true;
						q.push(i.v);
					}
				}
			//第二天 
			}else{
				ll pl=all(day(dis[x])+1)+i.l;
				if(pl<dis[i.v]){
					dis[i.v]=pl;
					if(!in[i.v]){
						in[i.v]=true;
						q.push(i.v);
					}
				}
			}
		}
	}
	return dis[v];
}
*/
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int m,q;
	cin>>n>>m>>s>>q;
	while(m--){
		int u,v;
		ll l,c;
		cin>>u>>v>>l>>c;
		u++,v++;
		g[u].push_back({v,l,c});
		g[v].push_back({u,l,c});
	}
	int Time=clock();
//	cerr<<"IO has spent "<<1.0*Time/CLOCKS_PER_SEC<<'s'<<endl;
	while(q--){
		int u,v;
		ll t;
		cin>>u>>v>>t;
		u++,v++;
		cout<<Dijkstra(u,v,t)-t<<'\n';
//		if(q%1000==0){
//			cerr<<"q="<<q<<endl;
//		}
	}
//	cerr<<1.0*(clock()-Time)/CLOCKS_PER_SEC<<'s'<<endl;
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
8 12 1000000000000000 13
2 0 4451698272827 120985696255786
6 5 78520421713825 342652131468508
2 1 185377268405175 382583457603811
0 4 54350742205838 133614919589507
7 0 68486247989149 651590905094148
0 6 85177550834829 299184420663240
5 2 442329739732459 926608308293721
3 7 78020232822359 913548478810253
1 3 267796317244889 687571310475622
5 4 90590208828121 910324397566584
5 7 8414633059584 17796117322043
4 6 45682367792138 204548471584556
7 2 44779065000162
3 5 79376234836942
4 7 305556687070759
4 3 927935834343174
5 1 663284649258985
2 5 967584209777344
5 2 963749709374595
7 4 484562389171308
1 5 446160773830045
6 4 801452311055604
3 1 744524289545354
0 6 467418420721777
5 6 371181379240653

72937946261976
929038398222642
702857945988825
272921388674172
580895059624855
181808439529442
117602869946965
569788353034530
1181546234307589
244230056736534
513790925121797
617759130113052
674500988551485
*/
