#include<bits/stdc++.h>
#define int __int128
#define N 1000000
#define Mod 998244353
using namespace std;
int t,n,k,ans,a[N+5];
int fpow(int x,int y){
	if(!y)return 1;
	if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
	return fpow(x*x%Mod,y>>1);
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
int dfs(int x){
	int sum=1;
	if(x>k){
		for(int i=1;i<=k;i++)sum=sum*a[i]/__gcd(sum,a[i]);
//		cout<<sum<<" fuwhufhsd\n";
		return sum;
	}
	for(int i=1;i<=n;i++)a[x]=i,sum=sum*dfs(x+1)%Mod;
	return sum;
}
main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout); 
	t=read();
	while(t--){
		n=read(),k=read();
		print(dfs(1)),putchar('\n');
	}
	return 0;
}
