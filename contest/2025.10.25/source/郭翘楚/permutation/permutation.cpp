#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main() 
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int n;
	cin>>n;
	int cnt1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i*2-1]>>a[i*2];
		if(a[i*2-1]==-1)
		{
			cnt1++;
		}
		if(a[i*2]==-1)
		{
			cnt1++;
		}
	}
	if(cnt1==0)
	{
		cout<<0;
	}
	else
	{
		cout<<cnt1*2%mod;
	}
}
