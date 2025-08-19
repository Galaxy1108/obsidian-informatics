#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int n,i,f=1,top=1,que[1000010];
long long x[1000010],p[1000010],c[1000010];
long long pre[1000010],xpre[1000010],g[1000010];
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	n=Qread();
	for(i=1;i<=n;i++)
	{
		x[i]=Qread();p[i]=Qread();c[i]=Qread();
		pre[i]=pre[i-1]+p[i];
		xpre[i]=xpre[i-1]+p[i]*x[i];
	}
	for(i=1;i<=n;i++)
	{
		while(f<top&&x[i]*(pre[que[f+1]]-pre[que[f]])>(g[que[f+1]]-g[que[f]])) f++;
		g[i]=g[que[f]]-x[i]*pre[que[f]]+c[i]+x[i]*pre[i];
		while(f<top&&(g[i]-g[que[top-1]])*(pre[que[top]]-pre[que[top-1]])<(g[que[top]]-g[que[top-1]])*(pre[i]-pre[que[top-1]])) top--;
		que[++top]=i;
	}
	cout<<g[n]-xpre[n];
	return 0;
}
