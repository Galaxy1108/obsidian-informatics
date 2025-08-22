#include<bits/stdc++.h>
#define LL long long
#define LLL __int128
#define uint unsigned
#define ldb long double
#define uLL unsigned long long
using namespace std;
const int N=5e3+5;
int n,seed;
int pos[N+N],lnk[N],a[N][N],b[N][N];
inline void push(int k){
	const int p=k>n?k-n:k;
	for(;lnk[b[p][pos[k]]]>k;++pos[k]);
	const int x=lnk[b[p][pos[k]]];
	lnk[b[p][pos[k]]]=k;
	if(x)push(x);
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>seed;
	if(seed){
		mt19937 rng(seed);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n+1;++j)
				a[i][j]=j,swap(a[i][j],a[i][rng()%j+1]);
	}
	else{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n+1;++j)
				cin>>a[i][j];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n+1;++j)
			b[i][a[i][j]]=j;
	for(int i=n;i>=1;--i){
		for(pos[i]=1;lnk[b[i][pos[i]]];++pos[i]);
		lnk[b[i][pos[i]]]=i;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n+1;++i)if(!lnk[i])cout<<i<<" \n"[k==n];
		lnk[b[k][pos[k]]]=0,pos[k+n]=1,push(k+n);
	}
    return 0;
}