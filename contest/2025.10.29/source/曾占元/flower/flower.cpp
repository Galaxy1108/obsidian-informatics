#include<bits/stdc++.h>
#define int unsigned long long
#define base 131
using namespace std;
int n,pos=0,s[50],used[50],ans[100];
string st[50];
unordered_map<string,int>lst;
int Hash(string s)
{
	int sum=0,n=s.size();
	for(int i=0;i<n;i++)
		sum=sum*base+s[i]-'a'+1;
	return sum;
}
bool dfs(int x)
{
	if(x==2*n+1)
	{
		for(int i=1;i<x;i++)
			cout<<st[ans[i]]<<'\n';
		return 1;
	}
	for(int i=1;i<=n;i++)
	{
		if(lst.find(st[i])==lst.end())
		{
			used[i]++;
			ans[++pos]=i;
			lst[st[i]]=pos;
			if(dfs(x+1))
				return 1;
			else
			{
				pos--;
				used[i]--;
				lst.erase(st[i]);
			}
		}
		else
		{
			if(pos-lst[st[i]]==i&&used[i]<2)
			{
				used[i]++;
				ans[++pos]=i;
				if(dfs(x+1))
					return 1;
				else
				{
					pos--;
					used[i]--;
				}
			}
		}
	}
	return 0;
}
signed main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i];
		s[i]=Hash(st[i]);
	}
	dfs(1);
	return 0;
}
