#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mo=9999973;

int f[101][101][101];
int n,m;
int total=0;

int work(int x){
	return ((x%mo*(x-1)%mo)%mo/2)%mo;
}

signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	f[0][0][m]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m-j;k++){
				f[i][j][k]=(f[i][j][k]%mo+f[i-1][j][k]%mo)%mo;
				if(j>=1) f[i][j][k]=(f[i][j][k]%mo+(f[i-1][j-1][k+1]%mo*(k+1)%mo)%mo)%mo;
				if(j<=m-1&&i>1&&j+1+k<=m) f[i][j][k]=(f[i][j][k]%mo+(f[i-1][j+1][k]%mo*(j+1)%mo)%mo)%mo;
				if(j>=2) f[i][j][k]=(f[i][j][k]+(f[i-1][j-2][k+2]%mo*work(k+2)%mo)%mo)%mo;
				if(j<=m-2&&i>1&&j+2+k<=m) f[i][j][k]=(f[i][j][k]+(f[i-1][j+2][k]%mo*work(j+2)%mo))%mo;
				if(k<=m-1&&i>1&&j+k+1<=m) f[i][j][k]=(f[i][j][k]+(((f[i-1][j][k+1]%mo*(k+1)%mo)%mo*j%mo)%mo)%mo)%mo;
//				cout<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
				if(i==n) total=(total%mo+f[i][j][k]%mo)%mo;
			}
		}
	}
	cout<<total<<endl;
	return 0;
}
