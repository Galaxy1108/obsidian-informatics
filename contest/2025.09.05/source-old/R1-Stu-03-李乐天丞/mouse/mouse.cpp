#include <bits/stdc++.h>
using namespace std;
const int N=1010;
double f[N][N][2];
int n,m;
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=m;i++) f[0][i][1]=1.0;
	for(int i=1;i<=n;i++) f[i][0][0]=f[i][0][1]=1.0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		double x=i*1.0,y=j*1.0;
		f[i][j][0]=x/(x+y)+y/(x+y)*(1.0-f[i][j-1][1]);
		if(j>1) f[i][j][1]=x/(x+y)+y/(x+y)*((y-1)/(x+y-1)*(1-f[i][j-2][0])+x/(x+y-1)*(1-f[i-1][j-1][0]));
		else f[i][j][1]=x/(x+y)+y/(x+y)*x/(x+y-1)*(1-f[i-1][j-1][0]);
	}
	printf("%.9lf",f[n][m][0]);
	return 0;
}
