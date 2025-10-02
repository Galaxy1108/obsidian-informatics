#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define INF 0x3f3f3f3f
int n,m,q,c[2],p[N],f[N][N][2];
int solve(int x){
	for(int i=x;i<=n;i++){
		// cerr<<i<<"::\n";
		for(int j=0;j<=c[0];j++){
			if(p[i]==-1){
				if(j>0)f[i][j][0]=min(f[i-1][j-1][0],f[i-1][j-1][1]+1);
				if(j<i)f[i][j][1]=min(f[i-1][j][1],f[i-1][j][0]+1);
			}
			else if(p[i]==0){
				if(j>0)f[i][j][0]=min(f[i-1][j-1][0],f[i-1][j-1][1]+1);
				f[i][j][1]=INF;
			}
			else if(p[i]==1){
				f[i][j][0]=INF;
				if(j<i)f[i][j][1]=min(f[i-1][j][1],f[i-1][j][0]+1);
			}
			// cerr<<j<<":("<<f[i][j][0]<<","<<f[i][j][1]<<")\n";
		}
	}
	return min(f[n][c[0]][0],f[n][c[0]][1]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	long long op,_p,_t;
	for(int i=1;i<=n;i++){
		cin>>_t;
		c[_t&1]++;
		p[i]=-1;
	}
	for(int i=1;i<=m;i++){
		cin>>_p>>_t;
		p[_p]=_t&1;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=c[0];j++){
			f[i][j][0]=f[i][j][1]=INF;
		}
	}
	f[0][0][0]=f[0][0][1]=0;
	solve(1);
	while(q--){
		cin>>op>>_p;
		if(op==1){
			p[_p]=-1;
		}
		else if(op==2){
			cin>>_t;
			p[_p]=_t&1;
		}
		cout<<solve(_p)<<'\n';
	}
	return 0;
} 
