#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,k,i,j,h,l,f[110][110][110][11],ans;
int v[110][3],sum[110][3],col[4][110][110];
void gmax(int &a,int b)
{
	if(a<b) a=b;
	return;
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=Qread();m=Qread();k=Qread();
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		v[i][j]=Qread();
		sum[i][j]=sum[i-1][j]+v[i][j];
	}
	memset(f,-7,sizeof(f));
	f[1][0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		col[1][i][i]=v[i][1];
		for(j=i-1;j>=1;j--)
			col[1][i][j]=max(col[1][i][j+1],sum[i][1]-sum[j-1][1]);
	}
	if(m==2)
	{
		for(i=1;i<=n;i++)
		{
			col[2][i][i]=v[i][2];
			for(j=i-1;j>=1;j--)
				col[2][i][j]=max(col[2][i][j+1],sum[i][2]-sum[j-1][2]);
		}
		for(i=1;i<=n;i++)
		{
			col[3][i][i]=v[i][1]+v[i][2];
			for(j=i-1;j>=1;j--)
				col[3][i][j]=max(col[3][i][j+1],sum[i][1]-sum[j-1][1]+sum[i][2]-sum[j-1][2]);
		}
	}
	ans=-11415419;
	if(m==1)
	{
		for(i=1;i<=n;i++)
		for(j=0;j<=i;j++)
		for(l=0;l<=i&&l<=k;l++)
		{
			if(i!=j) gmax(f[i+1][i][0][l+1],f[i][j][0][l]+col[1][i][j+1]);
			gmax(f[i+1][j][0][l],f[i][j][0][l]);
		}
		for(i=0;i<=n;i++)
			ans=max(ans,f[n+1][i][0][k]);
	}
	else
	{
		for(i=1;i<=n;i++)
		for(j=0;j<=i;j++)
		for(h=0;h<=i;h++)
		for(l=0;l<=i&&l<=k;l++)
		{
			if(i!=j) gmax(f[i+1][i][h][l+1],f[i][j][h][l]+col[1][i][j+1]);
			if(i!=h) gmax(f[i+1][j][i][l+1],f[i][j][h][l]+col[2][i][h+1]);
			if(i!=max(j,h)) gmax(f[i+1][i][i][l+1],f[i][j][h][l]+col[3][i][max(j,h)+1]);
			gmax(f[i+1][j][h][l],f[i][j][h][l]);
		}
		for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			ans=max(ans,f[n+1][i][j][k]);
	}
	cout<<ans<<endl;
	return 0;
}
