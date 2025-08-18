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
int n,m,i,j,k;
int v[10010];
long long f[2][110][110],ans;
void gmin(long long &a,long long b)
{
	if(a>b||a==0) a=b;
	return;
}
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	n=Qread();m=Qread();
	for(i=1;i<=n;i++)
		v[i]=Qread();
	for(i=1;i<=n;i++)
	{
		memset(f[(i+1)&1],0,sizeof(f[(i+1)&1]));
		for(j=1;j<=m;j++)
		for(k=j+1;k<=m;k++)
		{
			gmin(f[(i+1)&1][j+1][k+1],f[i&1][j][k]);
			gmin(f[(i+1)&1][1][j+1],f[i&1][j][k]+v[i]);
		}
	}
	for(i=1;i<=m;i++)
	for(j=i+1;j<=m;j++)
		if(f[(n+1)&1][i][j]!=0)
			gmin(ans,f[(n+1)&1][i][j]);
	cout<<ans<<endl;
	return 0;
}
