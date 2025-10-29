#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,x,mo=998244353;

inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48); ch=getchar();}
	return x;
}

inline int ksm(int x,int n)
{
	if(n==1)
		return x;
	else
	{
		int i=n>>1;
		int k=ksm(x,i)%mo;
		int ans=(k*k)%mo;
		if(i*2!=n)
			ans=(ans*x)%mo;
		return ans;
	}
}

signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout); 
	n=read(),x=read();
	if(n>x)
		cout<<ksm(x,n);
}
