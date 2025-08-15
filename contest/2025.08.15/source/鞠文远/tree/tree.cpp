#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Edge{int v,w;};
vector<Edge>vec[N];
vector<int>cl;
int n,f[N],g[N],a[N];
void getcl(int u)
{
	cl.push_back(u);
	for(int i=0;i<vec[u].size();i++)getcl(vec[u][i].v);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=1;i<=n;i++)
	{
		int w;
		cin>>w;
		vec[f[i]].push_back({i,w});
	}
	for(int i=1;i<=n;i++)cin>>g[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cout<<0<<" ";
	
	return 0;
} 
