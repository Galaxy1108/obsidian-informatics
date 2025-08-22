#include <bits/stdc++.h>

//#pragma GCC optimize(3)
//#pragma target("avx,avx2")

using namespace std;

//#define int long long

int P;
inline int Add(int x , int y){return x + y < P ? x + y : x + y - P;}
inline int Sub(int x , int y){return x < y ? x + P - y : x - y;}
inline int Mul(int x , int y){return 1LL * x * y % P;}

using IO_t=int;inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}inline IO_t read(){IO_t x=0;bool f=0;char ch=gc();while(!isdigit(ch)){f|=(ch=='-');ch=gc();}while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return(f?-x:x);}

int n , m;

signed main(){
	freopen("a.in" , "r" , stdin);
	freopen("a.out" , "w" , stdout);
	
	n = read() , m = read() , P = read();
	
	int f[n + 1][m + 1] , g[n + 1][m + 1] , h[n + 1][m + 1];
	int F[n + 1][m + 1] , G[n + 1][m + 1];
	memset(f , 0 , sizeof f);
	memset(g , 0 , sizeof g);
	memset(h , 0 , sizeof h);
	memset(F , 0 , sizeof F);
	memset(G , 0 , sizeof G);
	
	for(int l = 1; l <= m; ++ l){
		f[1][l] = m - l + 1;
	}
	for(int r = 1; r <= m; ++ r){
		g[1][r] = r;
	}
	for(int j = 1; j <= m; ++ j){
		h[1][j] = Mul(j , m - j + 1);
	}
	for(int j = 1; j <= m; ++ j){
		f[1][j] = Add(f[1][j] , f[1][j - 1]);
		g[1][j] = Add(g[1][j] , g[1][j - 1]);
	}
	int tot = f[1][m];
	for(int j = 1; j <= m; ++ j){
		int tmp1 = g[1][j - 1];
		int tmp2 = Sub(f[1][m] , f[1][j]);
		h[1][j] = Sub(Sub(tot , tmp1) , tmp2);
//		printf("h[%d][%d]=%d\n" , 1 , j , h[1][j]);
	}
	for(int j = 1; j <= m; ++ j){
		F[1][j] = Add(f[1][j] , F[1][j - 1]);
		G[1][j] = Add(g[1][j] , G[1][j - 1]);
	}
	
	for(int i = 2; i <= n; ++ i){//f，g用完后变为前缀和
		//F,G为前缀和的前缀和
		for(int l = 1; l <= m; ++ l){
			int tmp1 = Mul(m - l + 1 , h[i - 1][l]);
			int tmp2 = Sub(F[i - 1][m] , F[i - 1][l - 1]);
			int tmp3 = Mul(m - l + 1 , f[i - 1][l]);
			f[i][l] = Add(tmp1 , Sub(tmp2 , tmp3));
//			cout << tmp1 << " " << tmp2 << " " << tmp3 << endl;
//			printf("f[%d][%d]=%d\n" , i , l , f[i][l]);
		}
		for(int r = 1; r <= m; ++ r){
			int tmp1 = Mul(r , h[i - 1][r]);
			int tmp2 = Mul(r , g[i - 1][r - 1]);
			int tmp3 = Sub(G[i - 1][r - 1] , G[i - 1][0]);
			g[i][r] = Add(tmp1 , Sub(tmp2 , tmp3));
//			printf("g[%d][%d]=%d\n" , i , r , g[i][r]);
		}
		for(int j = 1; j <= m; ++ j){
			f[i][j] = Add(f[i][j] , f[i][j - 1]);
			g[i][j] = Add(g[i][j] , g[i][j - 1]);
		}
		int tot = f[i][m];
		for(int j = 1; j <= m; ++ j){
			int tmp1 = g[i][j - 1];
			int tmp2 = Sub(f[i][m] , f[i][j]);
			h[i][j] = Sub(Sub(tot , tmp1) , tmp2);
//			printf("h[%d][%d]=%d\n" , i , j , h[i][j]);
		}
		for(int j = 1; j <= m; ++ j){
			F[i][j] = Add(f[i][j] , F[i][j - 1]);
			G[i][j] = Add(g[i][j] , G[i][j - 1]);
		}
	}
	
//	assert(f[n][m] == g[n][m]);
	printf("%d" , g[n][m]);
	
	return 0;
}
