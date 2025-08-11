#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,k,t,T1,A,B,C,D,E,F,G;
int b[210];
long long f[210][41000],ans;
struct Node{
	int a,b,c,d,e,f;
}v[10010];
vector<int> V[110];
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	f[0][0]=1;
	for(int T=0;T<5040;++T){
		if(T) ++A;
		if(A>1) A=0,++B;
		if(B>2) B=0,++C;
		if(C>3) C=0,++D;
		if(D>4) D=0,++E;
		if(E>5) E=0,++F;
		v[T]=(Node){A,B,C,D,E,F};
		V[A+B+C+D+E+F].push_back(T);
	}
	for(int i=1;i<=n;++i){
		for(int S=0;S<(1<<k);++S){
			int siz=__builtin_popcount(S);
			if(b[i]-siz<0) continue;
			for(auto T:V[b[i]-siz]){
				A=v[T].a,B=v[T].b,C=v[T].c,D=v[T].d,E=v[T].e,F=v[T].f;
				G=b[i-1]-A-B-C-D-E-F;
				T1=T+G*5040;
				if(G<0||G>k) continue;
				if(siz+A+B+C+D+E+F!=b[i]) continue;
				G=F+(S&1);
				F=E+(S>>1&1);
				E=D+(S>>2&1);
				D=C+(S>>3&1);
				C=B+(S>>4&1);
				B=A+(S>>5&1);
				A=(S>>6&1);
				t=A+B*2+C*6+D*24+E*120+F*720+G*5040;
				f[i][t]=(f[i][t]+f[i-1][T1])%mod;
			}
		}
	}
	for(int S=0;S<40900;++S) ans=(ans+f[n][S])%mod;
	printf("%lld\n",ans);
	return 0;
}
