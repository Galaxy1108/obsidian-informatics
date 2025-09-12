#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=2e5+100;
int n;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct tree
{
	int fa,lson,ns,len,nx;
}a[mx];
struct edge
{
	int to,nxt;
}e[2*mx];
int h[mx],cnt;
void build(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
//	cout<<cnt<<":"<<e[cnt].to<<endl;
	return ;
}
//void pre(int fa,int x)
//{
//	a[x].len=max(a[x].len,1);
//	a[x].fa=fa;
//	cout<<x<<' '<<fa<<endl;
//	for(int i=h[x];i;i=e[i].nxt)
//	{
//		int v=e[i].to;
//		if(!a[v].fa)
//		{
//			pre(x,v);
//			if(a[v].len+1>a[x].len)
//			{
//				a[x].len=a[v].len+1;
//				a[x].lson=v;
//				a[x].ns++;
//				if(ns==1)
//				{
//					a[x].ns=a[v].nx;
//					a[x].cns=a[v].cns+1;
//				}
//				else a[x].ns=x;
//			}
//		}
//	}
//}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	int T=fread();
	while(T--)
	{
		memset(h,0,sizeof(h));
		memset(a,0,sizeof(a));
		n=fread();
		for(int i=1;i<n;i++)
		{
			int u=fread(),v=fread();
//			build(u,v),build(v,u);
		}
//		pre(-1,1);
		int kk=0;
		while(n)
		{
			kk++;
			n/=2;
		}
		cout<<kk<<'\n';
	}
	return 0;
}
/*
1
10
1 2
2 3
3 6
3 7
3 8
8 9
1 4
4 10
1 5
*/
