#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
set<int>c,p;
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])c.insert(i);
		else p.insert(i);
	}
	c.insert(n+1);
	p.insert(n+1);
	int T;
	cin>>T;
	while(T--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			if(c.count(x))c.erase(x);
			else c.insert(x);
			if(p.count(x))p.erase(x);
			else p.insert(x);
		}
		else
		{
			int l,r;long long ans=0;
			cin>>l>>r;
			for(int i=l;i<=r;i++)
			{
				set<int>::iterator to_=c.lower_bound(i);
				set<int>::iterator tp_=p.lower_bound(i);
				int to=*to_;
				if(to>r)
				{
					ans+=(r-i+1)/2;
					continue;
				}
				set<int>::iterator too_=c.upper_bound(to);
				int too=*too_,d=min(r+1,*p.upper_bound(*tp_))-(*tp_);
				if((*tp_)<=r)
				{
					if(to==i&&too==i+1)ans-=d;
					else if(to==i)ans-=d-1;
					else ans-=max(0,d-2);
				}
				ans+=(min(r,too-1)-i)/2+((to-i)%2==0);
				if(too>r)continue;
				ans+=r-too+1;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
