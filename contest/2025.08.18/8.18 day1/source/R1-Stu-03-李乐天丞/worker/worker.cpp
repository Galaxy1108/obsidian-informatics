#include <bits/stdc++.h>
using namespace std;
int f[11][11][11][110];
int a[110];
int ans=101,n,cnt;
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		while(c<'A'||c>'C') c=getchar();
		if(c=='A') a[i]=0;
		else if(c=='B') a[i]=1;
		else if(c=='C') a[i]=2;
	}
	for(int i=0;i<=10;i++)
	for(int j=0;j<=10;j++)
	for(int k=0;k<=10;k++)
	for(int m=0;m<=n;m++)
	f[i][j][k][m]=101;
	int x[3];
	x[0]=x[1]=x[2]=0;
	for(int i=1;i<=min(n,10);i++) x[a[i]]++;
	f[x[0]][x[1]][x[2]][min(10,n)]=0;
	for(int i=0;i<=10;i++)
	for(int j=0;j<=10;j++)
	for(int k=0;k<=10;k++)
	for(int m=0;m<=n;m++)
	{
		x[0]=x[1]=x[2]=0;
		for(int t=m;t<=min(m+i,n);t++) x[a[t]]++;
		if(j+x[1]<=10&&k+x[2]<=10)f[x[0]][j+x[1]][k+x[2]][min(m+x[0]+x[1]+x[2],n)]=min(f[x[0]][j+x[1]][k+x[2]][min(m+x[0]+x[1]+x[2],n)],f[i][j][k][m]+1);
		x[0]=x[1]=x[2]=0;
		for(int t=m;t<=min(m+j,n);t++) x[a[t]]++;
		if(i+x[0]<=10&&k+x[2]<=10) f[i+x[0]][x[1]][k+x[2]][min(m+x[0]+x[1]+x[2],n)]=min(f[i+x[0]][x[1]][k+x[2]][min(m+x[0]+x[1]+x[2],n)],f[i][j][k][m]+1);
		x[0]=x[1]=x[2]=0;
		for(int t=m;t<=min(m+k,n);t++) x[a[t]]++;
		if(j+x[1]<=10&&i+x[0]<=10) f[i+x[0]][j+x[1]][x[2]][min(m+x[0]+x[1]+x[2],n)]=min(f[i+x[0]][j+x[1]][x[2]][min(m+x[0]+x[1]+x[2],n)],f[i][j][k][m]+1);
	}
	for(int i=0;i<=10;i++)
	for(int j=0;j<=10;j++)
	for(int k=0;k<=10;k++)
	{
		if(i) f[i][j][k][n]++;
		if(j) f[i][j][k][n]++;
		if(k) f[i][j][k][n]++;
		ans=min(ans,f[i][j][k][n]);
	}
	cout<<ans;
	return 0;
}
/*
11
A
B
C
A
B
C
A
B
C
A
B
*/
