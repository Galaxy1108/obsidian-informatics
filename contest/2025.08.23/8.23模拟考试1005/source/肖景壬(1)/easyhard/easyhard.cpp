#include<bits/stdc++.h>
using namespace std;
#define int long long
int fast_pow(int x,int y,int mod)
{
	if(y==0) return 1;
	if(y==1) return x;
	int now=fast_pow(x,y>>1,mod);
	now*=now;
	now%=mod;
	if(y&1)
	{
		now*=x;
		now%=mod;
	}
	return now;
}
int n,m,p;
signed main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	cin>>n>>m>>p;
	if(2*m>=m+n) cout<<fast_pow(2,n+m,p)<<endl;
	else cout<<fast_pow(2,2*m,p)<<endl;
}
