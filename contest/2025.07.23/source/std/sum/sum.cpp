#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int N,M,K,D;
inline void add(int &a,int b){a+=b;if(a>=D) a-=D;}
inline void del(int &a,int b){a-=b;if(a<0) a+=D;}
inline int chk(int a){return a>=D?a-D:a;}

int pw[110][10010];

inline int qpow(int a,int p)
{
	int ret=1;
	for(;p;p>>=1,a=1ll*a*a%D)
		if(p&1) ret=1ll*ret*a%D;
	return ret;
}
int f[110][110],C[110][110];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	
	N=Qread(),M=Qread(),K=Qread(),D=Qread();
	
	for(int i=0;i<=100;i++)
	for(int j=0;j<=i;j++)
		if(j==0||i==j) C[i][j]=1;
		else C[i][j]=chk(C[i-1][j-1]+C[i-1][j]);

	for(int a=0;a<=100;a++)
	{
		pw[a][0]=1;
		for(int p=1;p<=10000;p++)
			pw[a][p]=1ll*pw[a][p-1]*a%D;
	}

	#define dbg printf("%d:\n",A);for(int i=0;i<=N;i++)for(int j=0;j<=M;j++)printf("%d%c",f[i][j]," \n"[j==M]);

	f[0][0]=1;
	for(int A=1;A<=K;A++)
	{
		int cnt=K-A+1;
		for(int i=N;~i;i--)
		for(int j=M;~j;j--)
		for(int k=1;i+k<=N;k++)
			add(f[i+k][j],1ll*f[i][j]*pw[cnt][k*j]%D*C[i+k][k]%D*pw[A][k*(M-j)]%D);
		
		// dbg

		for(int i=N;~i;i--)
		for(int j=M;~j;j--)
		for(int l=1;j+l<=M;l++)
			add(f[i][j+l],1ll*f[i][j]*pw[cnt][i*l]%D*C[j+l][l]%D*pw[A][(N-i)*l]%D);

		// dbg

		for(int i=N;~i;i--)
		for(int j=M;~j;j--)
		for(int p=1;i+p<=N;p++)
			((p&1)?del:add)(f[i+p][j],1ll*f[i][j]*pw[cnt-1][p*j]%D*C[i+p][p]%D*pw[A][p*(M-j)]%D);

		// dbg

		for(int i=N;~i;i--)
		for(int j=M;~j;j--)
		for(int q=1;j+q<=M;q++)
			((q&1)?del:add)(f[i][j+q],1ll*f[i][j]*pw[cnt-1][i*q]%D*C[j+q][q]%D*pw[A][(N-i)*q]%D);
	
		// dbg
	}
		
	printf("%d\n",f[N][M]);
	return 0;
}