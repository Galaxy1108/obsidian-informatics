#include<bits/stdc++.h>
using namespace std;
int n;
const int M=2005;
#define int long long
int w[M][M];
int minw=1e9;
unordered_set<int> s[M];
unordered_set<int> po;
struct info{int minn,val,id;};
inline bool operator <(const info &a,const info &b){return a.val>b.val;}
priority_queue<info> q;
void solve(int id){
	for(int i=1;i<=n;i++)s[i].clear();
	while(!q.empty())q.pop();
	if(po.count(id))return cout<<1ll*(n-1)*minw<<"\n",void();
	q.push({1000000000,0,id});
	while(!q.empty()){
		auto u=q.top();q.pop();
		if(s[u.id].count(u.minn))continue;
		if(po.count(u.id))return cout<<u.val+1ll*(n-1)*minw<<"\n",void();
		s[u.id].insert(u.minn);
		for(int i=1;i<=n;i++){
			if(i^u.id&&i^id){
				q.push({min(u.minn,w[u.id][i]),u.val+min(u.minn,w[u.id][i])-minw,i});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			cin>>w[i][i+j];
			minw=min(minw,w[i][i+j]);
			w[i+j][i]=w[i][i+j];
		}
	}
	for(int i=1;i<n;i++)for(int j=1;j<=n-i;j++)if(w[i][i+j]==minw)po.insert(i),po.insert(i+j);
	for(int i=1;i<=n;i++)solve(i);
	return 0;
}