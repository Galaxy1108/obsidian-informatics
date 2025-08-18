#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001],f[10001][101],ans=1e9;
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	cin>>n>>m;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int s=1;s<=m;s++){
		f[s][1]=a[1];
		for(int i=2;i<=n-s+1;i++){
			if(i!=n-s+1){
				for(int j=max(1,i-m+1);j<=i;j++){
					f[i][s]=min(f[i][s],f[j][s]+a[i]);
				}
			}
			else{
				for(int j=max(1,n-m+1);j<=i;j++){
					f[i][s]=min(f[i][s],f[j][s]+a[i]);
				}
			}
		}
	}
	
	for(int s=1;s<=m;s++){
		ans=min(ans,f[n][s]);
	}
	cout<<ans<<endl;
	return 0;
} 
