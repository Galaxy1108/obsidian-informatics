#include<bits/stdc++.h>
#define int long long
#define W while
#define fu(i,a,b) for (int i=a; i<=b; i++)
#define max(a,b) ((a)>(b)?(a):(b))

inline int read () {
	int a=0; char c=getchar();
	W (!isdigit(c))
		c=getchar();
	W (isdigit(c))
		a=(a<<3)+(a<<1)+(c^48),
		c=getchar();
	return a;
}
inline int gcd (int a, int b) {
	int t;
	W (b) 
		t=a%b, a=b, b=t;
	return a;
}

int deep, an[5];
bool fl;

inline void dfs (int a, int b, int x) {
	if (x>deep)	return ;
	int e=gcd(a, b);
	a/=e, b/=e;
	
	if (a==1&&an[x-1]<b) {
		fl=true,
		an[x]=b;
		return ;
	}
	int n=(deep-x+1)*b/a-1;
	fu (i, max(b/(a+1), an[x-1]+1), n) {
		an[x]=i;
		dfs (a*i-b, b*i, x+1);
		if (fl)
			return ;
	}
} 

signed main () {
freopen("math.in", "r", stdin);
freopen("math.out", "w", stdout);

	int a=read(), b=read();
	if (!a) {
		std::cout<<0;
		return 0;
	}
	int e=gcd(a, b);
	a/=e, b/=e;
	W (true) {
		deep++;
		dfs (a, b, 1);
		if (fl) {
			std::cout<<deep<<'\n';
			fu (i, 1, deep)
				std::cout<<an[i]<<" ";
			return 0;
		}
	}
	
	return 0;
}
/*

*/

