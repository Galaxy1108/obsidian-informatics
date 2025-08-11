#include<bits/stdc++.h>
#define int long long 
using namespace std;
int T,mi;
signed main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		int s,k;
		cin>>s>>k;
		if(s%2==1)cout<<(2*k>=s?-1:2*k)<<"\n";
		else
		{
			for(int i=1;i<=s;i++)
				if(s%i!=0)
				{
					mi=i;
					break;
				}
			cout<<(mi*k>=s?-1:mi*k)<<"\n";
		}
	}
	
	return 0;
} 
