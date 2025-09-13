#include<bits/stdc++.h>
#define int long long
#define N 2000000
#define Mod 998244353
using namespace std;
int n,t,k,sum[N+5];
inline int read(){
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
//	int x;
//	cin>>x;
//	return x;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
int fpow(int x,int y){
	if(!y)return 1;
	if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
	return fpow(x*x%Mod,y>>1);
}
int C(int x,int y){
	return sum[y]*fpow(sum[x]*sum[y-x]%Mod,Mod-2)%Mod;
}
main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	k=read(),t=read(),sum[0]=1;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]*i%Mod;
	while(t--){
		n=read();
		if(k>n/2){
			print(n),putchar(' ');
			print(1),putchar('\n');
			continue;
		}
//		if(k==1){
//			for(int i=1;i)
//		}
		print(0),putchar(' ');
		print(0),putchar('\n');
	}
	return 0;
}
