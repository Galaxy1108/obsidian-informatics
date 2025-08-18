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
long long n,a[2][2010],ans,q[2][2010];
struct lcx
{
	long long l,r,ans;
}f[2010][2010];
int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++)a[0][i]=qread(),q[0][i]=q[0][i-1]+a[0][i];
	for(int i=1;i<=n;i++)a[1][i]=qread(),q[1][i]=q[1][i-1]+a[1][i];
	for(int l=1,r;l<=n-2;l++)
	{
		r=l+2;
		f[l][r].ans=q[1][r]-q[1][l-1]+a[0][l]+a[0][r];
		f[l][r].l=l;
		f[l][r].r=r;
		ans=max(ans,f[l][r].ans);
	}
	for(int i=4;i<=n;i++)
	{
		for(int l=1,r;l<=n-i+1;l++)
		{
			r=l+i-1;
			f[l][r].ans=f[l+1][r].ans+a[0][l]+a[1][l];
			if(q[0][f[l+1][r].l]-q[0][l]<=0)f[l][r].l=l,f[l][r].ans-=q[0][f[l+1][r].l]-q[0][l];
			else f[l][r].l=f[l+1][r].l;
			f[l][r].r=f[l+1][r].r;
			if(f[l][r-1].ans+a[0][r]+a[1][r]>f[l][r].ans)
			{
				f[l][r].ans=f[l][r-1].ans+a[0][r]+a[1][r];
				if(q[0][r-1]-q[0][f[l][r-1].r-1]<=0)f[l][r].r=r,f[l][r].ans-=q[0][r-1]-q[0][f[l][r-1].r-1];
				else f[l][r].r=f[l][r-1].r;
				f[l][r].l=f[l][r-1].l;
			}
			ans=max(ans,f[l][r].ans);
		}
	}
	cout<<ans;
	return 0;
}
