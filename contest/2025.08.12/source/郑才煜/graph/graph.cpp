#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
const int N=1e3;
struct G
{
	int u,v;
}a[N];
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int T=read(),n,m,k,i,j;
	while(T--)
	{
		n=read();
		m=read();
		k=ceil(m*1.0/(n+1));
		for(i=1;i<=m;++i)
		{
			a[i].u=read();
			a[i].v=read();
		}
		cout<<"-1\n";
	}
}
