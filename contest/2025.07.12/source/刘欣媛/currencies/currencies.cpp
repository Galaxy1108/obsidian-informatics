#include <bits/stdc++.h>
using namespace std;
vector<int> v[250005];
int p[100005],c[100005],r[100005],pre[250005];
bool mp[250005];
int main()
{
	freopen("w","currencies.in",stdin);
	freopen("r","currencies.out",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		r[i]=a;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>p[i]>>c[i];
		c[r[p[i]]]=c[i];
	}
	for(int i=1;i<=q;i++)
	{
		int s,t,x,y;
		cin>>s>>t>>x>>y;
		queue<int> q;
		q.push(s);
		memset(mp,0,sizeof(mp));
		while(q.size())
		{
			int o=q.front();
			if(o==t)
			{
				break;
			}
			q.pop();
			for(int i=0;i<v[o].size();i++)
			{
				if(!mp[v[o][i]])
				{
					q.push(v[o][i]);
					mp[v[o][i]]=1;
					pre[v[o][i]]=o;
				}
			}
		}
		int pe=pre[t];
		while(pe!=s)
		{
			if(c[pe]){
				if(y>=c[pe]){
					y-=c[pe];
				}
			}
			else
			{
				x--;
			}
		}
		if(x<0)
		{
			cout<<x<<"-1\n";
		}
		else
		{
			cout<<x<<"\n";
		}
	}
	
	return 0;
 } 
