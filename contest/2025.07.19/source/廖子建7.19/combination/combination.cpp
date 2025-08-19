#include<bits/stdc++.h>
#define int long long
#define N 1000
#define Mod p
using namespace std;
int n,ux,p,m,a[N+5],csum[N+5],ans=0;
int fpow(int x,int y){
	if(!y)return 1;
	if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
	return fpow(x*x%Mod,y>>1);
}
int C(int x,int y){
	if(y<0||x<y)return 0;
	return csum[x]*fpow(csum[x-y]*csum[y]%Mod,Mod-2)%Mod;
}
int F(int x){
	int sum=0;
	for(int i=1;i<=m+1;i++)sum=(sum+a[i]*fpow(x,i-1)%Mod)%Mod;
	return sum;
}
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
} 
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
main(){
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	n=read(),ux=read(),p=read(),m=read(),csum[0]=1;
	for(int i=1;i<=N;i++)csum[i]=csum[i-1]*i%Mod;
	for(int i=1;i<=m+1;i++)a[i]=read();
	for(int i=0;i<=n;i++)ans=(ans+F(i)*fpow(ux,i)%Mod*C(n,i)%Mod)%Mod;
	print(ans);
	return 0;
}
