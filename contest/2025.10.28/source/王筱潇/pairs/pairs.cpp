#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp1[200][40000],flag[200][40000],dp2[200],mod,n,tmp;
int main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	scanf("%lld%lld",&n,&mod);
	dp1[0][0]=1;
	for(int i=0;i<=n*(n-1)/2;i++) flag[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n*(n-1)/2;j++){
			if(j-i>=0) dp1[i][j]=(flag[i-1][j]-flag[i-1][j-i]+mod)%mod;
			else dp1[i][j]=flag[i-1][j];
			if(j) (flag[i][j]=flag[i][j-1]+dp1[i][j])%=mod;
			else flag[i][j]=dp1[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int z=j+1;z<=i;z++){
				for(int g=0;g<=i*(i-1)/2;g++){
					tmp=g-(z-j)-1;
					if(tmp<0) continue;
					(dp2[i]+=dp1[i-1][g]*flag[i-1][tmp]%mod)%=mod;
				}
			}
		}
	}
	for(int i=2;i<=n;i++) dp2[i]=(dp2[i]+dp2[i-1]*i)%mod;
	printf("%lld",dp2[n]);
	return 0;
}
