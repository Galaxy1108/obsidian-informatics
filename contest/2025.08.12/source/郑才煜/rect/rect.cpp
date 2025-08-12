#include<bits/stdc++.h>
using namespace std;
const int N=5e2+3;
bool a[N][N];
int b[N][N],c[N][N],n,m;
void vinus1(int x,int y,int z)
{
	if(y>m) return;
	if(a[x][y]&&!b[x][y])
	{
		b[x][y]=z;
		vinus1(x,y+1,z);
	}
}
void vinus2(int x,int y,int z)
{
	if(x>n) return;
	if(a[x][y]&&!c[x][y])
	{
		c[x][y]=z;
		vinus2(x+1,y,z);
	}
}
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	int i,j,s=1,t=1;
	cin>>n>>m;
	char f;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			cin>>f;
			if(f=='C') a[i][j]=true;
		}
	}
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) if(a[i][j]&&b[i][j]==0) vinus1(i,j,s++);
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) if(a[i][j]&&c[i][j]==0) vinus2(i,j,t++);
	if(s<t)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j) printf("%d ",b[i][j]);
			printf("\n");
		}
	}
	else
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j) printf("%d ",c[i][j]);
			printf("\n");
		}
	}
}
