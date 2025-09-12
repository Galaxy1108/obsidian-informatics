#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("game.in"); ofstream fout("game.out");
constexpr int MAXN=2e5;
using ll=long long;
ll W[MAXN+5];
void solve(){
	int N=0,M=0;
	fin>>N>>M;
	fill(W+1,W+N+1,0);
	for(int m=1;m<=M;m++){
		int u,v; ll w;
		fin>>u>>v>>w;
		W[u]+=w;
		W[v]+=w;
	}
	sort(W+1,W+N+1);
	ll ans=0;
	for(int ng=0,i=N;i>=1;i--,ng^=1){
		if(ng) ans-=W[i];
		else ans+=W[i];
	}
	ans>>=1;
	fout<<ans<<'\n';
	return ;
}
int main(){
	int T;
	fin>>T;
	for(int t=1;t<=T;t++){
		solve();
	}
	return 0;
}
