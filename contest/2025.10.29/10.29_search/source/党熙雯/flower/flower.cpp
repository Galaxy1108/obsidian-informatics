#include<bits/stdc++.h>
using namespace std;
const int mx=50;
int n;
string s[mx];
int vis[mx];
int a[mx];
int flag;
//int check()
//{
//	for(int i=1;i<=2*n;i++)
//	{
//		if(a[i]!=a[i+a[i]+1]) return 0;
//	}

//	return 1;
//}
void dfs(int k)
{
	if(k==1)
	{
		flag=1;
//		for(int i=1;i<=2*n;i++)
//		cout<<a[i]<<' ';cout<<endl; 
		return ;
	}
	for(int i=1;i<=2*n;i++)
	{
		if(vis[i]||i+k>2*n||vis[i+k]) continue;
		vis[i]=1;
		vis[i+k]=1;
		a[i]=a[i+k]=k-1;
		dfs(k-1);
		if(flag==1) return ;
		vis[i]=0;
		vis[i+k]=0;
	 } 
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>s[i];
//	for(int i=1;i<=n;i++) cout<<s[i]<<endl;
	dfs(n+1);
	for(int i=1;i<=2*n;i++)
	{
//		cout<<a[i]<<endl;
		cout<<s[a[i]]<<endl;
	}
	return 0;
}
