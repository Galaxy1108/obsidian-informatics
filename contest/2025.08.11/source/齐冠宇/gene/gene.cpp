#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
constexpr int N=1e6+5;
int n,l,r;
int a[N];
int t[N],suf[N],pos[N];
bool fl;
int lim;
priority_queue<pii>q;
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		lim=max(lim,a[i]);
		if(i<=r)
			t[a[i]]++,pos[a[i]]=i;
		else
			suf[a[i]]++;
	}
	for(int i=1;i<=lim;i++)
		if(t[i]==1 && !(l<=pos[i] && pos[i]<=r))
			q.push(mp(pos[i],i));
	for(int i=r+1;i<=n;i++)
	{
		t[a[i]]++;
		if(suf[a[i]]==1)
		{
			//cout<<a[i]<<' ';
			while(!q.empty() && t[q.top().se]!=1)
				q.pop();
			while(!q.empty() && q.top().se==a[i])
				q.pop();
			if(t[a[i]]==1)
			{
				if(!q.empty())
				{
					//cout<<a[q.top().fi]<<' ';
					cout<<i-q.top().fi+1;
					//cerr<<i-q.top().fi+1;
					return 0;
				}
			}
			else
			{
				if(!q.empty() && q.top().fi>pos[a[i]])
				{
					cout<<i-q.top().fi+1;
					return 0;
				}
			}	
		}
		pos[a[i]]=i;
	}
	cout<<"-1";
	return 0;
}
