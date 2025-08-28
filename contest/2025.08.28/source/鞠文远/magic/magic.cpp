#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=250005,mod=998244353;
int n,q,a[N],b[N],c[N];
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	cin>>q;
	while(q--)
	{
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1)for(int i=l;i<=r;i++)a[i]=(a[i]+b[i])%mod;
		if(op==2)for(int i=l;i<=r;i++)b[i]=(b[i]+c[i])%mod;
		if(op==3)for(int i=l;i<=r;i++)c[i]=(c[i]+a[i])%mod;
		if(op==4)
		{
			int v;
			cin>>v;
			for(int i=l;i<=r;i++)a[i]=(a[i]+v)%mod;
		}
		if(op==5)
		{
			int v;
			cin>>v;
			for(int i=l;i<=r;i++)b[i]=(b[i]*v)%mod;
		}
		if(op==6)
		{
			int v;
			cin>>v;
			for(int i=l;i<=r;i++)c[i]=v%mod;
		}
		if(op==7)
		{
			int anslta=0,ansltb=0,ansltc=0;
			for(int i=l;i<=r;i++)
			{
				anslta=(anslta+a[i])%mod;
				ansltb=(ansltb+b[i])%mod;
				ansltc=(ansltc+c[i])%mod;
			}
			cout<<anslta<<" "<<ansltb<<" "<<ansltc<<"\n";
		}
	}
	
	return 0;
} 
