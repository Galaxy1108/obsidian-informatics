#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
inline ll read()
{
	ll sum=0;
	char c=getchar();
	while(c>'9'&&c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ll T=read(),S,k;
	while(T--)
	{
		S=read();
		k=read();
		if(S&1)
		{
			if(2*k>S) printf("-1\n");
			else printf("%lld\n",2*k);
		}
		else printf("-1\n");
	}
}
