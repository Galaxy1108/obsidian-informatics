#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
int n,k;
const int mx=2e5+100;
int a[mx];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int f[210][210][210],ans[210][210];
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	n=fread();
	k=fread();
	for(int i=1;i<=n-1;i++)
	{
		int x=fread(),y=fread();
	}
	for(int i=1;i<=n;i++) a[i]=fread();
	for(int i=1;i<=n;i++) ans[i][i]=a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		ans[i][j]=gcd(ans[i][j-1],a[j]);
//		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		f[i][j][0]=ans[i][j];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int g=i;g<=n;g++)
			{
				for(int kk=j;kk<g;kk++)
				{
					f[j][g][i]=max(f[j][g][i],f[j][kk][i-1]+f[kk+1][g][1]);
					f[j][g][i]=max(f[j][g][i],f[j][kk][1]+f[kk+1][g][i-1]);
				}
			}
		}
	}
	cout<<f[1][n][k];
	return 0;
}

