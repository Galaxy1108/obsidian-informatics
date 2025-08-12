#include <bits/stdc++.h>
using namespace std;
#define N 120005
#define INF 0x3f3f3f3f
int n,m,s[N],t[N],dis1[N],dis2[N],p1[N],p2[N];
vector<int>e[N];
bool dfs(int x,int ed,int* dis){
	if(x==ed)return true;
	for(auto v:e[x]){
		if(dis[v]!=INF)continue;
		dis[v]=dis[x]+1;
		if(dfs(v,ed,dis))return true;
		dis[v]=-1;
	}
	return false;
}
void getval(int st,int ed,int* dis,int* p){
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[st]=0;
	dfs(st,ed,dis);
	for(int i=1;i<=n;i++){
		if(dis[i]!=INF&&dis[i]!=-1)p[dis[i]]=i;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)e[i].clear();
	int _u,_v;
	bool sub1=true;
	for(int i=1;i<n;i++){
		cin>>_u>>_v;
		if(_u!=i||_v!=i+1)sub1=false;
		e[_u].emplace_back(_v);
		e[_v].emplace_back(_u);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>s[i]>>t[i];
	}
	if(sub1){
		static int a1[N],a2[N];
		for(int i=1;i<=m;i++){
			a1[i]=a2[i]=i;
		}
		sort(a1+1,a1+m+1,[&](int x,int y)->bool{return s[x]<s[y];});
		sort(a2+1,a2+m+1,[&](int x,int y)->bool{return t[x]<t[y];});
		bool ans=true;
		for(int i=1;i<=m;i++){
			if(a1[i]!=a2[i]){
				ans=false;
				break;
			}
		}
		if(ans){
			cout<<"Yes\n";
		} 
		else{
			cout<<"No\n";
		}
	}
	else if(m==2){
		getval(s[1],t[1],dis1,p1);
		getval(s[2],t[2],dis2,p2);
		bool s1=false,s2=false,t1=false,t2=false;
		//两条路径的起点在对方路径中/终点在对方路径中
		for(int i=0;i<dis1[t[1]];i++){
			if(p1[i]==s[2])s2=true;
			if(p1[i]==t[2])t2=true;
		} 
		for(int i=0;i<dis2[t[2]];i++){
			if(p2[i]==s[1])s1=true;
			if(p2[i]==t[1])t1=true;
		} 
		if((s1&&s2)||(t1&&t2)||(s1&&t1)||(s2&&t2)){
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
	}
	else{
		cout<<"No\n";
	}
}
int main(){
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
