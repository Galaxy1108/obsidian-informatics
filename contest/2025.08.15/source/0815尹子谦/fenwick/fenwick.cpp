#include<bits/stdc++.h>
#define int unsigned long long
using namespace std ;
const int N=1e7+10;
int tr[N];
int lowbit(int x)
{
	return x&-x;
}
int n,Q,op,num1,num2;
void add(int x,int k)
{ 
	int i=0;
	for(;x<=n;x+=lowbit(x)) 
	{ 
		tr[x]+=(++i)*k;
	}
}
int ask(int x)
{
	int sum=0;
	while(x)
	{
		sum+=tr[x];
		x-=lowbit(x);
	}
	return sum;
}
int s1,s2;
int my_rand()
{
    int s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query(int &op,int &num1,int &num2)
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}
signed main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
	cin>>n>>Q>>s1>>s2;
	int ans=0;
	for(int i=1;i<=Q;i++)
	{
		int opt,l,r;
		get_query(opt,l,r);
		if(opt==1) add(l,r);
		else
		{
			int sum=ask(r)-ask(l-1);
			ans^=(i*sum);
		}
	}
	cout<<ans;
	return 0;
}
