#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,mod=998244353;
int n,l[N],r[N];
int ans[N],puv[N];
int m;
int inv[N],p[N][N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=a*ans%mod;
		b>>=1;a=a*a%mod;
	}return ans;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	for(int i=2;i<=n;i++)scanf("%lld%lld",l+i,r+i);
	for(int i=1;i<=n;i++)inv[i]=qpow(i,mod-2);
	for(int t=2;t<=n;t++){
		p[t][t]=1;p[t][t-1]=-1;
		for(int i=t;i>=2;i--){
			p[t][i]=(p[t][i]+p[t][i+1])%mod;
			p[t][r[i]]=(p[t][r[i]]+p[t][i]*inv[r[i]-l[i]+1])%mod;
			p[t][l[i]-1]=(p[t][l[i]-1]-p[t][i]*inv[r[i]-l[i]+1])%mod;
		}
	}
	scanf("%lld",&m);
	while(m--){
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		if(u>v)swap(u,v);
		for(int i=u;i>=2;i--){
			ans[i]=(ans[i]+p[u][i]*w)%mod;
		}
		for(int i=v;i>=2;i--){
			ans[i]=(ans[i]+p[v][i]*w)%mod;
		}
		for(int t=u;t>=2;t--){
			puv[t]+=p[u][t]*p[v][t]%mod*w%mod;puv[t]%=mod;
		}
	}
	for(int t=n;t>=2;t--){
		for(int i=t-1;i>=2;i--)puv[i]=(puv[i]-p[t][i]*p[t][i]%mod*puv[t])%mod;
	}
	for(int i=2;i<=n;i++)puv[i-1]-=puv[i];
	for(int i=n;i>=2;i--){
		puv[i]=(puv[i]+puv[i+1])%mod;
		puv[r[i]]=(puv[r[i]]+puv[i]*inv[r[i]-l[i]+1])%mod;
		puv[l[i]-1]=(puv[l[i]-1]-puv[i]*inv[r[i]-l[i]+1])%mod;
		ans[i]=(ans[i]-2*puv[i])%mod;
	}
	for(int i=2;i<=n;i++){
		printf("%lld",(ans[i]+mod)%mod);
		if(i^n)putchar(' ');
	}
	return 0;
}
/*
�����ÿ������(u,v)�ϵĸ��� 
������u<v
������ÿ���ڵ�ǡΪu��v��һ�����ȵĸ���
P(u)+P(v)-P(uv)*2 
P(u)��P(v)������������dp�����
������xΪu,v��lca�ĸ���
�� u Ϊ v ������ �������׼���
�� u ��Ϊ v ������,P(uv)=P(u)*P(v) 
(��Ҫ�ü�ȥuΪv���ȵĸ���) 
*/
