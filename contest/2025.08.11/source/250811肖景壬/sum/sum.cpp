#include<bits/stdc++.h>
using namespace std;
int t;
long long s,k;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>s>>k;
		if(k*2>s) cout<<-1<<endl;
		else cout<<k*2<<endl;
	}
}
