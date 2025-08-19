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
int n,m,i,j,k,l;
int a[60][60],sum[60][60];
int f[60][60][510],tot;
void get_min(int &a,int b)
{
	if(a>b) a=b;
	return;
}
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	n=Qread();m=Qread();
	m=n*(n+1)/2-m;
	for(i=n;i>=1;i--)
	for(j=1;j<=i;j++)
		tot+=(a[i-j+1][j]=Qread());
	for(i=1;i<=n;i++)
	for(j=1;j<=n-i+1;j++)
		sum[i][j]=a[i][j]+sum[i-1][j];
	memset(f,1,sizeof(f));
	f[0][n+1][0]=0;
	for(i=1;i<=n;i++)
	for(j=0;j<=n-i+1;j++)
	for(k=j*i;k<=m;k++)
	for(l=j;l<=n-i+2;l++)
		get_min(f[i][j][k],f[i-1][l][k-j]+sum[j][i]);
	cout<<tot-min(f[n][1][m],f[n][0][m]);
	return 0;
}
/*
4 5
2 2 3 4
8 2 7
2 3
4
*/
