#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][55],f[55][55][505][2];
int main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			cin>>a[i][j];
	memset(f,-0x3f3f3f3f,sizeof f);
	f[1][1][1][1]=a[1][1];
	f[1][1][0][0]=0;
	for(int i=1;i<=n;i++)
		f[i][0][0][0]=0; 
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			f[1][i][j][0]=max(f[1][i-1][j][1],f[1][i-1][j][0]);
			f[1][i][j+1][1]=f[1][i][j][0]+a[1][i];
		}
		int sum=a[1][i];
		for(int j=1;j<i;j++){
			int x=j+1,y=i-j;
			sum+=a[x][y];
			for(int k=1;k+j+1<=m;k++)
				f[x][y][k+j+1][1]=f[x-1][y][k][1]+sum;
			for(int k=0;k<=m;k++)
				for(int l=0;l<=j;l++){
					if(l+k>m)
						break;
					f[x][y][l+k][0]=max(max(f[x][y-1][k][0],f[x][y-1][k][1])+max(f[x-1][y+1][l][0],f[x-1][y+1][l][1]),f[x][y][l+k][0]); 
				}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			maxn=max(maxn,max(f[i][j][m][1],f[i][j][m][0]));
	cout<<maxn;
	return 0;
}

