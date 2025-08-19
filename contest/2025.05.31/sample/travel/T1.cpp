#include <bits/stdc++.h>
using namespace std;
const int zjj=0x3f;
const int N=1000005,M=N*2;
int n,m,e[M],ne[M],w[M],h[N],idx,d[N][55];
bool st[N][55];
struct Node
{
	int u,dis,pre;
	bool operator <(const Node&W) const
	{
		return dis>W.dis;
	}
};
void add(int a,int b,int c)
{
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(h,-1,sizeof(h));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	priority_queue<Node> q;
	q.push({1,0,0});
	memset(d,0x3f,sizeof(d));
	d[1][0]=0;
	while(q.size())
	{
		Node t=q.top();
		q.pop();
		int u=t.u,dis=t.dis,pre=t.pre;
		if(st[u][pre])
		{
			continue;
		}
		st[u][pre]=true;
		for(int i=h[u];~i;i=ne[i])
		{
			int ver=e[i];
			if(!pre)
			{
				if(dis<d[ver][w[i]])
				{
					d[ver][w[i]]=dis;
					q.push({ver,dis,w[i]});
				}
			}
			else
			{
				int p=(pre+w[i])*(pre+w[i])+dis;
				if(p<d[ver][0])
				{
					d[ver][0]=p;
					q.push({ver,p,0});
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i][0]==1061109567) cout<<-1<<" ";
		else cout<<d[i][0]<<" ";
	}
	return 0;
}
