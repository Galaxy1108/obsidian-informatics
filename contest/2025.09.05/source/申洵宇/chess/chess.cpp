#include <bits/stdc++.h>
using namespace std;
#define N 105
#define MOD 9999973
int n,m;
long long f[N][N][N];
inline void add(long long &x,long long y){
	x+=y;
	x-=(x>=MOD?MOD:0);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	f[0][m][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;j+k<=m;k++){
				//0
				add(f[i][j][k],f[i-1][j][k]);
				//1:0->1
				if(j>=1)add(f[i][j-1][k+1],f[i-1][j][k]*j%MOD);
				//1:1->2
				if(k>=1)add(f[i][j][k-1],f[i-1][j][k]*k%MOD);
				//2:0->1,0->1
				if(j>=2)add(f[i][j-2][k+2],f[i-1][j][k]*(1ll*j*(j-1ll)/2ll%MOD)%MOD);
				//2:0->1,1->2
				if(j>=1&&k>=1)add(f[i][j-1][k],f[i-1][j][k]*j%MOD*k%MOD);
				//2:1->2,1->2
				if(k>=2)add(f[i][j][k-2],f[i-1][j][k]*(1ll*k*(k-1ll)/2ll%MOD)%MOD);
			}
		}
	}
	long long ans=0;
	for(int j=0;j<=m;j++){
		for(int k=0;j+k<=m;k++){
			add(ans,f[n][j][k]);
		}
	}
	cout<<ans;
	return 0;
}

