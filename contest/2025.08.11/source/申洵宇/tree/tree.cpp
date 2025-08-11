#include <bits/stdc++.h>
using namespace std;
/*
f[i].s/c:以i为根，i子树内非空连通块的最大点权平均值时,s:点权和,c个数 
*/
#define N 500005
struct node{
	long long s,c;
}f[N]; 
int n,fat[N],w[N];
vector<int>e[N];
void dfs1(int x,int fa){
	f[x].s=w[x];
	f[x].c=1;
	for(int v:e[x]){
		if(v==fa)continue;
		dfs1(v,x);
	}
//	shuffle(e[x].begin(),e[x].end(),mt19937((unsigned)time(NULL)));
	sort(e[x].begin(),e[x].end(),[&](int u,int v)->bool{
		if((__int128)f[u].s*f[v].c==(__int128)f[v].s*f[u].c) {
			return f[u].c>f[v].c;
		}
		return (__int128)f[u].s*f[v].c>(__int128)f[v].s*f[u].c;
	});
	for(int v:e[x]){
		if(v==fa)continue;
		if((__int128)f[x].s*f[v].c<=(__int128)f[v].s*f[x].c){//相等时加了更好 
		 /*f[x].s/f[x].c<=f[v].s/f[v].c*/
			f[x].s+=f[v].s;
			f[x].c+=f[v].c;
		} 
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>fat[i];
		e[fat[i]].emplace_back(i); 
		e[i].emplace_back(fat[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dfs1(i,0);
		cout<<fixed<<setprecision(10)<<((long double)f[i].s)/((long double)f[i].c)<<'\n';
	}
	return 0;
}
