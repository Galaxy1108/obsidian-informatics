#include<bits/stdc++.h>
using namespace std;
int n;
string st[110];
int a[110];
int dfs(int x){
	if(!x) return 1;
	for(int i=1;i+x+1<=2*n;++i){
		if(!a[i]&&!a[i+x+1]){
			a[i]=a[i+x+1]=x;
			if(dfs(x-1)) return 1;
			a[i]=a[i+x+1]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i) cin>>st[i];
	
	dfs(n);
	for(int i=1;i<=2*n;++i) cout<<st[a[i]]<<'\n';
	
	return 0;
} 
