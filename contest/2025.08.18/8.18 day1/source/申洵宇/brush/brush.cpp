#include <bits/stdc++.h>
using namespace std;
/*
f[i][j]:前i块满足要求时，第i块刷了，上一块刷在i-j（1<=j<=m-1）的位置 
f[i-j][j']->f[i][j](j'<=m-j) 
*/
#define N 10005
#define M 105
#define INF 0x3f3f3f3f3f3f3f3fll
int n,m;
long long f[N][M],a[N];
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=2;i<=n&&i<=m;i++){
		for(int imj=1;imj<i;imj++){
			f[i][i-imj]=min(f[i][i-imj],a[i]+a[imj]);
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=m-1&&i-j>=1;j++){
			for(int jp=1;jp<=m-j&&i-j-jp>=1;jp++){
//				if(f[i-j][jp]!=INF){
//					cerr<<i<<","<<j<<","<<jp<<endl;
//				}
				f[i][j]=min(f[i][j],f[i-j][jp]+a[i]);
			}
		}
	}
	long long ans=INF;
	for(int i=max(1,n-m+1);i<=n;i++){
		for(int j=1;j<=m-1&&j<=i-(n-m+1);j++){
//			cerr<<i<<","<<j<<endl;
			ans=min(ans,f[i][j]);
		}
	}
//	cerr<<f[3][2]<<','<<f[4][1]<<','<<f[6][2]<<','<<f[7][1]<<endl;
	cout<<ans;
	return 0;
}

