#include <bits/stdc++.h>
using namespace std;
int a[55];
int dis[55];
struct node
{
	int x,id;
}b[55];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i].x=a[i];
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		dis[b[i].id]=abs(i-b[i].id);
	}
	int ans=0; 
	for(int i=1;i<=n;i++)
	{
		ans+=dis[i]; 
//		cout<<dis[i]<<" ";
	}
//	cout<<endl;
	cout<<ans;
}
