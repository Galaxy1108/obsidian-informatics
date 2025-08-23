#include<bits/stdc++.h>
using namespace std;
int n,m,mod,ans;
int f[3010][3010];
int main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod);
	--n;
	f[0][0]=1;
	for(int i=1;i<=2*m-2;++i){
		for(int j=0;j<=i;++j){
			if(j>n+((i+1)/2)) continue;
			if(i-j>n+((i+1)/2)) continue;
			f[i][j]=f[i-1][j];
			if(j) f[i][j]+=f[i-1][j-1];
			if(f[i][j]>=mod) f[i][j]-=mod;
		}
		// for(int j=0;j<=i;++j){
		// 	printf("%d ",f[i][j]);
		// }
		// printf("\n");
	}
	for(int i=0;i<=2*m-2;++i){
		ans+=f[2*m-2][i];
		if(ans>=mod) ans-=mod;
	}
	printf("%lld\n",(4ll*ans)%mod);
	return 0;
}