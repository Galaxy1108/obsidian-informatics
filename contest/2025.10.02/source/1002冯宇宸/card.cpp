#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int n,m,q,i,j;
int a[N],c[2];
bool vis[N];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	n=read();m=read();q=read();
	for(i=1;i<=n;i++)
	{
		a[i]=read();
		++c[a[i]%2];
	}
	for(i=1;i<=m;i++)
	{
		int p,b;
		p=read();b=read();
		--c[b%2];
		vis[p]=1;
	}
	while(q--)
	{
		int op;
		op=read();
		if(op==1)
		{
			int x;
			x=read();
			--m;
			printf("%d\n",m-1);
		}
		else
		{
			int x,y;
			x=read();y=read();
			++m;
			printf("%d\n",m-1);
		}
	}
	return 0;
}
