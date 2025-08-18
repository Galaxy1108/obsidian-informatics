#include<bits/stdc++.h>
#define Max(a,b) (a=max(a,b))
using namespace std;
int n,m,K;
int sum1[110],sum2[110];
int f[11][110][110];
int misum1[110][110];
int misum2[110][110];
int misum[110][110];
void solve2(){
	for(int i=1;i<=n;i++){
		int num1,num2;
		cin>>num1>>num2;
		sum1[i]=sum1[i-1]+num1;
		sum2[i]=sum2[i-1]+num2;
	}
	for(int j=0;j<=n;j++){
		int mi1,mi2,mi;
		mi1=mi2=mi=INT_MAX;
		for(int k=j;k<=n;k++){
			mi1=min(mi1,sum1[k]);
			mi2=min(mi2,sum2[k]);
			mi=min(mi,sum1[k]+sum2[k]);
			misum1[j][k]=mi1;
			misum2[j][k]=mi2;
			misum[j][k]=mi;
		}
	}
	memset(f,0xcf,sizeof(f));
	int ans=f[0][0][0];
	f[0][0][0]=0;
	for(int i=0;i<K;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(f[i][j][k]==-808464433) continue;
				for(int t=j+1;t<=n;t++){
					Max(f[i+1][t][k],f[i][j][k]+sum1[t]-misum1[j][t-1]);
				}
				for(int t=k+1;t<=n;t++){
					Max(f[i+1][j][t],f[i][j][k]+sum2[t]-misum2[k][t-1]);
				}
				int low=max(j,k);
				for(int t=low+1;t<=n;t++){
					Max(f[i+1][t][t],f[i][j][k]+sum1[t]+sum2[t]-misum[low][t-1]);
				}
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			ans=max(ans,f[K][j][k]);
		}
	}
	cout<<ans;	
}
int f2[11][110];
void solve1(){
	for(int i=1;i<=n;i++){
		int num1;
		cin>>num1;
		sum1[i]=sum1[i-1]+num1;
	}
	memset(f2,0xcf,sizeof(f2));
	int ans=f2[0][0];
	f2[0][0]=0;
	for(int j=0;j<=n;j++){
		int mi1=INT_MAX;
		for(int k=j;k<=n;k++){
			mi1=min(mi1,sum1[k]);
			misum1[j][k]=mi1;
		}
	}
	for(int i=0;i<=K;i++){
		for(int j=0;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				Max(f2[i+1][k],f2[i][j]+sum1[k]-misum1[j][k-1]);
			}
		}
	}
	for(int j=1;j<=n;j++){
		ans=max(ans,f2[K][j]);
	}
	cout<<ans; 
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>K;
	if(m==2) solve2();
	else solve1();

	return 0;
}

