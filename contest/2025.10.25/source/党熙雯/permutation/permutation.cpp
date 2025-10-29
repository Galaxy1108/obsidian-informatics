#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mod=1e9+7;
const int mx=1e5+10;
int n;
int a[2*mx],b[mx];
int s[mx],vis[mx];
map<string,int> m;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int getanswer()
{
	string ss="";
	for(int i=1;i<=2*n;i+=2)
	{
		int x=min(s[i],s[i+1]);
		char ch=x+'0';
		ss=ss+ch;
	}
//	cout<<ss<<endl;
	if(m[ss]==0) 
	{
		m[ss]++;
		return 1;
	}
	return 0;
}
int ans=0;
void dfs(int k)
{
//	cout<<"Debug:"<<k<<endl;
	if(k==2*n)
	{
//		for(int i=1;i<=2*n;i++) cout<<s[i]<<' ';
//		cout<<endl;
		ans+=getanswer();
		return ;
	}
	if(a[k+1]!=-1)
	{
		s[k+1]=a[k+1];
		dfs(k+1);
		return ;
	}
	for(int i=1;i<=2*n;i++)
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
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=fread();
	for(int i=1;i<=2*n;i++) a[i]=fread(),vis[a[i]]+=(a[i]!=-1);
		dfs(0);
		cout<<ans;
	return 0;
}


