#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int b[31],a[N];
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,T;
	cin>>n>>k>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	int lst=0;
	while(T--)
	{
		int op,x,y;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			if(a[x]!=y)lst=0;
			a[x]=y;
		}
		else
		{
			if(lst)
			{
				cout<<lst<<'\n';
				continue;
			}
			int ans=1e9,l=1,cnt=0;
			for(int i=1;i<=k;i++)b[i]=0;
			for(int r=1;r<=n;r++)
			{
				b[a[r]]++;
				if(b[a[r]]==1)cnt++;
				if(b[a[r]]!=1&&b[a[r]]!=2||cnt!=k)continue;
				while(1)
				{
					if(b[a[l]]==1)break;
					b[a[l]]--;
					l++;
				}
				ans=min(ans,r-l+1);
				if(ans==k)break;
			}
			if(ans==1e9)lst=-1;
			else lst=ans;
			cout<<lst<<'\n';
		}
	}
	return 0;
}
