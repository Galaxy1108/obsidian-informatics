#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],b[2],c[N];
vector<int>len[2];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,T;
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		b[c[i]&1]++;
		a[i]=-1;
	}
	for(int i=1;i<=m;i++)
	{
		int t,p;
		cin>>t>>p;
		a[t]=p&1;
		b[p&1]--;
	}
	while(T--)
	{
		int op,t,x;
		cin>>op>>t;
		if(op==1)
		{
			if(a[t]>=0)b[a[t]]++;
			a[t]=-1;
		}
		else
		{
			cin>>x;
			if(a[t]>=0)b[a[t]]++;
			a[t]=x&1;
			b[x&1]--;
		}
		len[0].clear();len[1].clear();
		int ans=0,lst=0,l,r,p,q;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=-1)
			{
				if(!lst)l=i-lst-1,p=a[i];
				else
				{
					if(a[i]!=a[lst])ans++;
					else len[a[i]].push_back(i-lst-1);
				}
				lst=i;
			}
		}
		//cout<<b[0]<<' '<<b[1]<<' '<<ans<<":  ";
		//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		//cout<<'\n';
		r=n-lst;q=a[lst];
		sort(len[0].begin(),len[0].end());
		sort(len[1].begin(),len[1].end());
		int s[2]={b[0],b[1]};
		for(int i=0;i<len[0].size();i++)
		{
			if(s[0]<len[0][i])
			{
				ans+=2*(len[0].size()-i);
				break;
			}
			s[0]-=len[0][i];
		}
		for(int i=0;i<len[1].size();i++)
		{
			if(s[1]<len[1][i])
			{
				ans+=2*(len[1].size()-i);
				break;
			}
			s[1]-=len[1][i];
		}
		if(s[p]<l)ans++;
		if(s[q]<r)ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
