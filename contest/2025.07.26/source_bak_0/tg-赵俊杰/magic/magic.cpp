#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],ans[N],b[N];
vector<int>v[N],id[N];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,T;
	cin>>n>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=T;i++)
	{
		int t,x;
		cin>>t>>x;
		if(t>n*2)t=n*2;
		v[t].push_back(x);
		id[t].push_back(i);
	}
	for(int i=0;i<=n*2;i++)
	{
		for(int j=0;j<v[i].size();j++)
			ans[id[i][j]]=a[v[i][j]];
		int x=1,y=n/2+1;
		for(int j=1;j<=n;j++)
		{
			if(x>n/2)
			{
				b[j]=a[y++];
				continue;
			}
			if(y>n)
			{
				b[j]=a[x++];
				continue;
			}
			if(a[x]<a[y])b[j]=a[x++];
			else b[j]=a[y++];
		}
		for(int j=1;j<=n;j++)a[j]=b[j];
	}
	for(int i=1;i<=T;i++)cout<<ans[i]<<'\n';
	return 0;
}
