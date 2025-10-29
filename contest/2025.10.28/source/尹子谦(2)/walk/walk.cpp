#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=998244353;
int n,x,ans,mn=1e9,cnt,num[N];
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x,x%=2;
		if(x==1) num[++cnt]=i;
	} 
	for(int i=1;i<=cnt;i++)
	{
		for(int j=i;j<=cnt;j++)
		{
			mn=min(mn,cnt-j+i-1+num[j]-num[i]+1-(j-i+1));
		}
	}
	cout<<mn;
	return 0;
} 
