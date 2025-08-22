#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N][N],n;
inline void In(){
	int seed;
	cin>>n>>seed;
	if(seed){
		mt19937 rng(seed);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n+1;++j)
				a[i][j]=j,swap(a[i][j],a[i][rng()%j+1]);
	}
	else{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n+1;++j) cin>>a[i][j];
	}
}
inline int pre(int x){return x==1?n:x-1;}
int vis[N],Id[N],ans[N];
inline void pre(){
	for(int i=n;i;--i){
		int x=0;
		for(int j=1;j<=n+1;++j)
			if(!vis[j]&&(!x||a[i][j]<a[i][x])) x=j;
		vis[x]=1,Id[i]=x;
	}
	for(int i=1;i<=n+1;++i)
		if(!vis[i]) ans[1]=i;
}
inline void solve(){
	for(int T=n;T>1;--T){
		int val=Id[T];
		vis[val]=0;
		for(int i=pre(T);i!=T;i=pre(i))
			if(a[i][val]<a[i][Id[i]]) swap(val,Id[i]),vis[Id[i]]=1,vis[val]=0;
		val=0;
		for(int i=1;i<=n+1;++i)
			if(!vis[i]&&(!val||a[T][val]>a[T][i])) val=i;
		vis[val]=1,Id[T]=val;
		for(int i=1;i<=n+1;++i)
			if(!vis[i]) ans[T]=i;
	}
}
void File_Work(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
}
signed main(){
	File_Work();
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	In();
	pre();
	solve();
	for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
}
