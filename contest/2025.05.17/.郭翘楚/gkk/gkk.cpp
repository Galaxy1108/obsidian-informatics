#include <bits/stdc++.h>
using namespace std;
int fa[1010];
struct edge {
	int u, v, w;
};
int l;
int cnt;
int n, m;
struct lines{
	int u, v;
	friend bool operator<(lines a,lines b){
		return (a.u == b.u ? a.v < b.v : a.u < b.u);
	}
};
struct linee{
	int u, v, w;
};
map<lines, int> s;
linee g[40000000];

lines make_line(int u,int v){
	return {min(u, v), max(u, v)};
}
int findroot(int x) {
	return fa[x] == x ? x : fa[x] =findroot(fa[x]);
}
void Merge(int x, int y) {
	x = findroot(x);
	y = findroot(y);
	fa[x] = y;
}
void insert(int u,int v,int w){
	if(!s.count(make_line(u, v))){
		s[make_line(u, v)] = w;
		return;
	}
	int old_w = s[make_line(u, v)];
	s[make_line(u, v)] = min(old_w, w);
}
void kruskal()
{
	int tot = 0;
	int ans = 0;
	for (int i = 0; i < cnt and tot<n; i++)
	{
		int xr = findroot(g[i].u), yr = findroot(g[i].v);
		if (xr != yr) {
			Merge(xr, yr); 
			tot++; 
			ans += g[i].w;
		}
	}
	cout<<ans;
}
bool cmp(linee a,linee b){
	return a.w < b.w;
}
int main(){
	freopen("gkk.in","r",stdin);
	freopen("gkk.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < m;i++){
		int a, b, c;
		cin >> a >> b >> c;
		bool adds = false;
		insert(a, b, c);
		int at = a + 1, bt = b;
		for (;at!=a || bt!=b;(adds ? (at++,at%=n) : (bt++,bt%=n)),adds^=1){
			insert(at, bt, ++c);
		}
	}
	for(auto its:s){
		g[cnt++] = {its.first.u, its.first.v, its.second};
	}
	sort(g, g + cnt, cmp);
	kruskal();
}
