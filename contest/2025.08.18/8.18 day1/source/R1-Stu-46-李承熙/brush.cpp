#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	int a=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int n,m;
long long a[10010],f[10010][110],ans=1e13;
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++)a[i]=qread();
	memset(f,127,sizeof(f));
	memset(f[0],0,sizeof(f[0]));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m&&j<=i;j++)
		{
			for(int k=1;k<=m-j;k++)
			{
				f[i][j]=min(f[i][j],f[i-j][k]+a[i]);
			}
			if(i>n-m&&i-j>n-m)ans=min(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}
