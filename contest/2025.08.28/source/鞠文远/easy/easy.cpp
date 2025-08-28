#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q,ary[N];
signed main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>ary[i];
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int v;
			cin>>v;
			for(int i=1;i<=n;i++)ary[i]=min(ary[i],v);
		}
		if(op==2)for(int i=1;i<=n;i++)ary[i]+=i;
		if(op==3)
		{
			int l,r,anslt=0;
			cin>>l>>r;
			for(int i=l;i<=r;i++)anslt+=ary[i];
			cout<<anslt<<"\n";
		}
	}
	
	return 0;
}
