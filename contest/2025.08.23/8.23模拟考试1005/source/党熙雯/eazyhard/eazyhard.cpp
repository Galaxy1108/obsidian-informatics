#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p;
int f[6001][3001];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
signed main()
{
	freopen("eazyhard.in","r",stdin);
	freopen("eazyhard.out","w",stdout);
	n=fread(),m=fread(),p=fread();
	int ans=0;
//	for(int i=0;i<=n;i++)
//	f[0][i]=1;
	f[0][0]=1;
	f[0][n]=1;
	for(int i=1;i<=m;i++)
	{
		f[i][0]=(f[i-1][1]+f[i-1][0])%p;
		f[i][n]=(f[i-1][n]+f[i-1][n-1])%p;
//		f[i][1]=(f[i-1][0]+f[i-1][2]+f[i-1][1])%p;
//		f[i][n-1]=(f[i-1][n]+f[i-1][n-2]+f[i-1][n-1])%p;
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[i-1][j]*2+f[i-1][j-1]+f[i-1][j+1];
			f[i][j]%=p;
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=0;j<=n;j++)
//		{
//			cout<<"f["<<i<<"]["<<j<<"]:"<<f[i][j]<<' ';
//		}
//		cout<<endl;
////	}
//	if(n%2)
//	cout<<f[m][(n+1)/2];
//	else
//	cout<<f[m][(n+1)/2]+f[m][n/2];
	for(int i=0;i<=n;i++) ans=max(ans,f[m][i]),ans%=p;
//	ans-=f[m][0]*(n-1)+f[m][1]
	cout<<ans;
	return 0;
}


