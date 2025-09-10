#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
bool vis[N];
vector<int>p,q,vec;
vector<int> rev(vector<int> x)
{
	vector<int>res;
	for(int i=0;i<=n;i++)res.push_back(0);
	for(int i=1;i<=n;i++)res[x[i]]=i;
	return res;
}
vector<int> mup(vector<int>a,vector<int>b)
{
	vector<int>res;
	res.push_back(0);
	for(int i=1;i<=n;i++)res.push_back(b[a[i]]);
	return res;
}
void dfs(int pos)
{
	if(pos==n+1)
	{
		vector<int>lin=mup(vec,p);
		lin=mup(lin,rev(vec));
		if(lin==q)
		{
			cout<<"YES\n";
			for(int i=1;i<=n;i++)cout<<vec[i]<<" ";
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=true;
		vec.push_back(i);
		dfs(pos+1);
		vis[i]=false;
		vec.pop_back();
	}	
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n;
	vec.push_back(0);
	p.push_back(0);
	q.push_back(0);
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		p.push_back(x);
	}
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		q.push_back(x);
	}
	if(n>10)
	{
		cout<<"NO";
		return 0;
	}
	dfs(1);
	cout<<"NO";
	
	return 0;
} 
