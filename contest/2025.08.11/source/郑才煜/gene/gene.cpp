#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'&&c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
const int N=1e6+3;
struct number
{
	int s,l,r;
}a[N];
int b[N],x[N];
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	int n=read(),l=read(),r=read(),i,j,ans=N;
	for(i=1;i<=n;++i)
	{
		a[i].s=read();
		if(b[a[i].s])
		{
			a[i].l=x[a[i].s];
			a[a[i].l].r=i;
		}
		++b[a[i].s];
		x[a[i].s]=i;
	}
	for(i=l-1;i;--i)
	{
		if(a[i].l) continue;
		int t=n;
		if(a[i].r) t=a[i].r-1;
		for(j=r+1;j<=t;++j)
		{
			if(a[j].r) continue;
			if(a[j].l<i) ans=min(ans,j-i+1);
		}
	}
	if(ans==N) cout<<"-1";
	else cout<<ans;
}
