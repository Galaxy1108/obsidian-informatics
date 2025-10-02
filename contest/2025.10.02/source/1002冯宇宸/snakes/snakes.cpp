#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int t,n,m,i,j,x,y;
int s[N];
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
deque<int> p,q;
inline void solve()
{
	while(p.size()) p.pop_back();
	while(q.size()) q.pop_back();
	for(i=1;i<=n;i++) p.push_back(s[i]);
	while(1)
	{
		int x=-1e9,y=1e9,t=1e9;
		if(!p.empty())
		{
			x=max(x,p.back());
			y=min(y,p.front());
		}
		if(!q.empty())
		{
			x=max(x,q.back());
			y=min(y,q.front());
		}
		if(p.size()&&x==p.back()) p.pop_back();
		else q.pop_back();
		if(p.size()&&y==p.front()) p.pop_front();
		else q.pop_front();
		if(q.size()+p.size()==0)
		{
			puts("1");
			return ;
		}
		if(p.size()) t=p.front();
		if(q.size()) t=min(t,p.front());
		int delt=x-y;
		if(delt<t)
		{
			if((p.size()+q.size())%2==0)
				cout<<p.size()+q.size()+1<<'\n';
			else cout<<p.size()+q.size()+2<<'\n';
			return ;
		}
		else q.push_front(x-y);
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read();n=read();
	for(i=1;i<=n;i++)//单调不降
		s[i]=read();
	solve();
	while(--t)
	{
		m=read();
		while(m--)
		{
			x=read();y=read();
			s[x]=y;
		}
		solve();
	}
	return 0;
}
