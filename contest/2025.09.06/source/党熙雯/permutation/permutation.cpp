#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=1e5+100;
int p[mx],q[mx],hn[mx],h[mx],fl[mx];
int n;
int vis[mx];
int b=0;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
//h[q[i]]=p[h[i]]
//bool check()
//{
//	memset(vis,0,sizeof(vis));
//	for(int i=1;i<=n;i++)
//	if(vis[h[i]]) return 0;
//	else vis[h[i]]=1;
//	return 1;
//}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		hn[h[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int ans=hn[p[h[i]]];
		if(ans!=q[i]) return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++) cout<<h[i]<<' ';
	return 1;
}
void dfs(int k)
{
	if(k>n)
	{
		if(b) return ;
//		for(int i=1;i<=n;i++) cout<<h[i]<<' ';cout<<endl;
		b=check();
		return ;
	}
	if(b) return ;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		h[k]=i;
		vis[i]=1;
//		for(int j=1;j<=k;j++) cout<<h[j]<<' ';cout<<endl;
//		for(int j=1;j<=n;j++) cout<<vis[j]<<' ';cout<<endl;
		dfs(k+1);
		vis[i]=0;
		h[k]=0;
//			if(b) return ;
	}
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=fread();
	for(int i=1;i<=n;i++) p[i]=fread();
	for(int i=1;i<=n;i++) q[i]=fread();
//	for(int i=1;i<=n;i++) cout<<fl[i]<<' ';cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		hn[q[i]]=i;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		h[1]=i;
//		int ls=1;
//		int pp=hn[1];
//		int cnt=1;
//		while(cnt<n)
//		{
//			h[pp]=fl[h[ls]];
//			ls=pp,pp=hn[pp];
//			cnt++;
//		}
//		for(int j=1;j<=n;j++) cout<<h[i]<<' ';
//		cout<<endl;
//		if(check()) break;
//	}

	dfs(1);
//	for(int i=1;i<=n;i++) cout<<h[i]<<' ';
	if(b==0) cout<<"NO";
	return 0;
}


