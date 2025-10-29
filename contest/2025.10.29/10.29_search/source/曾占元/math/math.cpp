#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans[10005];
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int lcm(int x,int y)
{
	int z=gcd(x,y);
	return x/z*y;
}
void huajian(int &x,int &y)
{
	int z=gcd(x,y);
	x/=z;
	y/=z;
	return ;
}
void jia(int &a,int &b,int c,int d)
{
	if(b==0)
	{
		a=c;
		b=d;
		return ;
	}
	if(b!=d)
	{
		int e=lcm(b,d);
		int f=e/b*a;
		int g=e/d*c;
		a=f;
		b=e;
		c=g;
	}
	a+=c;
	return ;
}
bool dayu(int a,int b,int c,int d)
{
	if(b!=d)
	{
		int e=lcm(b,d);
		a=e/b*a;
		c=e/d*c;
		return a>c;
	}
	else
		return a>c;
}
signed main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==0)
	{
		cout<<0;
		return 0;
	}
	huajian(a,b);
	int cnt=0;
	for(int i=2;;i++)
	{
		if(a==1)
		{
			ans[++cnt]=b;
			break;
		}
		else
		{
			if(dayu(a,b,1,i))
			{
				jia(a,b,-1,i);
				huajian(a,b);
				ans[++cnt]=i;
			}
		}
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<" ";
	return 0;
}
