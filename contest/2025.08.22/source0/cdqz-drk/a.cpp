#include <cstdio>
const int N=(int)1e7+3;
int n,m,mod,fl[N],fr[N],gl[N],gr[N],sl[N],sr[N];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int i,j,t;
	scanf("%d%d%d",&n,&m,&mod);
	for(i=1;i<=m;i++)
		fl[i]=(long long)i*(i+1)/2%mod;
	for(i=m;i>0;i--)
		fr[i]=(long long)(m-i+1)*(m-i+2)/2%mod;
	for(i=2;i<=n;i++){
		t=fl[m];
		for(j=1;j<=m;j++) sl[j]=(sl[j-1]+fl[j])%mod;
		for(j=m;j> 0;j--) sr[j]=(sr[j+1]+fr[j])%mod;
		for(j=1;j<=m;j++)
			gl[j]=((long long)(t-fr[j+1]+mod)%mod*j%mod-sl[j-1]+mod)%mod;
		for(j=m;j> 0;j--)
			gr[j]=((long long)(t-fl[j-1]+mod)%mod*(m-j+1)%mod-sr[j+1]+mod)%mod;
		for(j=1;j<=m;j++) fl[j]=(fl[j-1]+gl[j])%mod;
		for(j=m;j> 0;j--) fr[j]=(fr[j+1]+gr[j])%mod;
	}
	printf("%d",fl[m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
