#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;bool f=false;char ch=getchar();
	while(ch<'0'||ch>'9') f|=!(ch^'-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
struct Qj{
	int l,r;
}p[200010];
bool cmp(Qj A,Qj B)
{
	if(A.l!=B.l) return A.l<B.l;
	return A.r<B.r;
}
int n,m,i,j,k,a[200010];
int lef[200010],rig[200010];
long long f[200010][2],g;
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	n=Qread(),m=Qread();
	for(i=1;i<=n;i++)
		a[i]=Qread();
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++)
		p[i].l=Qread(),p[i].r=Qread();
	sort(p+1,p+m+1,cmp);
	p[0].r=-1e9-1;
	for(i=1,j=1;i<=n;i++)
	{
		for(;p[j].l<=a[i]&&j<=m;j++)
			if(p[j].r<a[i])
			{
				if(p[j].r>p[k].r) p[++k]=p[j];
				else p[k]=p[j];
			}
		lef[i]=k;
		rig[i]=k+1;
	}
	for(;j<=m;j++)
	{
		if(p[j].r>p[k].r) p[++k]=p[j];
		else p[k]=p[j];
	}
	m=k;
	if(lef[i]) f[1][1]=2*(a[1]-p[1].r),f[1][0]=a[1]-p[1].r;
	for(i=1;i<=n;i++)
	{
		if(lef[i]<rig[i-1]) f[i][0]=f[i][1]=f[i-1][0];
		else
		{
			g=min(f[i-1][0]+2*(p[lef[i]].l-a[i-1]),f[i-1][1]+(p[lef[i]].l-a[i-1]));
			f[i][0]=min(f[i-1][0]+(a[i]-p[rig[i-1]].r),g);
			f[i][1]=min(f[i-1][0]+2*(a[i]-p[rig[i-1]].r),g);
			for(j=rig[i-1];j<lef[i];j++)
			{
				g=min(f[i-1][0]+2*(p[j].l-a[i-1]),f[i-1][1]+(p[j].l-a[i-1]));
				f[i][0]=min(f[i][0],g+(a[i]-p[j+1].r));
				f[i][1]=min(f[i][1],g+2*(a[i]-p[j+1].r));
			}
		}
	}
	if(rig[n]<=m) g=min(f[n][0]+2*(p[m].l-a[n]),f[n][1]+(p[m].l-a[n]));
	else g=min(f[n][0],f[n][1]);
	printf("%lld\n",g);
	return 0;
}
