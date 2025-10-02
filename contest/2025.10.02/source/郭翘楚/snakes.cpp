#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n;
int solve()
{
	multiset<int> s;
	for(int i=1;i<=n;i++)
	{
		s.insert(a[i]);
	}
	int f=0;
	while(1)
	{
		f++;
		int one=*s.begin();
		auto id=s.begin();
		int two=*next(s.begin(),1);
		int t=*s.rbegin();
//		cout<<one<<" "<<two<<" "<<t<<'\n';
//		for(int i:s)
//		{
//			cout<<i<<'\n';
//		}
		if(s.size()==2)
		{
			return 1;
		}
		if(t-one>two)
		{
			s.insert(t-one);
			auto it=s.find(one);
			s.erase(it);
			auto id=s.find(t);
			s.erase(id);
		}
		else
		{
			if(s.size()%2==0) return s.size()-1; 
			return s.size();
		}
			
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		if(i==1)
		{
			cin>>n;
			for(int j=1;j<=n;j++)
			{
				cin>>a[j];
			}
		}
		else
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
		}
		cout<<solve()<<'\n';
	}
}
