#include<bits/stdc++.h>
using namespace std;
int n,p[100005],q[100005],h[100005],book[100005],hh[100005];
bool f=false;
bool check(){
	for(int i=1;i<=n;i++) 
		hh[h[i]]=i;
	for(int i=1;i<=n;i++)
		if(hh[p[h[i]]]!=q[i])
			return false;
	return true;
			
}
void dfs(int x){
	if(x==n+1){
		if(check()){
			f=true;
			cout<<"YES\n";
			for(int i=1;i<=n;i++)
				cout<<h[i]<<" ";
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i])
			continue;
		book[i]=1;
		h[x]=i;
		dfs(x+1);
		if(f)
			return;
		book[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int j=1;j<=n;j++)
		cin>>q[j];
	if(n<=10) 
		dfs(1);
	if(!f)
		cout<<"NO\n";
	return 0;
} 
