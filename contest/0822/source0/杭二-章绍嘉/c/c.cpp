#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii<=Ii##_;Ii++)
#define per(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii>=Ii##_;Ii--)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double db;
#define fir first
#define sec second
#define siz(Aa) ((int)(Aa).size())
#define all(Aa) (Aa).begin(),(Aa).end()
#define ckmx(Aa,Bb) (Aa=max(Aa,Bb))
#define ckmn(Aa,Bb) (Aa=min(Aa,Bb))
const int N=20;
int n,seed,a[N][N],f[N][1<<17];
bool vis[N][1<<17];
int dfs(int x,int s){
	assert(__builtin_popcount(s)==n+2-x);
	if(vis[x][s]) return f[x][s];
	vis[x][s]=true;
	int&res=f[x][s];
	if(x==n+1){
		res=__lg(s)+1;
	}else{
		int now=0;
		rep(i,0,n) if(s>>i&1){
			int tmp=dfs(x+1,s^(1<<i));
			if(!now || (a[x][now]<a[x][tmp])) now=tmp;
		}
		res=now;
	}
	return res;
}
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>seed;
	if(seed){
	    mt19937 rng(seed);
	    rep(i,1,n){
	    	rep(j,1,n+1){
	            a[i][j]=j;
	            swap(a[i][j],a[i][rng()%j+1]);
	        }
	    }
	}else{
		rep(i,1,n) rep(j,1,n+1) cin>>a[i][j];
	}
	rep(i,1,n){
		// rep(j,1,n) rep(k,1,n+1) cout<<a[j][k]<<" \n"[k==k_];
		fill(&vis[0][0],&vis[N-1][(1<<17)-1]+1,false);
		cout<<dfs(1,(1<<(n+1))-1)<<" \n"[i==i_];
		rep(j,2,n) swap(a[j-1],a[j]); 
	}
return 0;}
/*
*/