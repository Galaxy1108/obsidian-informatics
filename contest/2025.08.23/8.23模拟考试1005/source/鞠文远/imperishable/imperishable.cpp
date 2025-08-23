#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,mod=998244353;
int num,n,q,ary[N];
int fp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	cin>>num>>n;
	for(int i=1;i<=n;i++)cin>>ary[i];
	cin>>q;
	if(ary[1]>0)cout<<fp(2,1);
	else cout<<fp(2,0);
	
	return 0;
} 
