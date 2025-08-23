#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef pair<int,int>pii;
int n,fa[N],w[N];
int siz[N];
vector<pii>G[N];
int ans[N];
typedef long long ll;
ll mx;
vector<int>res;
void dfs(int x,int fa){
	siz[x]=1;
	for(pii i:G[x])if(i.fi^fa){
		dfs(i.fi,x);
		siz[x]+=siz[i.fi];
		if(1ll*i.se*siz[i.fi]>mx){
			mx=1ll*i.se*siz[i.fi];
			res.clear();
		}if(mx==1ll*i.se*siz[i.fi])res.push_back(i.fi);
	}
}
int main(){
	scanf("%d",&n);
	
	return 0;
}
