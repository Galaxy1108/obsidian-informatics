#include<bits/stdc++.h>
#define W while
#define fu(i,a,b) for (int i=a; i<=b; i++)

constexpr int n=12;
constexpr int mod=79;

inline int read () {
	int a=0; char c=getchar();
	W (!isdigit(c))
		c=getchar();
	W (isdigit(c))
		a=(a<<3)+(a<<1)+(c^48),
		c=getchar();
	return a;
}



signed main () {
//freopen(".in", "r", stdin);
freopen("maze.in", "w", stdout);

	std::cout<<12<<" "<<12<<" "<<12<<" "<<11<<'\n';
	fu (i, 1, n) {
		fu (j, 1, n) {
			if (i*j*77/52%5==0&&i+j<20)
				std::cout<<1;
			else
				std::cout<<0;
			std::cout<<" ";
		}
		putchar(10);
	}	

	return 0;
}
/*

*/

