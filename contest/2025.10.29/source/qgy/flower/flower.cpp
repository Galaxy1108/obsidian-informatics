#include <bits/stdc++.h>
using namespace std;
constexpr int N=45;
int n;
string s[N];
bool vis[N];
int p[N<<1];
bool usd[N<<1];
int las[N];
bool chk()
{
	for(int i=1;i<=n*2;i++)
	{
		if(!las[p[i]])
			las[p[i]]=i;
		else
		{
			if(i-las[p[i]]-1!=p[i])return 0;
		}
	}
	return 1;
}
void dfs(int x)
{
	if(x==2*n+1)
	{
		for(int i=1;i<=n*2;i++)
			cout<<s[p[i]]<<'\n';
		// cerr<<(chk()?"AC":"WA");
		exit(0);
	}
	if(usd[x])return void(dfs(x+1));
	for(int i=n;i>=1;i--)
		if(!vis[i] && x+i+1<=2*n && !usd[x+i+1])
		{
			vis[i]=usd[x+i+1]=1;
			p[x]=i;
			p[x+i+1]=i;
			dfs(x+1);
			vis[i]=usd[x+i+1]=0;
		}
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	dfs(1);
	cout<<"fk";
	return 0;
}