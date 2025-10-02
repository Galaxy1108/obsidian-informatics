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
struct G
{
	int num,i;
}b[N];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T=read(),i,j,n,k,x;
	n=read();
	for(i=1;i<=n;++i) a[i]=read();
	if(n==3)
	{
		if(a[3]-a[1]>=a[2]) cout<<"1\n";
		else cout<<"3\n";
	}
	else
	{
		for(i=1;i<=n;++i) b[i].i=i,b[i].num=a[i];
		int p=1;
		while(1)
		{
			if(b[n].num-b[p].num<b[p+1].num)
			{
				cout<<n-p+1<<"\n";
				break;
			}
			b[n].num-=b[1].num;
			++p;
			for(i=n-1;1;--i)
			{
				if(b[i].num>b[i+1].num||b[i].num==b[i+1].num&&b[i].i>b[i+1].i) swap(b[i],b[i+1]);
				else break;
			}
		}
	}
	while(--T)
	{
		k=read();
		for(i=1;i<=k;++i)
		{
			x=read();
			a[x]=read();
		}
		if(n==3)
		{
			if(a[3]-a[1]>=a[2]) cout<<"1\n";
			else cout<<"3\n";
		}
		else
		{
			for(i=1;i<=n;++i) b[i].i=i,b[i].num=a[i];
			int p=1;
			while(1)
			{
				if(b[n].num-b[p].num<b[p+1].num)
				{
					cout<<n-p+1<<"\n";
					break;
				}
				b[n].num-=b[1].num;
				++p;
				for(i=n-1;1;--i)
				{
					if(b[i].num>b[i+1].num||b[i].num==b[i+1].num&&b[i].i>b[i+1].i) swap(b[i],b[i+1]);
					else break;
				}
			}
		}
	}
}
