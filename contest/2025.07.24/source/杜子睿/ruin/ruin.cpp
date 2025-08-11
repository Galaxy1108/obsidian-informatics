#include<bits/stdc++.h>
using namespace std;
int n,a[25],b[25],c[25],ans;
bool check(){
	int book[25],b[25];
	for(int i=1;i<=2*n;i++)
		b[i]=::b[i];
	for(int i=0;i<n;i++){
		memset(book,0,sizeof book);
		for(int j=2*n;j>=1;j--){
			book[b[j]]++;
			if(b[j]&&book[b[j]]>1)
				b[j]--;
		}
	}
	int f=0;
	for(int i=0;i<n;i++){
		if(!b[a[i]]){
			f=1;
			break;
		}
		b[a[i]]=0;
	}
	if(f)
		return false;
	for(int i=1;i<=2*n;i++) {
		if(b[i]){
			f=1;
			break; 
		} 
	}
	return f^1;
}
void dfs(int x){
	if(x==2*n+1){
		if(check())
			ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=2){
			c[i]++;
			b[x]=i;
			dfs(x+1);
			c[i]--;
		}
	}
}
int main(){
	freopen("ruin.in","r",stdin);
	freopen("ruin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(a[n-1]!=2*n){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

