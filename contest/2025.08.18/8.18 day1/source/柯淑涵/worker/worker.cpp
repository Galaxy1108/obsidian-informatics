#include <bits/stdc++.h>
using namespace std;
int n;
char a[1001];
int f[101][11][11][11],t1[101],t2[101],t3[101],s1,s2,s3,r=0;
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=100;i++){
		for(int j=0;j<=10;j++){
			for(int k=0;k<=10;k++){
				for(int s=0;s<=10;s++){
					f[i][j][k][s]=1e9;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='A') t1[i]=1;
		else if(a[i]=='B') t2[i]=1;
		else if(a[i]=='C') t3[i]=1;
	} 
	if(n<=10){
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='A') x=1;
			else if(a[i]=='B') y=1;
			else if(a[i]=='C') z=1;
		} 
		cout<<x+y+z<<endl;
	}
	int x=0,y=0,z=0;
	for(int i=1;i<=10;i++){
		if(a[i]=='A') x++;
		else if(a[i]=='B') y++;
		else if(a[i]=='C') z++;
		f[i][x][y][z]=0;	
	} 
	for(int i=10;i<=n;i++){
		for(int j=0;j<=10;j++){
			for(int k=0;k<=10;k++){
				for(int s=0;s<=10;s++){
					if(f[i][j][k][s]<1e9){
						if(j>0){
							s1=0,s2=k,s3=s,r=1;
							for(int t=i+1;t<=min(n,i+j);t++){
								s1+=t1[t],s2+=t2[t],s3+=t3[t];
								f[t][s1][s2][s3]=min(f[t][s1][s2][s3],f[i][j][k][s]+1);
							} 
						} 
						if(k>0){
							s1=j,s2=0,s3=s;
							for(int t=i+1;t<=min(n,i+k);t++){
								s1+=t1[t],s2+=t2[t],s3+=t3[t];
								f[t][s1][s2][s3]=min(f[t][s1][s2][s3],f[i][j][k][s]+1);
							} 
						} 
						if(s>0){
							s1=j,s2=k,s3=0;
							for(int t=i+1;t<=min(n,i+s);t++){
								s1+=t1[t],s2+=t2[t],s3+=t3[t];
								f[t][s1][s2][s3]=min(f[t][s1][s2][s3],f[i][j][k][s]+1);
							} 
						} 
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=10;j++){
			for(int k=0;k<=10;k++){
				for(int s=0;s<=10;s++){
					if(f[i][j][k][s]<1e9){
						int x=0;
						if(j>0) x++;
						if(k>0) x++;
						if(s>0) x++;
						f[i][j][k][s]+=x;
					}
				}
			}
		}
	}
	int ans=1e9;
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			for(int k=0;k<=10;k++){
				ans=min(f[n][i][j][k],ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
