#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],q,v,o;
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(register int i=1;i<=n;i++) cin>>a[i];
	while(q--)
	{
		cin>>o;
		if(o==1)
		{
			cin>>v;
			for(register int i=1;i<=n;i++) a[i]=min(a[i],v);
		}
		else if(o==2)
		{
			for(register int i=1;i<=n;i++) a[i]+=i;
		}
		else
		{
			long long ans=0;
			int l,r;
			cin>>l>>r;
			for(register int i=l;i<=r;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
} 
