#include<bits/stdc++.h>
using namespace std;
int n,a[105],f[105][15][15][15];
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=int(x-'A')+1;
	}
	if(n<=10){
		int f1,f2,f3;
		for(int i=1;i<=n;i++){
			if(a[i]==1)
				f1=1;
			if(a[i]==2)
				f2=1;
			if(a[i]==3)
				f3=1;
		}
		cout<<f1+f2+f3;
		return 0;
	}	
	int f1=0,f2=0,f3=0;
	for(int i=1;i<=10;i++){
		if(a[i]==1)
			f1++;
		if(a[i]==2)
			f2++;
		if(a[i]==3)
			f3++;
	}
	memset(f,0x3f3f3f3f,sizeof f);
	f[10][f1][f2][f3]=0;
	for(int i=10;i<n;i++)
		for(int j=0;j<=10;j++)
			for(int k=0;k<=10;k++){
					int l=10-k-j;
					if(l<0)
						break;
					int f1,f2,f3;
					if(j){
						f1=0;
						f2=0;
						f3=0;
						for(int m=1;m<=j&&i+m<=n;m++){
							if(a[m+i]==1)
								f1++;
							if(a[m+i]==2)
								f2++;
							if(a[m+i]==3)
								f3++; 
						}
						f[min(n,i+j)][f1][f2+k][l+f3]=min(f[min(n,i+j)][f1][f2+k][l+f3],f[i][j][k][l]+1);
					}
					if(k){
						f1=0;
						f2=0;
						f3=0;
						for(int m=1;m<=k&&i+m<=n;m++){
							if(a[m+i]==1)
								f1++;
							if(a[m+i]==2)
								f2++;
							if(a[m+i]==3)
								f3++; 
						}
						f[min(n,i+k)][f1+j][f2][l+f3]=min(f[min(n,i+k)][f1+j][f2][l+f3],f[i][j][k][l]+1);
					}
					if(l){
						f1=0;
						f2=0;
						f3=0;
						for(int m=1;m<=l&&i+m<=n;m++){
							if(a[m+i]==1)
								f1++;
							if(a[m+i]==2)
								f2++;
							if(a[m+i]==3)
								f3++; 
						}
						f[min(n,i+l)][f1+j][f2+k][f3]=min(f[min(n,i+l)][f1+j][f2+k][f3],f[i][j][k][l]+1);
					}
				}
	int minn=INT_MAX;
	for(int i=0;i<=10;i++)
		for(int j=0;j<=10;j++)
			for(int k=0;k<=10;k++){
				if(i+j+k>10)
					break;
				minn=min(minn,f[n][i][j][k]+((i)?1:0)+((j)?1:0)+((k)?1:0));
			}
	cout<<minn;
	return 0;
}
