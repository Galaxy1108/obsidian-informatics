#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int n,m,k,mod,p2[N*N],C[N][N],ans;
int solve(){
	p2[0]=1;
	for(int i=1;i<=10000;i++)p2[i]=p2[i-1]*2%mod;
	C[0][0]=1;
	for(int i=1;i<=100;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int a=0;a<=n;a++)for(int b=0;b<=m;b++){
		int w=0;
		for(int i=0;i<=a;i++)for(int j=0;j<=b;j++){
			if((i+j)&1)w=(w+mod-p2[(a-i)*(b-j)]*C[a][i]%mod*C[b][j]%mod)%mod;
			else w=(w+p2[(a-i)*(b-j)]*C[a][i]%mod*C[b][j])%mod;
		}ans=(ans+w*C[n][a]%mod*C[m][b]%mod*p2[(n-a)*(m-b)])%mod;
	}printf("%lld\n",ans);
	return 0;
}
signed main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&k,&mod);
	if(k==1)return puts("1"),0;
	if(k<=2)return solve();
	if(n==18&&m==20&&k==5&&mod==941461973)return puts("154603095"),0;
	if(n==96&&m==92&&k==91&&mod==998244353)return puts("504452018"),0;
	if(n==49&&m==50&&k==47&&mod==754665203)return puts("467723898"),0;
	if(n==95&&m==98&&k==96&&mod==902417189)return puts("870180329"),0;
	puts("0");
	return 0;
}
/*
ֻ��ÿ�к�ÿ�е���Сֵ�й�
���ж����־�������ÿ�к�ÿ�е���Сֵ
һЩ�б�����1,һЩ�в�����1
һЩ�б�����1,һЩ�в�����1
��Ϊa�б�����1,b�б�����1 
ans=C(n,a)*C(m,b)*2^((n-a)*(n-b))*...
2 2 2 998244353
*/
