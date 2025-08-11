#include <bits/stdc++.h>
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
long long mod=1e9+7;
long long n,k;
long long a[2500005];
long long q[2500005],s[2500005];
long long f[2500005],ans=0;
int main(){
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	n=Qread(),k=Qread();
	for(int i=1;i<=n;i++){
		a[i]=Qread();
	}
	long long head=1,tail=0;
	for(int i=1;i<=n;i++){
		while(head<=tail&&a[q[tail]]<a[i]) tail--;
		q[++tail]=i;
		while(head<=tail&&q[head]<i-k) head++; 
		f[i]=min(f[i-1]+a[i],f[i-k]+a[q[head]]);
	} 
	s[0]=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]*23;
		s[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		ans+=f[i]*s[n-i];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
} 
/*
8 3 
3 2 9 8 7 11 3 4
*/
