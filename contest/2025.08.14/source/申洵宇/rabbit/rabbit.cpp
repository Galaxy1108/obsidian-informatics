#include <bits/stdc++.h>
using namespace std;
#define N 105
#define MOD 998244353ll
struct node{
	int v,tp;
	node(int v_=0,int tp_=0):v(v_),tp(tp_){}
};
int n,m,st,ed;
int rd[N];
long long p[N][N],inv[N*N];
//long double p2[N][N];
vector<node>e[N];
long long mpow(long long base,long long p){
	long long res=1;
	while(p){
		if(p&1)res=res*base%MOD;
		p>>=1;
		base=base*base%MOD;
	}
	return res;
}
void init(){
	for(int i=1;i<=n*n;i++){
		inv[i]=mpow(i,MOD-2);
	}
}
void solvedag(){
	queue<int,list<int>>que;
	p[st][0]=1;
//	p2[st][0]=1.0;
	for(int i=1;i<=n;i++){
		if(rd[i]==0){
			que.emplace(i);
		}
	}
	while(!que.empty()){
		static int x;x=que.front();
		que.pop();
		for(auto v:e[x]){
//			if(v.v==5||v.v==4)cerr<<x<<"->"<<v.v<<":"<<v.tp<<endl;
			if(v.tp==0){
				for(int i=0;i<=n;i++){
					p[v.v][0]=(p[v.v][0]+inv[e[x].size()]*p[x][i]%MOD)%MOD;
//					p2[v.v][0]+=p2[x][i]/(1.0L*e[x].size());
				}
			}
			else if(v.tp==1){
				for(int i=1;i<=n;i++){
					p[v.v][i]=(p[v.v][i]+inv[e[x].size()]*p[x][i-1]%MOD)%MOD;
//					p2[v.v][i]+=p2[x][i-1]/(1.0L*e[x].size());
				}
			}
			rd[v.v]--;
			if(rd[v.v]==0){
//				if(e[v.v].size()==0){
//					cerr<<v.v<<":\n";
//					for(int i=0;i<=n;i++){
//						if(p2[v.v][i]>1e-10||i<=2)
//							cerr<<i<<":"<<fixed<<setprecision(10)<<p2[v.v][i]<<endl;
//					}
//				}
				que.emplace(v.v);
			}
		}
	}
//	for(int i=0;i<=n;i++){
//		p[92][i]=(p[92][i]+p[90][i]%MOD)%MOD;
//		p2[92][i]+=p2[90][i];
//	}
//	cerr<<"!!"<<e[4].size()<<endl;
	long long ex=0,/*sp=0,*/varx=0;
//	long double sp2=0.0;
	for(int i=0;i<=n;i++){
//		cerr<<i<<":"<<p[ed][i]<<endl;
//		cerr<<i<<":"<<fixed<<setprecision(10)<<p2[ed][i]<<endl;
		ex=(ex+1ll*i*p[ed][i]%MOD)%MOD;
//		sp=(sp+p[ed][i])%MOD;
//		sp2+=p2[ed][i];
	}
//	cerr<<sp<<"|"<<fixed<<setprecision(10)<<sp2<<endl;
	for(int i=0;i<=n;i++){
		varx=(varx+(1ll*i-ex)*(1ll*i-ex)%MOD*p[ed][i]%MOD)%MOD;
	}
//	cerr<<ex<<' '<<varx;
	cout<<ex<<' '<<varx;
}
int main(){
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>st>>ed;
	init();
	int _x,_y,_o;
	bool subo0=true,subdag=true;
	for(int i=1;i<=m;i++){
		cin>>_x>>_y>>_o;
		rd[_y]++;
		e[_x].emplace_back(_y,_o);
		if(_o!=0)subo0=false;
		if(_x>=_y)subdag=false;
	}
	if(subo0){
		cout<<"0 0";
	}
	else if(subdag){
		solvedag();
	}
	else{
		cout<<"0 0";
	}
	return 0;
}

