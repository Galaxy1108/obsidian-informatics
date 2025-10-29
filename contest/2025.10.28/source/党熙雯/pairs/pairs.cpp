#include<bits/stdc++.h>
using namespace std;
const int mx=200;
int n,mod;
int vis[mx];

int p[4000000];
int cnt=0;
int s[mx];
int t1[11];
int t2[60];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
int lowbit(int x)
{
	return x&-x;
}
void add1(int pos,int x)//计算逆序对数量的加法 
{
	for(int i=pos;i<=n;i+=lowbit(i))
	t1[i]+=x; 
}
int ask1(int pos)
{
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))
	ans+=t1[i];
	return ans;
}
void add2(int pos,int x)// 字典序小的排列的逆序对数量 
{
	for(int i=pos;i<=59;i+=lowbit(i))
	t2[i]+=x,t2[i]%=mod; 
}
int ask2(int pos)
{
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))
	ans+=t2[i];
	return ans;
}
int ask()
{
	int ans=0;
	memset(t1,0,sizeof(t1));
	for(int i=n;i>=1;i--)
	{
		ans+=ask1(s[i]);
		add1(s[i],1);
	}
	return ans;
}
int ans=0;
void dfs(int k)
{
	if(k==n)
	{
		++cnt;
//		for(int i=1;i<=n;i++)
//		a[cnt][i]=s[i],cout<<s[i]<<' ';cout<<endl;
		p[cnt]=ask();
//		cout<<p[cnt]<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			s[k+1]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=fread(),mod=fread();
	dfs(0);
	int ans=0;
//	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		ans+=ask2(55)-ask2(p[i]);
		ans%=mod;
//		cout<<ans<<endl;
		if(p[i]!=0)
		add2(p[i],1);
	}
	cout<<ans;
	return 0;
}

