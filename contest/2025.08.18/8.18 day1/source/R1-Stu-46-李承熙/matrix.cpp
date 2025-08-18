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
int n,m,k,a[3][110],ans,an=-1e9,ll,rr,zl,xa,bo;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=qread();m=qread();k=qread();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[j][i]=qread();
		}
	}
	for(int i=1;i<=k;i++)
	{
		an=-1e5;bo=0;
		for(int j=1;j<=n;j++)
		{
			xa=0;
			for(int l=j;l<=n;l++)
			{
				xa+=a[1][l];
				if(xa>an)an=xa,ll=j,rr=l;
			}
		}
		if(an<=0)
		{
			if(zl)zl--;
			else a[1][rr]=-1e5;
		}
		else
		{
			for(int j=ll;j<=rr;j++)
			{
				a[1][j]*=-1;
				if(a[0][j])bo=1;
				a[0][j]^=1;
			}
		}
		ans+=an;
		bo?zl-=rr-ll:zl+=rr-ll;
	} 
	cout<<ans;
	return 0;
}
