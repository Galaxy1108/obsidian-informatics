#include <bits/stdc++.h>
using namespace std;
int n,p;
vector<int> v[305],d[305];
int siz[305],tot,dep[305],fa[305];
bool mp[305];
inline void dfs(int i,int de)
{
	tot++;
//	cout<<tot<< " ";
	if(v[i].size()==0)
	{
		siz[i]=1;
		return;
	}
	dep[i]=de;
//	cout<<i<<" "<<dep[i]<<"\n";
	for(auto u:v[i])
	{
		if(u==fa[i]) continue;
		dep[u]=dep[i]+1;
		fa[u]=i;
		//cout<<dep[v[i][u]]<<" "<<dep[i]<<"\n";
		dfs(u,de+1);
		siz[i]+=siz[u];
	}
	
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>p;
	//dep[1]=1;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	int op,po;
	for(int i=1;i<=p;i++)
	{
		cin>>op>>po;
		v[op].push_back(po);
		v[po].push_back(op);
	}
	dfs(1,0);
	long long ans=1;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		k=max(k,dep[i]);
		d[dep[i]].push_back(i);
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<dep[i]<<" ";
//	}
//	cout<<"\n";
	for(int i=1;i<=k;i++)
	{
		int g=0,p=0,res=0;
		for(auto j:d[i])
		{
			if(mp[j]==1)
			{
			//	cout<<"??";
				for(auto l:v[j]){
					mp[l]=1;
				}
				continue;
			}
			//cout<<j<<" ";
			res++;
			if(g<v[j].size())
			{
				g=v[j].size();
				p=j;
			}
			
		}
	//	cout<<"\n";
		if(p==0)
		{
			break;
		}
		ans+=res-1,mp[p]=1;
		for(auto j:v[p])
		{
			if(j==fa[p]) continue;
			mp[j]=1;
		//	cout<<j<<" ";
		}
	//	cout<<"l\n";
	//	cout<<p<<" "<<ans<<"\n";
	}
	cout<<ans;
//	for(int i=1;i<=n;i++) cout<<mp[i];
	return 0;
 } 
