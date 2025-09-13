#include <bits/stdc++.h>
using namespace std;
int suma[2000005];
int fa[2000005];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void add(int x,int y)
{
	fa[find(x)]=find(y);
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,lk,rk;
	cin>>n>>lk>>rk;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		if(s[i-1]=='a')
		{
			suma[i]=suma[i-1]+1;
		}
		else
		{
			suma[i]=suma[i-1];
		}
	}
	if(n<=5000)
	{	
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int sa=suma[j]-suma[i-1];
				if(sa>=lk and sa<=rk)
				{
					add(i,j);
					break;
				}
			}
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		if(l>r)
		{
			swap(l,r);
		}
		if(n<=5000)
		{
			for(int i=l;i<=r;i++)
			{
				for(int j=i+1;j<=r;j++)
				{
					int sa=suma[j]-suma[i-1];
					if(sa>=lk and sa<=rk)
					{
						add(i,j);
						break;
					}
				}
			}
			int sa=suma[r]-suma[l-1];
			if(find(l)==find(r))
			{
				cout<<"Yes"<<'\n';
				continue;
			}
			else
			{
				cout<<"No"<<'\n'; 
			}
		}
		else if (lk==rk)
		{
			int sa=suma[r]-suma[l-1];
			if(find(l)==find(r))
			{
				cout<<"Yes"<<'\n';
				continue;
			}
			else
			{
				cout<<"No"<<'\n'; 
			}
		}
		else if (lk!=rk)
		{
			int sa=suma[l];
			int sb=suma[r]-suma[l];
			int sc=suma[n]-suma[l];
			if((sa+sb>=lk or sc-sb>=lk) and (sa>lk or sc>lk))
			{
				cout<<"Yes"<<'\n'; 
			}
			else
			{
				cout<<"No"<<'\n';
			}
		}
		else
		{
			cout<<"No"<<'\n';
		}
	}
	return 0;
 } 
