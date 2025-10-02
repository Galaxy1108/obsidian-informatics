#include<bits/stdc++.h>
#define W while
#define Fz(x,i,j) for(int x=i;x<=j;x++)
#define pii pair<int,int>
#define il inline

using namespace std;

const int N=1e6+2;

il int read () {
	int an=0; char c=getchar();
	while (c<48 or c>57)	c=getchar();
	while (c>=48 and c<=57)
		an=(an<<3)+(an<<1)+(c-48), c=getchar();
	return an;
}
il bool cmp (pii a, pii b) {
	if (a.first==b.first)	return a.second>b.second;
	return a.first>b.first;
}

int n, y[N];
pii a[N];

signed main() {
freopen("snakes.in","r",stdin);
freopen("snakes.out","w",stdout);

	int T=read();
	n=read();
	Fz (i, 1, n)	y[i]=read();
	
	Fz (t, 1, T) {
		int an=n;
		if (t!=1) {
			int k=read(), f;
			W (k--)
				f=read(), y[f]=read();
		}
		Fz (i, 1, n)
			a[i].first=y[i], a[i].second=i;
		sort (a+1, a+1+n, cmp);
		W (an>2 and a[1].first-a[an].first>a[2].first)
			a[1].first-=a[an--].first;
		if (a[1].first-a[an].first==a[2].first)
			if (a[1].second>a[2].second)	an--;
		if (an==2)	an=1;
		printf ("%d", an);
		putchar ('\n');
	}

    return 0;
}
/*
2 
3 
11 14 14  
3 //
1 5 2 6 3 25
*/
