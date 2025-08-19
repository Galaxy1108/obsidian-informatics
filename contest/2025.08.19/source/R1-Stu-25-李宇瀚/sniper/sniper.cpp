#include<bits/stdc++.h>

using namespace std;

struct ene{
	int lx,u,t;
}a[100001];

const long long inf=999999999999999;

long long f[25010][24][3];
int mapn[25010][24];
int n;
int v[40]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};

int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	cin>>n;
	int maxu=-1,maxt=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i].lx>>a[i].u>>a[i].t;
		mapn[a[i].t][a[i].u]=a[i].lx;
		maxu=max(maxu,a[i].u),maxt=max(maxt,a[i].t);
	}
	for(int i=0;i<=maxt+2;i++){
		for(int j=0;j<=maxu;j++) f[i][j][0]=f[i][j][1]=f[i][j][2]=-inf;
	} 
	for(int i=0;i<=maxu;i++){
		f[0][i][0]=v[mapn[0][i]];
		f[0][i][1]=0;
		f[0][i][2]=0;
	}
	for(int i=1;i<=maxt;i++){
		for(int j=0;j<=maxu;j++){
			for(int k=max(0,j-2);k<=min(maxu,j+2);k++){
				if(mapn[i][j]) f[i][j][0]=max(f[i][j][0],max(f[i-1][k][1],f[i-1][k][2])+v[mapn[i][j]]);
//				if(k==j) f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+v[mapn[i][j]]);
				f[i][j][2]=max(f[i][j][2],max(f[i-1][k][2],f[i-1][k][1]));
			}
			f[i][j][1]=f[i-1][j][0];
//			cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<" "<<f[i][j][2]<<endl;
//			cout<<f[4][3][0]<<endl;
			if(mapn[i][j]==15){
				for(int k=0;k<=maxu;k++){
					if(k==j) f[i][k][1]=f[i][k][2]=-inf;
					else f[i][k][0]=f[i][k][1]=f[i][k][2]=-inf;
				}
				break;
			}
		}
	}
	long long maxans=-1;
	for(int i=0;i<=maxu;i++){
		maxans=max(maxans,f[maxt][i][0]);
		maxans=max(maxans,f[maxt][i][1]);
		maxans=max(maxans,f[maxt][i][2]);
	}
	cout<<maxans<<endl;
	return 0;
}
