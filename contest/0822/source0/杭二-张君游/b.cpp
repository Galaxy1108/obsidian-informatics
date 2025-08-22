#include<bits/stdc++.h>
#define LL long long
#define LLL __int128
#define uint unsigned
#define ldb long double
#define uLL unsigned long long
using namespace std;
const int N=2e3+5,M=N*N/2;
const LL INF=1e10;
int n,m;
LL w=INF,D[N],nD[N],G[N][N];
signed main(){
    cin.tie(0)->sync_with_stdio(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	if(n==1)return cout<<"0\n",0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			cin>>G[i][j],w=min(w,G[i][j]),G[j][i]=G[i][j];
	for(int i=1;i<=n;++i){
		D[i]=INF;
		for(int j=1;j<=n;++j)
			if(G[i][j]==w)D[i]=0;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j&&!D[j])D[i]=min(D[i],G[i][j]-w);
	for(int i=1;i<=n;++i){
		nD[i]=D[i];
		for(int j=1;j<=n;++j)
			if(i!=j)nD[i]=min(nD[i],G[i][j]-w+min(G[i][j]-w,D[j]));
	}
	for(int k=0;k<30;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)if(i!=j)
				nD[i]=min(nD[i],nD[j]+G[i][j]-w);
	for(int i=1;i<=n;++i)cout<<nD[i]+(n-1)*w<<'\n';
    return 0;
}