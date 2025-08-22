#include<bits/stdc++.h>
using namespace std;
int n,vis[17],seed,ans;
const int MAXN=5010;
int a[MAXN][MAXN];
void gen(int n,int seed){
    mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int nxt(int x){
	return x%n+1;
}
int dfs(int nw,int u){
	if(nw==n+1){
		for(int i=1;i<=n+1;++i)
			if(!vis[i]) return i;
	}
	int res=0,res_;
	for(int i=1;i<=n+1;++i){
		if(vis[i]) continue;
		vis[i]=1;
		int v=dfs(nw+1,nxt(u));
		if(a[u][v]>res){
			res=a[u][v];
			res_=v;
		}
		vis[i]=0;
	}
	return res_;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>seed;
	if(seed==0){
		for(int i=1;i<=n;++i)
        	for(int j=1;j<=n+1;++j)
        		cin>>a[i][j];
	}else gen(n,seed);
	for(int i=1;i<=n;++i)
		cout<<dfs(1,i)<<' ';
	return 0;
}

