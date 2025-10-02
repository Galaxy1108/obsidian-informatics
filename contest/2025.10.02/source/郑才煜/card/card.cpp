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
const int N=1e6+3;
int a[N];
bool book[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(),m=read(),q=read(),i,j,op,ji=0,ou=0,x,y;
	for(i=1;i<=n;++i)
	{
		op=read();
		if(op&1) ++ji;
		else ++ou;
	}
	for(i=1;i<=m;++i)
	{
		j=read();
		a[j]=read()%2;
		if(a[j]&1) --ji;
		else --ou;
		book[j]=true;
	}
	while(q--)
	{
		int ans=0;
		op=read();
		if(op==1)
		{
			j=read();
			if(book[j])
			{
				if(a[j]&1) ++ji;
				else ++ou;
				book[j]=false;
			}
		}
		if(op==2)
		{
			j=read();
			if(book[j])
			{
				if(a[j]&1) ++ji;
				else ++ou;
			}
			a[j]=read()%2;
			if(a[j]&1) --ji;
			else --ou;
			book[j]=true;
		}
		x=ji;
		y=ou;
		for(i=1;i<=n;++i)
		{
			if(book[i]) continue;
			if(book[i+1])
			{
				if(a[i-1]!=a[i+1]) a[i]=0;
				else
				{
					if(a[i-1]==1)
					{
						if(x)
						{
							--x;
							a[i]=1;
						}
						else
						{
							a[i]=0;
							--y;
						}
					}
					else
					{
						if(y)
						{
							a[i]=0;
							--y;
						}
						else
						{
							a[i]=1;
							--x;
						}
					}
				}
			}
//			else
//			{
//				if(a[i-1])
//				{
//					if(x)
//					{
//						a[i]=1;
//						--x;
//					}
//					else a[i]=0,--y;
//				}
//				else
//				{
//					if(y) a[i]=0,--y;
//					else a[i]=1,--x;
//				}
//			}
		}
		for(i=1;i<n;++i) if(a[i]!=a[i+1]) ++ans;
		cout<<ans<<'\n';
	}
}
