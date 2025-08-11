#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+20;
int n,m,q,r[mx],vis[mx];
struct city
{
	int fa,w[100],cnt;
}a[mx];
int fread()
{
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
void find(int x)
{
	while(a[x].fa!=0)
	{
//		cout<<x<<' ';
//		cout<<a[x].fa<<'\n';
		if(vis[x]) vis[x]=0;
		else vis[x]=1;
		x=a[x].fa;
	}
}
//bool cmp(city x,city y)
//{
//	if(x.w&&y.w)
//	return x.w<y.w;
//	if(x.w) return 1;
//	return 0;
//}
int main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	n=fread();
	m=fread();
	q=fread();
	for(int i=1;i<=n-1;i++)
	{
		int x=fread();
		int y=fread();
		if(a[x].fa==0) a[x].fa=y,r[i]=x;
		else a[y].fa=x,r[i]=y;
	}
//	for(int i=1;i<=n-1;i++) cout<<r[i]<<' ';cout<<endl;
	for(int i=1;i<=m;i++)
	{
		int p=fread();
		int c=fread();
		a[r[p]].w[++a[r[p]].cnt]=c;
	}
//	cout<<endl;
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<' '<<a[i].fa<<' '<<a[i].w[a[i].cnt]<<endl;
//	}
//	for(int i=1;i<=n;i++) cout<<a[i].cnt<<' ';cout<<endl;
	while(q--) 
	{
		int s=fread();
		int t=fread();
		int x=fread();
		int y=fread();
		find(s);
		find(t);
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' '; cout<<endl;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
				int k=0;
				while(a[i].cnt-k)
				{
//					cout<<y<<' '<<x<<' '<<a[i].w[a[i].cnt]<<endl;
					if(y>a[i].w[a[i].cnt]) y-=a[i].w[a[i].cnt-k],k++;
					else x--,k++;
				}
				vis[i]=0;
			}
//			cout<<endl;
		}
		if(x>=0) cout<<x<<'\n';
		else cout<<"-1\n";
//		memset(vis,0,sizeof(vis));
	}
	return 0;
}
