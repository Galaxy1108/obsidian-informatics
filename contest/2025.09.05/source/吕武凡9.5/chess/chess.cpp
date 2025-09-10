#include<bits/stdc++.h>
using namespace std;
int n,m;
int lin[110];
long long ans=0;
int mod=9999973;
void DFS(int deep)
{
	if(deep>m)
	{
		ans++;
		ans%=mod;
		return;
	}
	DFS(deep+1);
	for(int i=1;i<=n;i++)
	{
		if(lin[i]<=1)
		{
			lin[i]++;
			DFS(deep+1);
			lin[i]--;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(lin[i]<=1&&lin[j]<=1)
			{
				lin[i]++;
				lin[j]++;
				DFS(deep+1);
				lin[i]--;
				lin[j]--;
			}
		}
	}
	
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	DFS(1);
	cout<<ans;
}
