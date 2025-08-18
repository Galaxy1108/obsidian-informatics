#include<bits/stdc++.h>//WHY IS THE PROBLEM SO HARD?! I don't have two *brush*es. XD

using namespace std;

int n,m;
int a[100001];
int f[102][102];
int minn[10001][101];

int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	cin>>n>>m;
	int total=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		total+=a[i];
	}
	if(m==2){ //Maybe as a gift. 
		cout<<total<<endl;
		return 0;
	}
	else{
		//Why is the problem so hard? Life is hard.
		memset(f,0x3f3f3f3f,sizeof(f));
		memset(minn,0x3f3f3f3f,sizeof(minn));
		f[0][0]=0;
		for(int j=m;j>1;j--){
			for(int k=j-1;k>=1;k--){
				f[j][k]=a[j]+a[k];
				minn[m][j]=min(minn[m][j],f[j][k]);
			}
		}
		for(int i=m+1;i<=n;i++){
			for(int j=2;j<m;j++){
				for(int k=1;k<j;k++) f[j][k]=f[j+1][k+1];
			}
			for(int j=m-1;j>=1;j--){
				f[m][j]=minn[i-1][j+1]+a[i];
				minn[i][m]=min(minn[i][m],f[m][j]);
			}
			for(int j=m-1;j>1;j--){
				for(int k=j-1;k>=1;k--){
					f[j][k]=min(f[j][k],minn[i-1][k+1]+a[i-m+j]);
					minn[i][j]=min(minn[i][j],f[j][k]);
//					cout<<i<<" "<<j<<" "<<k<<" "<<f[j][k]<<endl;
				}
			}
		}
		int minans=999999999;
		for(int j=m;j>1;j--){
			for(int k=j-1;k>=1;k--) minans=min(minans,f[j][k]);
		}
		cout<<minans<<endl;
	}
	return 0;
}
