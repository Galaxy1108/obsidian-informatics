#include<bits/stdc++.h>
using namespace std; 
const int N=1e6+5;
#define int long long

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())if(c=='-')f=1;
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10|48);
}

int T,n,P,f[N],g[N],h[N],F[N],iv[N];

int power(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=ans*x%P;
		x=x*x%P;
		y>>=1;
	}
	return ans;
}

void work(){
	n=read();P=read();
	int ans=1;
	f[1]=h[1]=1;
	for(int i=1;i<=n;++i)F[i]=1;
	for(int i=2;i<=n;++i){
		f[i]=(f[i-1]*2+f[i-2])%P;
		F[i]=F[i]*f[i]%P;
		iv[i]=power(F[i],P-2);
		for(int j=i+i;j<=n;j+=i){
			F[j]=F[j]*iv[i]%P;
		}
		h[i]=h[i-1]*F[i]%P;
		ans=(ans+i*h[i])%P;
//		cout<<" i:"<<i<<" f:"<<f[i]<<" F:"<<F[i]<<" g:"<<g[i]%P<<" h:"<<h[i]<<endl;
	}
	print(ans);putchar('\n');
}

signed main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	T=read();
	while(T--){
		work();
	}
	return 0;
//	n=read();
//	init();
//	f[1]=1;g[1]=1;h[1]=1;
//	for(int i=2;i<=n;++i){
//		F[i]=f[i]=f[i-1]*2+f[i-2];
//		g[i]=lcm(g[i-1],f[i]);
//		for(int j=2;j<i;++j){
//			if(i%j==0){
//				F[i]=F[i]*power(F[j],P-2)%P;	
//			}
//		}
//		h[i]=h[i-1]*F[i]%P;
////		cout<<" i:"<<i<<" f:"<<f[i]<<" F:"<<F[i]<<" g:"<<g[i]%P<<" h:"<<h[i]<<endl;
//	}

	return 0;
}


















