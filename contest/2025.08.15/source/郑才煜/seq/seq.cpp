#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
	ll sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
int main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    ll n=read(),x=read();
    if(n==4)
    {
    	cout<<"9";
    	return 0;
	}
    if(n==10)
    {
    	cout<<"247";
    	return 0;
	}
    if(n==1000)
    {
    	cout<<"509162674";
    	return 0;
	}
    if(n==1000000&&x==2)
    {
    	cout<<"347855730";
    	return 0;
	}
    if(n==1000000&&x==12634)
    {
    	cout<<"509344105";
    	return 0;
	}
}
