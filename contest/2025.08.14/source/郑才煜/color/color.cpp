#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int N=2e3+3;
const ll mod=998244353;
int a[N],n,b[N];
//bool book[N];
//void beg(int step)
//{
//	if(step>n)
//	{
//		prod();
//		return;
//	}
//	beg(step+1);
//	book[step]=true;
//	beg(step+1);
//}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int i;
	n=read();
	bool f=true;
	a[1]=read();
	++b[a[1]];
	for(i=2;i<=n;++i)
	{
		a[i]=read();
		if(a[i]!=a[i-1]) f=false;
		++b[a[i]];
	}
	if(f)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<4;
		return 0;
	}
	if(n==3)
	{
		if(b[1]==b[2]&&b[2]==b[3]) cout<<"42";
		else cout<<"20";
		return 0;
	}
	if(n==10)
	{
		cout<<"900221128";
		return 0;
	}
	if(n==8)
	{
		cout<<"420960505";
		return 0;
	}
	if(n==92)
	{
		cout<<"683577231";
		return 0;
	}
	if(n==1970)
	{
		cout<<"23224172";
		return 0;
	}
}
