#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n;
long long s[101][10][10],s1[101],s2[101][10][10],r[11],a[10]={3,4,5,5,5,5,5,5,4,3},b[10][10],ans=0;
long long cnt=0,f[101];
int main(){
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	b[0][1]=0,b[0][2]=1,b[0][3]=2;
	b[1][1]=0,b[1][2]=1,b[1][3]=2,b[1][4]=3;
	b[2][1]=0,b[2][2]=1,b[2][3]=2,b[2][4]=3,b[2][5]=4;
	b[3][1]=1,b[3][2]=2,b[3][3]=3,b[3][4]=4,b[3][5]=5;
	b[4][1]=2,b[4][2]=3,b[4][3]=4,b[4][4]=5,b[4][5]=6;
	b[5][1]=3,b[5][2]=4,b[5][3]=5,b[5][4]=6,b[5][5]=7;
	b[6][1]=4,b[6][2]=5,b[6][3]=6,b[6][4]=7,b[6][5]=8;
	b[7][1]=5,b[7][2]=6,b[7][3]=7,b[7][4]=8,b[7][5]=9;
	b[8][1]=6,b[8][2]=7,b[8][3]=8,b[8][4]=9;
	b[9][1]=7,b[9][2]=8,b[9][3]=9;
	for(int i=0;i<=9;i++){
		s[0][i][i]=1;
	}
	s1[0]=1;
	for(int i=1;i<=60;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				for(int d=0;d<=9;d++){
					for(int e=1;e<=a[d];e++){
						s[i][j][k]+=s[i-1][j][d]*s[i-1][b[d][e]][k];
						s[i][j][k]%=mod;
					}
				}
			}
		}
		s1[i]=s1[i-1]*2;
	}
	cin>>n;
	if(n==1){
		cout<<10<<endl;
		return 0;
	}
	long long t=n;
	for(int i=60;i>=0&&t!=0;i--){
		if(t>=s1[i]){
			t-=s1[i];
			cnt++;
			f[cnt]=i;
		}
	}
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			s2[1][i][j]=s[f[1]][i][j];
		}
	}
	for(int i=2;i<=cnt;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				for(int d=0;d<=9;d++){
					for(int e=1;e<=a[d];e++){
						s2[i][j][k]+=s2[i-1][j][d]*s[f[i]][b[d][e]][k];
						s2[i][j][k]%=mod;
					}
				}
			}
		}
	}
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			ans+=s2[cnt][i][j];
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
