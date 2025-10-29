#include<bits/stdc++.h>
using namespace std;
const int mm=2e5+5;
const int inf=0x7fffffff;
int n,m;
int sum,ans,cnt;
int d[mm];
struct My1{
	int a,c;
} A[mm];
struct my{
	int l,r;
	bool b;
} x[mm],X[mm];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool cmp(My1 x,My1 y)
{
	if(x.c==y.c) return x.a>y.a;
	return x.c<y.c;
}
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) d[i]=read();
	for(int i=1;i<=m;i++) x[i].l=read(),x[i].r=read(),x[i].b=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(d[j]>=x[i].l&&d[j]<=x[i].r) x[i].b=0;
			if(x[i].b==0) break;
		}
	}
	for(int i=1;i<=m;i++) 
	{
		if(x[i].b==1) X[++cnt]=x[i];
		A[i].a=inf;
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=n;j++)
		{
			A[i].a=min(min(abs(X[i].l-d[j]),abs(X[i].r-d[j])),A[i].a);
			if(A[i].a==abs(X[i].l-d[j])||A[i].a==abs(X[i].r-d[j])) A[i].c=j;
		}
	}
	sort(A+1,A+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(A[i].c==A[i+1].c) sum=max(A[i].a,sum);
		else ans+=sum,sum=0;
	}
	if(sum==0) ans+=A[cnt].a;
	else ans+=sum; 
	cout<<ans<<endl;
	return 0;
}
