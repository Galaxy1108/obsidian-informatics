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
int n,m,p,ans,i,j,k;
int f[2][3010][2];
int main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	n=Qread(),m=Qread(),p=Qread();
	for(i=0;i<n;i++)
		f[0][i][1]=1,f[0][i][0]=p-1;
	f[0][n][1]=1;
	for(i=1;i<=m;i++)
	{
		memset(f[i&1],0,sizeof(f[i&1])); 
		for(j=0;j<=n;j++)
		{
			if(j!=0) (f[i&1][j][1]+=(f[(i-1)&1][j][1]+f[(i-1)&1][j-1][1])%p)%=p;
			if(j!=n) (f[i&1][j][1]+=(f[(i-1)&1][j][1]+f[(i-1)&1][j+1][1])%p)%=p;
			if(j==n) continue;
			if(j!=0) (f[i&1][j][0]+=(f[(i-1)&1][j][0]+f[(i-1)&1][j-1][0])%p)%=p;
			if(j!=n-1) (f[i&1][j][0]+=(f[(i-1)&1][j][0]+f[(i-1)&1][j+1][0])%p)%=p;
		}
	}
	for(j=0;j<=n;j++)
	{
		(ans+=f[m&1][j][1])%=p;
		if(j!=n) (ans+=f[m&1][j][0])%=p;
	}
	printf("%d\n",ans);
	return 0;
}