#include<bits/stdc++.h>
using namespace std;
const int N=300+10; 
int n,x,y;
int num[N][N],t[N*N];
bool bb,vis[N*N];
int lowbit(int x)
{
	return x&-x;
}
void add(int u,int x)
{
	for (int i=u;i<=n;i+=lowbit(i))
		t[i]+=x;
}
int ask(int u)
{
	int res=0;
	for (int i=u;i>=1;i-=lowbit(i))res+=t[i];
	return res;
}
void dfs(int xx,int yy)
{
	if(bb) return ;
	if(xx>n)
	{
		int cnt=0,a[N*N],b[N*N],cnta=0,cntb=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[++cnt]=num[i][j],b[cnt]=num[j][i];
		for(int i=1;i<=n*n;i++)
		{
			for(int j=i+1;j<n*n;j++)
			{
				if(a[i]>a[j]) cnta++;
				if(b[i]>b[j]) cntb++; 
			}
		}
		if(cnta==x&&cntb==y)
		{
			bb=1;
			cout<<"Yes"<<endl;
			for(int i=1;i<=n;i++,cout<<endl) for(int j=1;j<=n;j++) cout<<num[i][j]<<' ';
		}
		return ;
	}
	for(int i=1;i<=n*n;i++)
	{
		if(vis[i]) continue;
		num[xx][yy]=i;
		vis[i]=1;
		if(yy<n) dfs(xx,yy+1);
		else dfs(xx+1,1);
		vis[i]=0;
	}
}
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(t,0,sizeof t);
		cin>>n>>x>>y;
		if(n<=3)
		{
			memset(vis,0,sizeof vis);
			bb=0;
			dfs(1,1);
			if(!bb) cout<<"NO"<<endl;
		}
		else
		{
			if(x==0)
			{
				int cnt=0,b[N*N];
				for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)num[i][j]=++cnt;
				cnt=0;
				for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) b[++cnt]=num[j][i];
				int ans=0;
				for(int i=1;i<=n*n;i++) ans+=ask(b[i]),add(b[i],1);
				if(ans!=y) cout<<"No"<<endl;
				else
				{
					cout<<"Yes"<<endl;
					for(int i=1;i<=n;i++,cout<<endl) for(int j=1;j<=n;j++) cout<<num[i][j]<<' ';
				}
			}
			else if(y==0)
			{
				int cnt=0;
				int a[N*N];
				for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)num[j][i]=++cnt;
				cnt=0;
				for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[++cnt]=num[i][j];
				int ans=0;
				for(int i=1;i<=n*n;i++) ans+=ask(a[i]),add(a[i],1);
				if(ans!=y) cout<<"No"<<endl;
				else
				{
					cout<<"Yes"<<endl;
					for(int i=1;i<=n;i++,cout<<endl) for(int j=1;j<=n;j++) cout<<num[i][j]<<' ';
				}
			}
		}
	}
	return 0;
}
