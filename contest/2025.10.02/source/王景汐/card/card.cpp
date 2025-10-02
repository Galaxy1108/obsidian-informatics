#include<bits/stdc++.h>
using namespace std;
long long int a[1000001];
int b[1000001];
bool c[1000001];
long long int n,m,q,www=INT_MAX,cnt;
void dfs(int u,int x,int y)
{
	cnt=0;
	if(x==0)
	{
		for(int i=u;i<=n;i++)
		{
			if(b[i]==0) {b[i]=1;c[i]=1;}
		}
		for(int i=2;i<=n;i++) if(b[i]!=b[i-1]) cnt++;
		if(cnt<www) www=cnt;
		for(int i=u;i<=n;i++) if(c[i]==1) b[i]=0;
		memset(c,0,sizeof(c));
		return;
	}
	if(y==0)
	{
		for(int i=u;i<=n;i++)
		{
			if(b[i]==0) {b[i]=2;c[i]=1;}
		}
		for(int i=2;i<=n;i++) if(b[i]!=b[i-1]) cnt++;
		if(cnt<www) www=cnt;
		for(int i=u;i<=n;i++) if(c[i]==1) b[i]=0;
		memset(c,0,sizeof(c));
		return;
	}
	if(b[u]!=0) dfs(u+1,x,y);
	else{
	b[u]=2;
	dfs(u+1,x-1,y);
	b[u]=1;
	dfs(u+1,x,y-1);
	b[u]=0;
}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	long long int x=0,y=0,c,d,e,f,g;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]%2==0) x++;
		else y++;
	}
	while(m--)
	{
		cin>>c>>d;
		if(d%2==0) {x--;b[c]=2;}
		else {b[c]=1;y--;}
	}
	while(q--)
	{
		cin>>e>>f;
		if(e==1)
		{
			if(b[f]%2==0) x++;
			else y++;
			b[f]=0;
			dfs(1,x,y);
		}
		else
		{
			cin>>g;
			if(g%2==0){x--;b[f]=2;}
			else{b[f]=1;y--;}
			dfs(1,x,y);
		}
		cout<<www<<endl;
		www=INT_MAX;
	}
	
 	return 0;
}
 	

