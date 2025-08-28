#include<bits/stdc++.h>
#define ls p*2
#define rs p*2+1
#define int long long
using namespace std;
const int N=5e5+10;
int n,q,a[N];
signed  main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q--)
	{
		int op,v,l,r;
		cin>>op;
		if(op==1)
		{
			cin>>v;
			for(int i=1;i<=n;i++) a[i]=min(a[i],v);
		}
		if(op==2)
		{
			for(int i=1;i<=n;i++) a[i]+=i;
		}
		if(op==3)
		{
			int ans=0;
			cin>>l>>r;
			for(int i=l;i<=r;i++) ans+=a[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
