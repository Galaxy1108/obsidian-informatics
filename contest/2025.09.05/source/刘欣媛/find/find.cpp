#include <bits/stdc++.h>
using namespace std;
int mp[4005][4005];
int w[16000005];
inline int q(int p)
{
	int ans=1;
	while(p)
	{
		ans*=p%10;
		p/=10;
	}
	return ans;
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long n,k;
	cin>>n>>k;
	if(n>=4000)
	{
		return 0;
	}
	for(register int i=1;i<=n;i++)
	{
		int k=q(i);
		if(k<=n)
		{
			for(register int j=1;j<=n;j++)
			{
				int l=q(j);
				if(l<=n)
				{
					mp[k][l]++;
				}	
			}
		}
	}
	int tot=0;
	for(register int i=1;i<=n;i++)
	{
		for(register int j =1;j<=n;j++)
		{
			w[++tot]=mp[i][j];
		}
	}
	sort(w+1,w+tot+1);
	long long ans=0;
	for(int i=tot;i>=tot-k+1;i--)
	{
		ans+=w[i];
	}
	cout<<ans;
	
	return 0;
} 
