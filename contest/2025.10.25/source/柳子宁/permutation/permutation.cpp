#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,x,cnt;
int f[610][310][310];
int A[1010],a[1010],del[1010],tag[1010],suf[1010];
long long ans;
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=2*n;++i) scanf("%d",&A[i]);
	for(int i=1;i<=2*n;i+=2){
		if(A[i]!=-1&&A[i+1]!=-1){
			del[A[i]]=del[A[i+1]]=1;
		}
		else a[++cnt]=A[i],a[++cnt]=A[i+1];
	}
	n=cnt/2;
	for(int i=1;i<=cnt;++i){
		if(a[i]==-1) continue;
		int Ai=0;
		for(int j=1;j<=a[i];++j){
			if(!del[j]) ++Ai;
		}
		a[i]=Ai;
	}
	for(int i=1;i<=2*n;++i){
		if(a[i]!=-1) tag[a[i]]=1;
	}
	for(int i=2*n;i>=1;--i) suf[i]=suf[i+1]+tag[i];

	f[0][0][0]=1;
	for(int i=0;i<2*n;++i){
		for(int j=0;j<=n;++j){
			for(int k=0;k<=n;++k){
				if(!f[i][j][k]) continue;
				long long a=suf[i+1]-k;
				long long b=(2*n-i-suf[i+1]-j-a);
				long long c=(i-j-k);
				if(a<0||b<0||c<0||(b&1)||(c&1)) continue;
				b>>=1,c>>=1;
				if(tag[i+1]){
					if(k) f[i+1][j][k-1]=(1ll*k*f[i][j][k]+f[i+1][j][k-1])%mod;
					if(a) f[i+1][j+1][k]=(f[i][j][k]+f[i+1][j+1][k])%mod;
				}
				else{
					if(j) f[i+1][j-1][k]=(f[i][j][k]+f[i+1][j-1][k])%mod;
					if(a) f[i+1][j][k+1]=(f[i][j][k]+f[i+1][j][k+1])%mod;
					if(b) f[i+1][j+1][k]=(b*f[i][j][k]+f[i+1][j+1][k])%mod;
				}
			}
		}
	}

	int i=2*n;
	for(int j=0;j<=n;++j){
		for(int k=0;k<=n;++k){
			long long a=suf[i+1]-k;
			long long b=(2*n-i-suf[i+1]-j-a);
			long long c=(i-j-k);
			if(a<0||b<0||c<0||(b&1)||(c&1)) continue;
			b>>=1,c>>=1;
			ans=(ans+f[i][j][k])%mod;
		}
	}
	
	printf("%lld\n",ans);

	return 0;
}
