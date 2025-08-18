#include<bits/stdc++.h> //Why is the problem so hard? Life is hard.

using namespace std;

const int inf=0x3f3f3f3f;

int f[101][71][71][71];

int n;
char kt[101];

int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	cin>>n;
	int tot1=0,tot2=0,tot3=0;
	for(int i=1;i<=n;i++){
		cin>>kt[i];
		if(kt[i]=='A') tot1++;
		else if(kt[i]=='B') tot2++;
		else tot3++;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=tot1;j++){
			for(int k=0;k<=tot2;k++){
				for(int l=0;l<=tot3;l++) f[i][j][k][l]=inf;
			}
		}
	}
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=min(n,10);i++){
		if(kt[i]=='A') cnt1++;
		else if(kt[i]=='B') cnt2++;
		else cnt3++;
	}
	f[min(n,10)][cnt1][cnt2][cnt3]=0;
	for(int i=1;i<=n;i++){
		for(int j=tot1;j>=0;j--){
			for(int k=tot2;k>=0;k--){
				for(int l=tot3;l>=0;l--){
					if(f[i][j][k][l]==inf) continue;
					if(j+k+l>10) continue;
					int t1=0,t2=0,t3=0;
//					cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[i][j][k][l]<<endl;
					for(int s=i+1;s<=min(i+j,n);s++){
						if(kt[s]=='A') t1++;
						else if(kt[s]=='B') t2++;
						else t3++;
					}
					f[min(i+j,n)][t1][k+t2][l+t3]=min(f[min(i+j,n)][t1][k+t2][l+t3],f[i][j][k][l]+1);
					t1=0,t2=0,t3=0;
					for(int s=i+1;s<=min(i+k,n);s++){
						if(kt[s]=='A') t1++;
						else if(kt[s]=='B') t2++;
						else t3++;
					}
					f[min(i+k,n)][j+t1][t2][l+t3]=min(f[min(i+j,n)][j+t1][t2][l+t3],f[i][j][k][l]+1);
					t1=0,t2=0,t3=0;
					for(int s=i+1;s<=min(i+l,n);s++){
						if(kt[s]=='A') t1++;
						else if(kt[s]=='B') t2++;
						else t3++;
					}
					f[min(i+l,n)][j+t1][k+t2][t3]=min(f[min(i+j,n)][j+t1][k+t2][t3],f[i][j][k][l]+1);
				}
			}
		}
	}
	cout<<f[n][0][0][0]<<endl;
	return 0;
}
