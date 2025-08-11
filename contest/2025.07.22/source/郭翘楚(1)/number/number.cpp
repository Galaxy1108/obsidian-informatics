#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		vector <long long> x(m);
		for(auto &i:x)
		{
			cin>>i;
		}
			reverse(x.begin(),x.end());
			vector <long long> f(n+1,-1e18); 
			f[0]=0;
			for(long long i:x)
			{
				vector<long long> g(n+1,-1e18);
				for(long long j=0;j<=n;j++)
				{
					if(j) g[j-1]=max(g[j-1],f[j]-i);
					if(j<n) g[j+1]=max(g[j+1],f[j]+i); 
				}
				f=g;
			}
			cout<<*max_element(f.begin(),f.end())<<endl;
	}
	return 0;
}
