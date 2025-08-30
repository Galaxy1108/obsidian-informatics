#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
int gcd(int a,int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
const int N=503;
struct Tr
{
	int u,v;
}a[N];
int b[N],c[N],bu[N];
bool cmp(int x,int y)
{
	return b[x]>b[y];
}
bool book[N];
int ss,n;
int fi(int x)
{
	int i,maxx=0,next=0;
	for(i=1;i<=n-1;++i)
	{
		if(book[i]) continue;
		if(a[i].u==x)
		{
			if(bu[a[i].v]==2)
			{
				maxx=b[a[i].v];
				next=a[i].v;
				ss=i;
			}
			break;
		}
		if(a[i].v==x)
		{
			if(bu[a[i].u]==2)
			{
				maxx=b[a[i].u];
				next=a[i].u;
				ss=i;
			}
			break;
		}
	}
	return maxx*1000+next;
}
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	n=read();
	int k=read(),i,j;
	long long ans=0;
	for(i=1;i<=n-1;++i)
	{
		a[i].u=read();
		a[i].v=read();
		++bu[a[i].u];
		++bu[a[i].v];
	}
	for(i=1;i<=n;++i) b[i]=read();
	int z=0;
	for(i=1;i<=n;++i) if(bu[i]==1) c[++z]=i;
	while(k--)
	{
		sort(c+1,c+z+1,cmp);
		int p=1,maxx=0,next=0;
		maxx=fi(c[1]);
		if(maxx==0)
		{
			maxx=b[c[2]];
			next=c[2];
		}
		else
		{
			next=maxx%1000;
			maxx/=1000;
		}
		for(i=2;i<=z;++i)
		{
			if(b[c[i]]!=b[c[1]]) break;
			int t=fi(c[i]);
			if(t/1000>maxx)
			{
				maxx=t/1000;
				next=t%1000;
				p=i;
			}
		}
		ans+=b[c[p]];
		--bu[c[p]];
		c[p]=next;
		if(next==c[2]) c[1]=c[z--];
		book[ss]=true;
		--bu[next];
	}
	int s=-1;
	for(i=1;i<=n;++i)
	{
		if(bu[i])
		{
			if(s!=-1) s=gcd(c[i],s);
			else s=c[i];
		}
	}
	cout<<ans+s;
}
