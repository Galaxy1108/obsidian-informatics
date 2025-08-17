#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[5001][5001],b[5001][5001],mod=1e9+7;
signed main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z,l,r;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		for(int j=1;j<=n;j++){
			if(j>=x&&j<=y) a[i][j]=a[i-1][j]+z;
			else a[i][j]=a[i-1][j];
			b[i][j]=b[i][j-1]+a[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		cin>>x>>y>>l>>r;
		ans=0;
		for(int j=x;j<=y;j++){
			ans+=b[j][r]-b[j][l-1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
10 10 10 
3 10 1 
2 8 1 
1 10 1 
2 7 1 
2 9 1 
2 9 1 
2 6 1 
2 6 1 
3 10 1 
1 9 1 
5 9 2 6 
6 7 4 6 
3 8 4 6 
7 8 4 9 
4 6 2 6 
0 2 4 6 
1 5 5 9 
3 8 4 7 
2 8 4 8 
2 7 2 10
*/
