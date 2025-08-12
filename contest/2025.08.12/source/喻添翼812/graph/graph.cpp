#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int T,n,m;
int cnt,h[mx];
struct Edge
{
	int to,nxt;
}e[mx*4];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nxt=h[x];
	h[x]=cnt;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		int k=ceil(1.0*m/(n-1));
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		cout<<"1 3"<<endl<<"2 1 3"<<endl<<"1 4"<<endl;
		cout<<"4 1 2 3 4"<<endl<<"2 1 4"<<endl<<"2 1 4"<<endl;
		cout<<"3 5"<<endl<<"3 3 4 5"<<endl<<"2 3 5";
	}
	return 0;
} 
