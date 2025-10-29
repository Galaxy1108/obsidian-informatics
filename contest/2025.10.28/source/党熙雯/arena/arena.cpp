#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int mx=510;
int n,x;
int a[mx],c[mx];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
} 
int ans=0;
int getanswer()
{
	for(int i=1;i<=n;i++) c[i]=a[i];
	int cnt=n-1;
	while(1)
	{
		int sl=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]>0)
			{
				if(c[i]-cnt<=0) sl++;
			}
			c[i]-=cnt;
		}
		cnt-=sl;
//		cout<<sl<<' '<<cnt<<endl;
		if(cnt==0) return 0;
		if(cnt==-1) return 1;
//		cout<<cnt<<endl; 
	}
}
void dfs(int k)
{
	if(k==n)
	{
//		cout<<endl;
//		cout<<getanswer()<<endl<<endl;
		ans+=getanswer();
		return ;
	}
	for(int i=1;i<=x;i++)
	{
		a[k+1]=i;
		dfs(k+1);
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=fread(),x=fread();
	if(x<n)
	{
		cout<<pow(x,n);
	}
	else if(n<=5&&x<=5)
	{
		dfs(0);
		cout<<ans;
	}
	else if(n==3)
	{
		cout<<x+(x-1)*x/2*3+floor(1.0*x/2.0)*3;
	}
	return 0;
}
