#include<bits/stdc++.h>
//#define int long long
using namespace std;
vector<pair<int,int>>a[100001];
vector<int>money[100001];
int s,t,x;
int n,m,q,vis[100001],road[100001][3],route[100001],cnt;
long long y;
int dfs(int now,int final){
	if(now==final){
		
//		for(int i=1;i<=cnt;i++)cout<<route[i]<<' ';
//		cout<<endl;
		sort(route+1,route+cnt+1);
//		for(int i=1;i<=cnt;i++)cout<<route[i]<<' ';
//		cout<<endl;
		for(int i=1;i<=cnt;i++){
			if(y-route[i]>=0)y-=route[i];
			else if(route[i])x--;
		}
		cout<<max(x,-1)<<endl;
	}
	vis[now]=1;
	for(auto i:a[now]){
		if(!vis[i.first]){
			int t=0;
			for(int j:money[i.second]){
				t++;
				route[++cnt]=j;
			}
			dfs(i.first,final);
			cnt-=t;
		}
	}
}
int main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<n;i++){
		cin>>road[i][0]>>road[i][1];
	}
	for(int i=1;i<=m;i++){
		int k,r;
		cin>>k>>r;
		money[k].push_back(r);
	}
	for(int i=1;i<=n;i++){
		a[road[i][0]].push_back({road[i][1],i});
		a[road[i][1]].push_back({road[i][0],i});  
	}
	for(int i=1;i<=q;i++){
		memset(vis,0,sizeof(vis));
		cin>>s>>t>>x>>y;
		dfs(s,t);
	} 
	return 0;
}
