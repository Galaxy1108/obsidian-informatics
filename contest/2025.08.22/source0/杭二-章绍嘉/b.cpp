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
#define int ll
const int N=2010,inf=1e18;
int n,e[N][N],dis[N];
bool vis[N];
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	array<int,3> mn({inf,0,0}),cur;
	rep(i,1,n) rep(j,i+1,n){
		int x;cin>>x;
		e[i][j]=e[j][i]=x;
		cur={x,i,j};
		ckmn(mn,cur);
	}
	rep(i,1,n) rep(j,1,n) if(i!=j) e[i][j]-=mn[0];
	dis[mn[1]]=dis[mn[2]]=0;
	rep(i,1,n) if(i!=mn[1] && i!=mn[2])
		dis[i]=min(e[i][mn[1]],e[i][mn[2]]);
	rep(i,1,n) if(i!=mn[1] && i!=mn[2])
	rep(j,1,n) if(j!=mn[1] && j!=mn[2] && j!=i)
		ckmn(dis[i],2*e[i][j]);
	rep(_,1,n-1){
		int x=0;
		rep(i,1,n) if(!vis[i] && (!x || dis[i]<dis[x])) x=i;
		assert(x);
		vis[x]=true;
		rep(i,1,n) if(i!=x){
			if(dis[i]>dis[x]+e[x][i]){
				dis[i]=dis[x]+e[x][i];
			}
		}
	}
	rep(i,1,n) cout<<dis[i]+mn[0]*(n-1)<<"\n";
return 0;}
/*
*/