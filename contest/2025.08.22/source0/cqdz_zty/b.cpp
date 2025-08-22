#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,f=0,fl;
ll ans;
int d[2005][2005];
int v[2005];
void dfs(int x){
	cout<<x<<' ';
	v[x]=1;
	for(int i=1;i<=n;i++){
		if(i==x) continue;
		if(v[i]) continue;
		if(d[x][i]==1){
			ans++;
			dfs(i);
		}
	}
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int x;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cin>>d[i][j];
			d[j][i]=d[i][j];
			if(d[i][j]==1) f=1;
		}
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			cout<<1ll*1000000000*(n-1)<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		fl=0;
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(d[i][j]==1){
				fl=1;
				break;
			}
		}
		if(fl==1){
			cout<<n-1<<'\n';
		}
		else {
			cout<<1000000000+n-2<<'\n';
		}
	}
	return 0;
}
/*
4
1 1 1000000000
1 1000000000
1000000000
*/
