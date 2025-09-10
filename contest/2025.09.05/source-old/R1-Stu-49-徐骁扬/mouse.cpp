#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int w,b;
double f[1010][1010][2];
double solve(int n,int m,int jum)
{
//	printf("%d %d %d\n",n,m,jum);
	if(f[n][m][jum]!=0) return f[n][m][jum];
	if(m==0) return f[n][m][jum]=1;
	if(jum)
	{
		if(n==0) return f[n][m][1]=1.0;
		if(n==1&&m==1) return f[n][m][1]=1.0;
		if(m==1) return f[n][m][1]=1.0*n/(n+m);
		return f[n][m][1]=1.0*n/(n+m)+1.0*m/(n+m)*(1-1.0*n/(n+m-1)*solve(n-1,m-1,0)-1.0*(m-1)/(n+m-1)*solve(n,m-2,0));
	}
	else
	{
		if(n==0) return f[n][m][0]=0;
		return f[n][m][0]=1.0*n/(n+m)+1.0*m/(n+m)*(1-solve(n,m-1,1));
	}
}
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	w=Qread();b=Qread();
	printf("%.9lf\n",solve(w,b,0));
	return 0;
}
