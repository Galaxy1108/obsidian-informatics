#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,m,K;
long long a[110],b[110],suma[110],sumb[110];
long long val1[13][110][110],f[110][110][5];
long long val2[13][110][110];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	if(m==1) for(int i=1;i<=n;++i) scanf("%lld",&a[i]),b[i]=-inf;
	else for(int i=1;i<=n;++i) scanf("%lld%lld",&a[i],&b[i]);
	for(int i=0;i<=n;++i){
		for(int k=0;k<=K;++k){
			f[i][k][0]=-inf;
			f[i][k][1]=-inf;
			f[i][k][2]=-inf;
			f[i][k][3]=-inf;
			f[i][k][4]=-inf;
		}
	}
	f[0][0][0]=0;
	for(int i=1;i<=n;++i){
		for(int k=0;k<=K;++k){
			if(k>=1) f[i][k][1]=max(f[i][k][1],f[i-1][k-1][0]);
			if(k>=1) f[i][k][2]=max(f[i][k][2],f[i-1][k-1][0]);
			if(k>=1) f[i][k][3]=max(f[i][k][3],f[i-1][k-1][0]);
			if(k>=2) f[i][k][4]=max(f[i][k][4],f[i-1][k-2][0]);
			if(k>=1) f[i][k][4]=max(f[i][k][4],f[i-1][k-1][1]);
			if(k>=1) f[i][k][4]=max(f[i][k][4],f[i-1][k-1][2]);
			
			f[i][k][0]=max(f[i][k][0],f[i-1][k][0]);
			f[i][k][1]=max(f[i][k][1],f[i-1][k][1]);
			f[i][k][2]=max(f[i][k][2],f[i-1][k][2]);
			f[i][k][3]=max(f[i][k][3],f[i-1][k][3]);
			f[i][k][4]=max(f[i][k][4],f[i-1][k][4]);
			
			f[i][k][1]+=a[i];
			f[i][k][2]+=b[i];
			f[i][k][3]+=a[i]+b[i];
			f[i][k][4]+=a[i]+b[i];
			
			f[i][k][2]=max(f[i][k][2],f[i][k][4]);
			f[i][k][1]=max(f[i][k][1],f[i][k][4]);
			f[i][k][0]=max(f[i][k][0],f[i][k][1]);
			f[i][k][0]=max(f[i][k][0],f[i][k][2]);
			f[i][k][0]=max(f[i][k][0],f[i][k][3]);
			f[i][k][0]=max(f[i][k][0],f[i][k][4]);
		}
	}
	printf("%lld\n",f[n][K][0]);
	return 0;
}
