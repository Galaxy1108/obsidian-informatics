#include<bits/stdc++.h>
#define pc(x) putchar(x)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=ch=='-'?-1:f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<0){x=-x;pc('-');}
	if(x>9)write(x/10);
	pc(x%10+48);
}
int n,mod,a[11],ans,cnt;
int q[4000005];
int c[101];
int lowbit(int x){return x&-x;}
void add(int x){for(int i=x;i<=n;i+=lowbit(i))c[i]++;}
int qry(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=c[i];
	return res;
}
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=read(),mod=read();cnt=0;
	if(n>10)
	{
		puts("114514");
		return 0;
	}int mx=1;
	for(int i=1;i<=n;++i)mx*=i;
	for(int i=1;i<=n;++i)a[i]=i;
	while(1)
	{
		memset(c,0,sizeof c);++cnt;int res=0;
		for(int i=n;i>=1;--i)
			res+=qry(a[i]-1),add(a[i]);
		q[cnt]=res;if(cnt==mx)break;
		next_permutation(a+1,a+n+1);
	}memset(c,0,sizeof c);int zero=0;
	for(int i=mx;i>=1;--i)
	{
		if(!q[i]){zero++;continue;}
		ans+=qry(q[i]-1)+zero;
		if(ans>=mod)ans-=mod;
		add(q[i]);
	}write(ans),pc('\n');
	return 0;
}
