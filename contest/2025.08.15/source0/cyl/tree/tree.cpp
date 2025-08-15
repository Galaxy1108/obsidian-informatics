#include<bits/stdc++.h>
#define L(i,j,k) for(int i = (j); i <= (k); ++i)
#define R(i,j,k) for(int i = (j); i >= (k); --i)
#define ll long long
using namespace std;
const int N = 5e3 + 5;
ll dis[N][N];
int fa[N], n;
ll w[N];
vector <pair<int, ll > > ta[N];
void dfs(int wi, int u, int fz, ll ds){
	dis[u][wi] = ds;
	for(auto v:ta[wi]){
		if(v.first == fz) continue;
		dfs(v.first, u, wi, ds + v.second);
	}
}
int fb[N]; ll ax[N];
vector <int> tt[N];
ll ans[N];
void work(int u, int wi, ll dd, ll dx){
	if(u != wi){
		ans[u] = max(ans[u], dis[u][wi] + dx);
	}
	for(int v:tt[wi]){
		work(u, v, dd + ax[wi], dx + dd + ax[wi]);
	}
	
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 2, n){
		cin >> fa[i]; 
	}
	L(i, 2, n){
		cin >> w[i];
		ta[fa[i]].push_back(make_pair(i, w[i]));
		ta[i].push_back( make_pair(fa[i], w[i]));
	}
	L(i, 1, n){
		dfs(i, i, 0, 0);
	}
	L(i, 2, n){ cin >> fb[i]; tt[fb[i]].push_back(i);}
	L(i, 1, n){ cin >> ax[i];}
	L(i, 1, n){
		work(i, i, 0, 0);
	}
	L(i, 1, n){
		cout << ans[i] <<" ";
	}
	return 0;
}

