#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		sum=(sum<<3)+(sum<<1)+c-'0';
		c=getchar();
	}
	return sum*f;
}
struct que
{
	int t,num,ans,i;
}a[1000003];
bool cmp(que x,que y)
{
	return x.t<y.t;
}
bool cmp2(que x,que y)
{
	return x.i<y.i;
}
const int N=2e5+3;
int q[N],n,g[N];
void use1()
{
	int i=1,j=n/2+1,k=0;
	while(i<=n/2&&j<=n)
	{
		if(q[i]<q[j]) g[++k]=q[i++];
		else g[++k]=q[j++];
	}
	if(k!=n)
	{
		if(j!=n+1) while(k<n) g[++k]=q[j++];
		else while(k<n) g[++k]=q[i++];
	}
}
void use2()
{
	int i=1,j=n/2+1,k=0;
	while(i<=n/2&&j<=n)
	{
		if(g[i]<g[j]) q[++k]=g[i++];
		else q[++k]=g[j++];
	}
	if(k!=n)
	{
		if(j!=n+1) while(k<n) q[++k]=g[j++];
		else while(k<n) q[++k]=g[i++];
	}
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();
	int i,j,Q=read(),t,last=1;
	for(i=1;i<=n;++i) q[i]=read();
	for(i=1;i<=Q;++i) a[i].t=read(),a[i].num=read(),a[i].i=i;
	sort(a+1,a+Q+1,cmp);
	for(i=0;i<=a[Q].t;++i)
	{
		for(j=last;a[j].t==i;++j)
		{
			if(i&1) a[j].ans=g[a[j].num];
			else a[j].ans=q[a[j].num];
		}
		last=j;
		if(i&1) use2();
		else use1();
	}
	sort(a+1,a+Q+1,cmp2);
	for(i=1;i<=Q;++i) printf("%d\n",a[i].ans);
}
