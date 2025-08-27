/*
我花了三个小时写T1
你告诉我式子假了 

我【数据删除】你【数据删除】 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,s,tc,t,x,y,ans,dds;
void sol1()
{
	if(s<=t)
	{
		int tmp1=t-s;
		int tmp2=(tmp1+y-1)/y;
		if(n<=tmp2)
		{
			ans=s+y*n;
		}
		n-=tmp2;
		s=s+tmp2*y;
	}
	else
	{
		int tmp1=s-t;
		int tmp2=tmp1/x;
		if(n<=tmp2)
		{
			ans=s-x*n;
			return;
		}
		n-=tmp2;
		s=s+tmp2*x;
	}
	if(n%2==1)
	{
		if(s>=t) ans=s-x;
		else ans=s+x;
	}
	else
	{
		ans=s;
	}
	return;
}
/*bool sol2()//jump
{
	if(s<=t)
	{
		int tmp1=t-s;
		int tmp2=(tmp1+y-1)/y;
		if(n<=tmp2)
		{
			ans=s+y*n;
			return 0;
		}
		n-=tmp2;
		s=s+tmp2*y;
		dds=s-t;
		return 1;
	}
	else
	{
		int tmp1=s-t;
		int tmp2=tmp1/x;
		if(n<=tmp2)
		{
			ans=s-x*n;
			return 0;
		}
		n-=tmp2;
		s=s+tmp2*x;
		dds=s-t;
		return 1;
	}
	return 0;
}
int simgcd(int n,int a,int b,int c) 
{
	if(a==0)
	{
        return (b/c)*(n+1); 
    } 
    if (a>=c||b>=c)
	{
		return (n*(n+1))/2*(a/c)+(b/c)*(n+1)+simgcd(n,a%c,b%c,c);
	}
	int m=(a*n+b)/c; 
	return n*m-simgcd(m-1,c,c-b-1,a); 
}
int calc(int nn)
{
	if(nn==0) return 0;
	if(nn==1) return 2;
	int ret=1+nn;
	ret+=simgcd(nn-2,y-x,dds,x);
	ret-=simgcd(nn-2,y-x,dds,x*x);
	ret+=(nn-1)*(y/x);
	return ret;
}
void sol3()
{
	if(sol2())
	{
		return;
	}
	int l=0,r=10000,mid,finans;
	while(l<=r)
	{
		
	}
}*/
signed main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	/*cin>>tc;
	while(tc--)
	{
		cin>>n>>s>>t>>x>>y;
		if(y==x)
		{
			sol1();
			cout<<ans<<endl;
		}
		else if(y<x)
		{
			 
		}
		else
		{
			
		}
	}*/
	/*s=6;
	t=5;
	x=3;
	y=4;
	n=10;
	sol2();
	cout<<calc(3)<<" ";
	cout<<s<<" "<<t<<" "<<x<<" "<<y<<" "<<n<<endl;*/
	cin>>tc;
	while(tc--)
	{
		cin>>n>>s>>t>>x>>y;
		if(x==y)
		{
			sol1();
			cout<<ans<<endl;
			continue;
		}
		while(n--)
		{
			if(s>=t) s-=x;
			else s+=y;
		}
		cout<<s<<endl;
	}
 } 
