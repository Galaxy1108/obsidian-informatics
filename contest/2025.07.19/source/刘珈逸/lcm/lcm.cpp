#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353,phi=402653184,mx=N-5;
int qpow(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*a*ans%p;
		b>>=1;a=1ll*a*a%p;
	}return ans;
}
int prime[N],tot;
bool isp[N];
int s[N],smul[N],invmul[N];
int n,k;
void get_k(){
	char c=getchar();k=0;
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9')k=(10ll*k+c-'0')%phi,c=getchar();
}
int query(int p){
	int l=0,mul=1;
	while(1){
		s[l]=n/mul-n/mul/p;
		if(1ll*mul*p>n)break;
		l++;mul*=p;
	}for(int i=1;i<=l;i++)s[i]+=s[i-1];
	int ans=1ll*l*qpow(s[l],k,mod-1)%(mod-1);
	for(int i=0;i<l;i++)ans=(ans-qpow(s[i],k,mod-1))%(mod-1);
	return ans+mod-1;
}
int solve(){
	scanf("%d",&n);get_k();
	int ans=1;
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		if(smul[l-1]==smul[r])continue;
		ans=1ll*ans*qpow(1ll*smul[r]*invmul[l-1]%mod,query(l),mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	for(int i=2;i<=mx;i++){
		if(!isp[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=mx;j++){
			isp[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=0;i<=mx;i++)smul[i]=1;
	for(int i=1;i<=tot;i++)smul[prime[i]]=prime[i];
	for(int i=1;i<=mx;i++)smul[i]=1ll*smul[i-1]*smul[i]%mod;
	for(int i=0;i<=mx;i++)invmul[i]=qpow(smul[i],mod-2,mod);
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}
