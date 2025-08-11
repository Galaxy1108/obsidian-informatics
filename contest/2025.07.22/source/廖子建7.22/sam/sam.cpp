#include<bits/stdc++.h>
#define int long long
#define M 10ll
#define Mod 1000000007ll
using namespace std;
struct Mar{int a[M+3][M+3]={};};
Mar operator*(Mar const &x,Mar const &y){
	Mar z;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=M;j++){
			z.a[i][j]=0;
			for(int k=1;k<=M;k++)z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%Mod)%Mod;
		}
	}
	return z;
}
int n,ans;
Mar e,k,u;
Mar fpow(Mar x,int y){
//	cout<<y<<"\n";
//	for(int i=1;i<=M;i++){
//		for(int j=1;j<=M;j++){
//			cout<<x.a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	if(!y)return e;
	if(y&1)return fpow(x*x,y>>1)*x;
	return fpow(x*x,y>>1);
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
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	for(int i=1;i<=M;i++)e.a[i][i]=1;
	for(int i=1;i<=M;i++){
		for(int j=max(i-2,1ll);j<=min(i+2,M);j++)k.a[i][j]=1;
	}
	n=read()-1;
	if(!n){
		print(10);
		return 0;
	}
	u=fpow(k,n);
//	cout<<n<<"\n";
	for(int i=2;i<=M;i++){
		for(int j=1;j<=M;j++)ans=(ans+u.a[i][j])%Mod;
//		cout<<"\n";
	}
	print(ans);
	return 0;
}
