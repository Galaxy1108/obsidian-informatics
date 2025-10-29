#include<bits/stdc++.h>
using namespace std;
const int N=100;
int fl[N],n,tmp[N],cnt;
bool vis[N];
string s[N];
void dfs(int stp)
{
	//if(++cnt>=1e8) exit(0);
	if(tmp[stp]!=0)
	{
		dfs(stp+1);
		return;
	}
	if(stp>2*n)
	{
		for(int i=1;i<=2*n;i++) cout<<s[tmp[i]]<<endl;
		exit(0);
		return ; 
	}
	for(int i=n;i>=1;i--)
	{
		if(vis[i]) continue;
		if(tmp[stp+i+1]||stp+i+1>2*n)continue;
		vis[i]=1;
		tmp[stp]=tmp[stp+i+1]=i;
		dfs(stp+1);
		tmp[stp]=tmp[stp+i+1]=0;
		vis[i]=0;
		
	}
}
int main() 
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	dfs(1);
	return 0;
}
