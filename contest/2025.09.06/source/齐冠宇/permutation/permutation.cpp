#include <bits/stdc++.h>
#define vi vector<int>
#define pb emplace_back
using namespace std;
constexpr int N=2e5+5;
int n;
int p[N],q[N];
int ph[N],toh[N];
int e1[N],e2[N];
int h[N];
vi cyc[N];
bool vis[N];
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],e1[i]=p[i];
	for(int i=1;i<=n;i++)
		cin>>q[i],ph[i]=i,toh[i]=q[i],e2[ph[i]]=toh[i];
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int j=e1[i],cnt=1;
			vis[i]=1;
			while(1)
			{
				if(j==i)break;
				vis[j]=1,cnt++,j=e1[j];
			}
			cyc[cnt].pb(i);
		}
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int j=e2[i],cnt=1;
			vis[i]=1;
			while(1)
			{
				if(j==i)break;
				vis[j]=1,cnt++,j=e2[j];
			}
			if(!cyc[cnt].size())return cout<<"NO",0;
			int id=cyc[cnt].back();
			cyc[cnt].pop_back();
			j=e2[i];
			h[i]=id;
			id=e1[id];
			while(1)
			{
				if(j==i)break;
				h[j]=id;
				j=e2[j],id=e1[id];
			}
		}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
		cout<<h[i]<<' ';
	cout<<'\n';
	for(int i=1;i<=n;i++)
		if(p[h[i]]!=h[q[i]])
			return cout<<"WA",0;
	cout<<"AC";
	return 0;
}
