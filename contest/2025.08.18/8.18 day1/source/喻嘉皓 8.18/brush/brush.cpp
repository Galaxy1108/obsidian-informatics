#include<bits/stdc++.h>
#define Min(a,b) (a=min(a,b))
using namespace std;
int n,m;
int w[10010];
int f[10010][110];
int minn[10010][110];
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
//	for(int i=1;i<=n;i++){
//		int mi=INT_MAX;
//		for(int j=i;j<=i+m-1;j++){
//			mi=min(mi,w[j]);
//			minn[i][j-i+1]=mi;
//		}
//	}
//	memset(f,0x3f,sizeof(f));
//	int ans=f[0][0];
//	f[0][0]=0;
//	for(int i=1;i<=m;i++){
//		for(int j=i;j>=1;j--){
//			f[i][j]=w[j]+minn[1][j-1];
//		} 
//	}
//	for(int i=m+1;i<=n;i++){
//		for(int j=i;j>max(i-m,0);j--){
//			int l=i-m+1,r=j-1;
//			Min(f[i][j],f[l-1][l-1]+minn[l][r-l+1]+w[j]);
//		}
//	}
//	for(int j=n;j>n-m;j--){
//		Min(ans,f[n][j]);
//	}
	memset(f,0x3f,sizeof(f));
	int ans=f[0][0];	
	for(int i=2;i<=m;i++){
		for(int j=1;j<i;j++){
			f[i][i-j]=w[i]+w[j];
		}
	}
	for(int i=m+1;i<=n;i++){
		for(int j=1;j<m;j++){
			for(int k=1;j+k<=m;k++){
				Min(f[i][j],f[i-j][k]+w[i]);
			}
		}
	}
	for(int i=n-m+2;i<=n;i++){
		for(int j=1;i-j>=n-m+1;j++){
			Min(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}

