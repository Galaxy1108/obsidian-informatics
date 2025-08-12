#include<bits/stdc++.h>
using namespace std;
const int N=120005;
struct T
{
	int ne,to;
}e[2*N];
struct Q
{
	int x,y,op;
}a[N];
int he[N],idx;
void add(int x,int y)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	he[x]=idx;
}
bool cmp(Q a,Q b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,flag=1;
		cin>>n;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			if(!(x==i&&y==i+1))flag=0;
			add(x,y);
			add(y,x);
		}
		cin>>m;
		for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y;
		if(flag)
		{
			flag=0;
			for(int i=1;i<=m;i++)
			{
				if(a[i].x>a[i].y)
				{
					swap(a[i].x,a[i].y);
					a[i].op=1;
				}
			}
			sort(a+1,a+m+1,cmp);
			int mx=0;
			for(int i=1;i<=m;i++)
			{
				if(mx>=a[i].y)flag=1;
				mx=max(mx,a[i].y);
			}
			if(flag)
			{
				cout<<"No\n";
				continue;
			}
			for(int i=2;i<=m;i++)
				if(a[i].op!=a[i-1].op&&a[i].x<a[i-1].y)flag=1;
			if(flag)cout<<"No\n";
			else cout<<"Yes\n";
		}
		else
		{
			cout<<"Yes\n";
		}
	}
	return 0;
}
