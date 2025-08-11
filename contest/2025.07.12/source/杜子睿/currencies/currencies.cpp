#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct node{
	int x,y;
}s[100005];
vector<int> e[100005],w[100005];
int d[100005],f[100005],l[100005],idx;
void dfs(int x){
	for(int i:e[x])
		if(!d[i]){
			d[i]=d[x]+1;
			f[i]=x;
			dfs(i);
		}
}
void lca(int x,int y){
	if(d[x]>d[y])
		swap(x,y);
	while(d[y]!=d[x]){
		for(int i:w[y])
			l[idx++]=i;
		y=f[y];
	}
	while(x!=y){
		for(int i:w[x])
			l[idx++]=i;
		for(int i:w[y])
			l[idx++]=i;
		x=f[x];
		y=f[y];
	}
}
int main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=0;i<n-1;i++){
		cin>>s[i].x>>s[i].y;
		e[s[i].x].push_back(s[i].y);
		e[s[i].y].push_back(s[i].x);
	}
	f[1]=1;
	d[1]=1;
	dfs(1);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		int u=s[x-1].x,v=s[x-1].y;
		if(f[v]==u)
			swap(u,v);
		w[u].push_back(y);
	}
	for(int i=0;i<q;i++){
		int x,y;
		long long g,s;
		cin>>x>>y>>g>>s;
		idx=0;
		lca(x,y);
		sort(l,l+idx);
		for(int j=0;j<idx;j++){
			if(l[j]>s)
				g--;
			else
				s-=l[j];
		}
		if(g<0)
			cout<<"-1\n";
		else	
			cout<<g<<endl;
	}
	return 0;
}

