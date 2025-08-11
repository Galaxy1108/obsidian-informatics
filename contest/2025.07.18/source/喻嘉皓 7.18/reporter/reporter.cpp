#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=200010;
int n;
struct PER{
	int to,h,c; 
}p[N];
int fa[N];
vector<int> g[N];
int ans=0;
void dfs(int s){
	bool flag=0;
	for(int to:g[s]){
		if(to==fa[s]) continue;
		if(!flag&&p[to].h<p[s].h){
			ans+=p[s].c;
			flag=1;
		}
	}
}
signed main(){
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].to>>p[i].h>>p[i].c;
		fa[i]=p[i].to;
		g[p[i].to].pb(i);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

