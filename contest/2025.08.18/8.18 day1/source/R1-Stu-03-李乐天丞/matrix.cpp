#include <bits/stdc++.h>
using namespace std;
inline int Qread()
{
	int sum=0,flag=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') flag=-1;c=getchar();}
	while(c>='0'&&c<='9') {sum=(sum<<3)+(sum<<1)+(c^48);c=getchar();}
	return sum*flag;
}
int n,t,k;
int m[110][2];
int f[110][11][2];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=Qread();t=Qread();k=Qread();
	if(t==1)
	{
		for(int i=1;i<=n;i++) m[i][0]=Qread();
		for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
		for(int k=0;k<=1;k++) f[i][j][k]=-3276700;
		f[1][0][0]=0;f[1][1][1]=m[1][0];
		for(int i=1;i<n;i++)
		for(int j=0;j<=k;j++)
		{
			if(j+1<=k) 
			{
				f[i+1][j+1][1]=max(f[i+1][j+1][1],f[i][j][1]+m[i+1][0]);
				f[i+1][j+1][1]=max(f[i+1][j+1][1],f[i][j][0]+m[i+1][0]);
			}
			f[i+1][j][0]=max(f[i+1][j][0],f[i][j][1]);
			f[i+1][j][0]=max(f[i+1][j][0],f[i][j][0]);
			f[i+1][j][1]=max(f[i+1][j][1],f[i][j][1]+m[i+1][0]);
		}
		cout<<max(f[n][k][0],f[n][k][1]);
	}
	return 0;
}
