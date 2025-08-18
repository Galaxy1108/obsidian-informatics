#include <bits/stdc++.h>
using namespace std;
int n,m,r,a[1101][3],s[1101][3],f[1001][11][11]={};
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>r;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			s[i][1]=s[i-1][1]+a[i][1];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=r;j++){
				f[i][1][j]=f[i-1][1][j];
				f[1][1][1]=a[1][1];
				for(int k=0;k<=i;k++){
					f[i][1][j]=max(f[i][1][j],f[k][1][j-1]+s[i][1]-s[k][1]);
					//if(i==n) cout<<f[i][1][j]<<" "<<k<<" "<<f[k][1][j-1]+s[i][1]-s[k][1]<<" "<<f[k][1][j-1]<<endl;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,f[i][1][r]);
			//cout<<f[i][1][r]<<endl;
		}
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				s[i][j]=s[i-1][j]+a[i][j];
			}
		}
		f[1][1][1]=a[1][1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=r;k++){
					f[i][j][k]=f[i-1][j][k];
					f[1][1][1]=a[1][1];
					if(j==2) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]);
					for(int t=0;t<=i;t++){
						f[i][j][k]=max(f[i][j][k],f[t][j][k-1]+s[i][1]-s[t-1][1]);
						if(j==2){
							f[i][j][k]=max(f[i][j][k],max(f[t][j][k-1]+s[i][2]-s[t-1][2],f[t][j-1][k-1]+s[i][2]-s[t-1][2]));
							f[i][j][k]=max(f[i][j][k],f[t][j][k-1]+s[i][1]-s[t-1][1]+s[i][2]-s[t-1][2]);
						}
					}
					//cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl; 
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans=max(ans,f[i][j][r]);
			}
		}
		cout<<ans<<endl;
	}
		
	return 0;
}
/*
3 2 2 
1 -3 
2 3 
-2 3 
*/
