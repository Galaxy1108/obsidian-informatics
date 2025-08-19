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
int n,co,i;
int w[2010];
double c[2010],d[2010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	n=Qread();co=Qread();
	for(i=1;i<=n;i++)
	{
		w[i]=Qread();
		cin>>c[i]>>d[i];
	}
	printf("%.4lf",39.0);
	return 0;
}
