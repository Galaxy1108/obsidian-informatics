#include <bits/stdc++.h>
using namespace std;
const int maxn=2.5e6+100;
const int mod=1e9+7;
int read()
{
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0'; 
		c=getchar();
	}
	return f*k;
}
long long ksm(int x){
	if(x==0) return 1;
	long long sum=ksm(x/2);
	if(x%2==0) return (sum%mod*sum%mod)%mod;
	else return (23*sum%mod*sum%mod)%mod;
}
int n,k;
int a[maxn],f[maxn];
int q[maxn],h=0,t=-1;
long long ans;
int main()
{
//	freopen("beetle2.in","r",stdin);
//	freopen("beetle.out","w",stdin);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		if(i-q[h]>=k) h++;
		while(t>=h&&a[q[t]]<=a[i]) t--;
		q[++t]=i;
		if(i>k) {
			f[i]=(a[q[h]]+f[i-k])%mod;
			long long m=ksm(n-i);
			ans=(ans+(f[i]%mod)*(m%mod)%mod)%mod;	
		}
		else{
			f[i]=a[q[h]]%mod;
			long long m=ksm(n-i);
			ans=(ans+(f[i]%mod)*(m%mod)%mod)%mod;
		} 
	//	cout<<f[i]<<endl;
	}
	cout<<ans; 
	return 0;
}
