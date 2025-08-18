#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
int n;
int f[N][11][11][11];
char a[N];
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(f,0x3f,sizeof f);
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=min(n,10);i++){
		if(a[i]=='A') cnt1++;
		else if(a[i]=='B') cnt2++;
		else cnt3++;
	} 
	if(n<=10){
		cout<<(cnt1>0)+(cnt2>0)+(cnt3>0);
		return 0;
	}
	f[10][cnt1][cnt2][cnt3]=0;
	for(int i=10;i<n;i++){
		for(int j=0;j<=10;j++){
			for(int k=0;j+k<=10;k++){ 
				for(int l=0;j+k+l<=10;l++){
					if(j){
						cnt1=0,cnt2=0,cnt3=0;
						for(int x=i+1;x<=min(n,i+j);x++){
							if(a[x]=='A') cnt1++;
							else if(a[x]=='B') cnt2++;
							else cnt3++;
						}
						f[min(n,i+j)][cnt1][k+cnt2][l+cnt3]=min(f[min(n,i+j)][cnt1][k+cnt2][l+cnt3],f[i][j][k][l]+1);
					}
					if(k){
						cnt1=0,cnt2=0,cnt3=0;
						for(int x=i+1;x<=min(n,i+k);x++){
							if(a[x]=='A') cnt1++;
							else if(a[x]=='B') cnt2++;
							else cnt3++;
						}
						f[min(n,i+k)][cnt1+j][cnt2][l+cnt3]=min(f[min(n,i+k)][cnt1+j][cnt2][l+cnt3],f[i][j][k][l]+1);
					}
					if(l){
						cnt1=0,cnt2=0,cnt3=0;
						for(int x=i+1;x<=min(n,i+l);x++){
							if(a[x]=='A') cnt1++;
							else if(a[x]=='B') cnt2++;
							else cnt3++;
						}
						f[min(n,i+l)][j+cnt1][k+cnt2][cnt3]=min(f[min(n,i+l)][j+cnt1][k+cnt2][cnt3],f[i][j][k][l]+1);
					}
				}
			}
		}
	}
	int ans=1e9;
	for(int i=0;i<=10;i++){
		for(int j=0;i+j<=10;j++){
			for(int l=0;i+j+l<=10;l++){
				ans=min(ans,f[n][i][j][l]+(i>0)+(j>0)+(l>0));
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
