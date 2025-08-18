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
int n,i,j,k,l,num[4][120],f[120][11][11][11],ans;
char ch;
void gmin(int &a,int b)
{
	if(a>b) a=b;
	return;
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	n=Qread();
	for(i=1;i<=n;i++)
	{
		cin>>ch;
		num[0][i]=num[0][i-1];
		num[1][i]=num[1][i-1];
		num[2][i]=num[2][i-1];
		num[ch-'A'][i]++;
	}
	for(i=n+1;i<=n+10;i++)
	{
		num[0][i]=num[0][i-1];
		num[1][i]=num[1][i-1];
		num[2][i]=num[2][i-1];
	}
	memset(f,1,sizeof(f));
	f[10][num[0][10]][num[1][10]][num[2][10]]=0;
	for(i=10;i<=n;i++)
	for(j=0;j<=10;j++)
	for(k=0;k+j<=10;k++)
	for(l=0;l+k+j<=10;l++)
	{
		gmin(f[i+j][num[0][i+j]-num[0][i]][k+num[1][i+j]-num[1][i]][l+num[2][i+j]-num[2][i]],f[i][j][k][l]+1);
		gmin(f[i+k][j+num[0][i+k]-num[0][i]][num[1][i+k]-num[1][i]][l+num[2][i+k]-num[2][i]],f[i][j][k][l]+1);
		gmin(f[i+l][j+num[0][i+l]-num[0][i]][k+num[1][i+l]-num[1][i]][num[2][i+l]-num[2][i]],f[i][j][k][l]+1);
	}
	ans=100;
	for(i=n;i<=n+10;i++)
	for(j=0;j<=10;j++)
	for(k=0;k+j<=10;k++)
	for(l=0;l+k+j<=10;l++)
		gmin(ans,f[i][j][k][l]+(j!=0)+(k!=0)+(l!=0));
	cout<<ans<<endl;
	return 0;
}
