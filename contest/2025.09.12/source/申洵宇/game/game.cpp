#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,col[N];
map<int,long long>mp[N];
vector<pair<int,long long>>e[N];
long long getans(int st){
	for(int i=1;i<=n;i++)col[i]=0;
	col[st]=1;
	for(int _=2;_<=n;_++){
		
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)mp[i].clear(),e[i].clear();
	int _u,_v,_w;
	bool subj=true;
	for(int i=1;i<=m;i++){
		cin>>_u>>_v>>_w;
		if(_u!=1)subj=false;
		mp[_u][_v]+=_w;
		if(_v!=_u)mp[_v][_u]+=_w;
	}
	static long long ans;
	ans=0;
	for(int i=1;i<=n;i++){
		for(auto v:mp[i]){
			if(subj&&i==1&&v.first==1){
				ans+=v.second;
				continue;
			} 
			e[i].emplace_back(v);
		}
	}
	if(subj){
//		for(vector<pair<int,long long>>::iterator it=e[1].begin();it!=e[1].end();it++){
//			if(it->first==1){
//				ans+=it->second;
//				e[1].erase(it);
//				break;
//			}
//		}
		sort(e[1].begin(),e[1].end(),[&](pair<int,long long>x,pair<int,long long>y)->bool{return x.second>y.second;});
		for(int i=0;i<e[1].size();i++){
			if(i&1)ans+=e[1][i].second;
		}
		cout<<ans<<'\n';
	}
	else{
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,getans(i));
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
