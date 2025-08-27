#include <bits/stdc++.h>
using namespace std;
long long Qread()
{
	long long x=0;bool f=false;char ch=getchar();
	while(ch<'0'||ch>'9') f!=!(ch^'-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
long long T,n,s,t,x,y;
int main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	T=Qread();
	while(T--)
	{
		n=Qread(),s=Qread(),t=Qread(),x=Qread(),y=Qread();
		while(n--)
		{
			if(s<t) s+=y;
			else s-=x;
		}
		printf("%lld\n",s);
	}
	return 0;
}