#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=1e6+10;
int num[2],num1[2],a[mx],p[mx],r[mx],l[mx],must[2];
int n,m,q;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int ans=2e9;
void dfs(int k,int n0,int n1)
{
	if(k==n)
	{
		int numm=0;
		for(int i=2;i<=n;i++)
		if(a[i]!=a[i-1]) numm++;
		ans=min(ans,numm); 
//		cout<<endl;
		return ;
	}
	if(p[k+1]!=-1) 
	{
		a[k+1]=p[k+1];
		dfs(k+1,n0,n1);
		return ;
	}
	if(n0)
	{
		a[k+1]=0;
		dfs(k+1,n0-1,n1);
	}
	if(n1)
	{
		a[k+1]=1;
		dfs(k+1,n0,n1-1);
	}
 } 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=fread(),m=fread(),q=fread();
	for(int i=1;i<=n;i++) a[i]=fread(),num1[a[i]%2]++;
	for(int i=1;i<=n;i++) p[i]=-1;
	for(int i=1;i<=m;i++) 
	{
		int loc=fread();
		p[loc]=fread()%2;
		num1[p[loc]]--;
	}
//	cout<<num1[0]<<' '<<num1[1]<<endl;
	while(q--)
	{
		int op=fread();
		ans=2e9;
		if(op==1)
		{
			int x=fread();
			if(p[x]!=-1)
			num1[p[x]]++;
			p[x]=-1;
		}
		else
		{
			int loc=fread(),x=fread()%2;
			if(p[loc]!=-1) num1[p[loc]]++;
			num1[x]--;
			p[loc]=x;
			
		}
		dfs(0,num1[0],num1[1]);
		cout<<ans<<endl;
	}
	return 0;
}


