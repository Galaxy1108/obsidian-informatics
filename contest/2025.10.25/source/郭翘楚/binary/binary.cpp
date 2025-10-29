#include <bits/stdc++.h>
using namespace std;
bitset<100005> s;
int cnt[3];
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		s[i]=p;
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			s.flip(x);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			int ans=0;
			for(int j=l;j<=r;j++)
			{
				cnt[0]=0;
				cnt[1]=0;
				for(int k=j;k<=r;k++)
				{
					cnt[s[k]]++;
					if(cnt[1]>=3 and cnt[0]>=2)
					{
						ans+=(r-k+1);
						break;
					}
					if(cnt[1]%2==0 or (cnt[1]>=3 and cnt[0]>=2))
					{
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}
