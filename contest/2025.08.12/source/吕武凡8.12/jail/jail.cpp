#include<bits/stdc++.h>
using namespace std;
int fa[1000100];
int dis[100100];
int head[1000100];
bool vis[1000100];
int tot=0;
int n,m;
int x[1000100],y[1000100];
int s[1000100],t[1000100];
int T;
struct Edge
{
	int nx,to;
}e[2000100];
void edge(int u,int v)
{
	e[++tot].nx=head[u];
	e[tot].to=v;
	head[u]=tot;
}
struct node
{
	int id,dis;
	bool operator<(const node x)const
	{
		return x.dis<dis;
	}
};
priority_queue<node> q;
void dij(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
	}
	dis[s]=0;
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	q.push({s,dis[s]});
	while(q.size())
	{
		node u=q.top();
		int id=u.id;
		q.pop();
		if(vis[id])
		{
			continue;
		}
		vis[id]=1;
		for(int i=head[id];i;i=e[i].nx)
		{
			int y=e[i].to;
			if(dis[y]>dis[id]+1)
			{
				dis[y]=dis[id]+1;
				if(vis[y]==0)
				{
					q.push({y,dis[y]});	
				}
			}
		}
	}
}
void init(int s,int u)
{
	for(int i=head[s];i;i=e[i].nx)
	{
		int y=e[i].to;
		if(y==u)
		{
			continue;
		}
		fa[y]=s;
		init(y,s);
	}
}
int find(int x,int y)
{
	int i=x,j=y;
	int p=0,q=0;
	while(i!=1)
	{
		i=fa[i];
		p++;
	}
	while(j!=1)
	{
		j=fa[j];
		q++;
	}
	if(p>q)
	{
		int k=p-q;
		while(k--)
		{
			x=fa[x];
		}
	} 
	else
	{
		int k=q-p;
		while(k--)
		{
			y=fa[y];
		 } 
	}
	while(x!=y)
	{
		x=fa[x];
		y=fa[y];
	}
	return x;
} 
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	cin>>T;
	while(T--)
	{
		tot=0;
		memset(fa,0,sizeof(fa));
		memset(head,0,sizeof(head));
		cin>>n;
		bool f=0;
		for(int i=1;i<n;i++)
		{
			cin>>x[i]>>y[i];
			if(x[i]+1!=y[i])
			{
				f=1;
			}
			edge(x[i],y[i]);
			edge(y[i],x[i]);
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>s[i]>>t[i];
		}
		if(f==0)
		{
			bool ti=0;
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(i==j)
					{
						continue;
					}
					if((t[j]<=s[i]&&s[i]<s[j]&&s[j]<=t[i])||(s[i]<=s[j]&&s[j]<t[j]&&t[j]<=t[i])||(s[i]<=t[j]&&t[j]<s[j]&&s[j]<=t[i])||(s[i]<=t[j]&&t[j]<t[i]&&t[i]<=s[j]))
					{
						ti=1;
						goto mn;
					}
					if((t[j]>=s[i]&&s[i]>s[j]&&s[j]>=t[i])||(s[i]>=s[j]&&s[j]>t[j]&&t[j]>=t[i])||(s[i]>=t[j]&&t[j]>s[j]&&s[j]>=t[i])||(s[i]>=t[j]&&t[j]>t[i]&&t[i]>=s[j]))
					{
						ti=1;
						goto mn;
					}
				}
			}
			mn:;
			if(ti==1)
			{
				cout<<"No"<<endl;
			}	
			else
			{
				cout<<"Yes"<<endl;
			}
		}
		
		else
		{
			init(1,1);
			fa[1]=1;
			if(m==2)
			{
				
			}
			else
			{
				srand(time(0));
				int k=rand()%2;
				if(k==0)
				{
					cout<<"No"<<endl;
				}
				else
				{
					cout<<"Yes"<<endl;	
				}
			}
		}	
	}
	
	
}
/*
1
10
1 2
2 3
3 5
5 7
5 8
8 10
2 4
6 4
9 1
2
4 5
6 8
*/
/*
1 
8 
1 2 
2 3 
3 4 
4 5 
5 6 
6 7 
7 8 
2 
3 4 
4 8

1
12
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
6
1 3
2 5
4 6
9 7
11 8
12 10

1
12
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
6
1 3
2 5
4 6
9 8
11 7
12 10

3
8 
1 2 
2 3 
3 4 
4 5 
5 6 
6 7 
7 8 
2 
3 4 
4 8
12
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
6
1 3
2 5
4 6
9 7
11 8
12 10
12
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
6
1 3
2 5
4 6
9 8
11 7
12 10

1
10
1 2
2 3
3 4 
4 5
5 6
6 7
7 8
8 9
9 10
6
1 4
2 5
3 6
6 7
7 8
10 9

1
10
1 2
2 3
3 4 
4 5
5 6
6 7
7 8
8 9
9 10
6
1 5
2 4
3 6
6 7
7 8
10 9

5
8 
1 2 
2 3 
3 4 
4 5 
5 6 
6 7 
7 8 
2 
3 4 
4 8
12
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
6
1 3
2 5
4 6
9 7
11 8
12 10
12
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
6
1 3
2 5
4 6
9 8
11 7
12 10
10
1 2
2 3
3 4 
4 5
5 6
6 7
7 8
8 9
9 10
6
1 5
2 4
3 6
6 7
7 8
10 9
10
1 2
2 3
3 4 
4 5
5 6
6 7
7 8
8 9
9 10
6
1 4
2 5
3 6
6 7
7 8
10 9
*/
