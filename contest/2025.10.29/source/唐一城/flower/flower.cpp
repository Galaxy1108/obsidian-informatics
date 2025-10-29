#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=165;
int n,a[N],vis[N],flag=0;
string name[N];
il void dfs(int x) {
	if(flag)return;
	if(x==0) {
//		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		for(int i=1;i<=n;i++)cout<<name[a[i]]<<'\n';
		flag=1;
		return;
	}
	for(int i=n;i>=1;i--) {
		if(vis[i]||vis[i+x+1]||i+x+1>n)continue;
		vis[i]=1,a[i]=x,vis[i+x+1]=1,a[i+x+1]=x;
		dfs(x-1); 
		vis[i]=0,a[i]=0,a[i+x+1]=0,vis[i+x+1]=0;
	}
}
int main() {
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>name[i];
	n=n*2,flag=0;
	dfs(n/2);	
	
	return 0;
}
