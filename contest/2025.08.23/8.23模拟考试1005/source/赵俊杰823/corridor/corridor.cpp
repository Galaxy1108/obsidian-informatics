#include<bits/stdc++.h>
using namespace std;
const int N=500005;
set<int>h[N],w[N];
int main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int id,n,m,k;
	cin>>id>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		w[i].insert(0);
		w[i].insert(m+1);
	}
	for(int i=1;i<=m;i++)
	{
		h[i].insert(0);
		h[i].insert(n+1);
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		w[x].insert(y);
		h[y].insert(x);
	}
	int T;
	cin>>T;
	while(T--)
	{
		int op,x,y,t,k;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			w[x].insert(y);
			h[y].insert(x);
		}
		else
		{
			cin>>x>>y>>k;
			k++;
			if(x==0)t=0;
			else t=1;
			while(x<=n&&y<=m&&k)
			{
				k--;
				t^=1;
				if(!k)break;
				if(t==0)
				{
					y=*w[x].upper_bound(y);
					//y++;
				}
				else
				{
					x=*h[y].upper_bound(x);
					//x++;
				}
			}
			cout<<x<<' '<<y<<'\n';
		}
	}
	return 0;
}
