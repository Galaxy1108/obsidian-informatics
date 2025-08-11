#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,q,cnt;
bool subtask1;
vector<int>c[N];
vector<pair<int,int>>e[N];
int fa[N],ue[N],dep[N];
priority_queue<int,vector<int>,greater<int>>pq;
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	for(auto v:e[x]){
		if(v.first==f)continue;
		ue[v.first]=v.second;
		dfs(v.first,x);
	}
}
inline void add(int &x){
	cnt+=c[ue[x]].size();
	if(!subtask1){
		for(auto v:c[ue[x]]){
			pq.emplace(v);
		}
	}
	x=fa[x];
}
int main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	int _u,_v,_lv=0;
	for(int i=1;i<n;i++){
		cin>>_u>>_v;
		e[_u].emplace_back(_v,i);
		e[_v].emplace_back(_u,i);
	}
	dfs(1,0);
	subtask1=true;
	for(int i=1;i<=m;i++){
		cin>>_u>>_v;
		c[_u].emplace_back(_v);
		if(i>1&&_lv!=_v)subtask1=false;
		_lv=_v;
	}
	int xk;
	long long yk;
	while(q--){
		cin>>_u>>_v>>xk>>yk;
		while(!pq.empty())pq.pop();
		cnt=0;
		if(dep[_u]>dep[_v])swap(_u,_v);
		while(dep[_v]>dep[_u]){
			add(_v);
		}
		while(_u!=_v){
			add(_u);
			add(_v);
		}
		if(!subtask1){
			while(!pq.empty()){
	//			cerr<<"T"<<pq.top()<<" ";
				if(yk-pq.top()>=0){
					yk-=pq.top();
					pq.pop();
					cnt--;
				}
				else break;
			}
		}
		else{
			cnt-=min((long long)cnt,yk/((long long)_lv));
		}
		if(xk>=cnt){
			cout<<xk-cnt<<'\n';
		}
		else{
			cout<<"-1\n";
		}
	}
	return 0;
}

