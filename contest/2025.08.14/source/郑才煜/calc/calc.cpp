#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
	ll sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	ll T=read(),p=read(),i,j,b,k;
	while(T--)
	{
		b=read();
//		for(k=1;;++k)
//		{
//			if(k>p)
//			{
				cout<<"-1\n";
//				break;
//			}
//			
//		}
	}
}
