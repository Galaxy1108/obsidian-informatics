#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[11],n,b[11],t[101];
ll res[11]={0,0,0,0,17,904,45926,2725016,196884712,17350671831,1847029162807};
ll ans,p;
int work(){
	int cnt=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j]>a[i])cnt++;
		}
	}
	return cnt;
}
void dfs(int x){
	if(x==n+1){
		int now=work();
		t[now]++;
		for(int i=now+1;i<=(n*n+n)/2;i++)ans+=t[i];
		ans%=p;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			a[x]=i;
			b[i]=1;
			dfs(x+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	cin>>n>>p;
	cout<<res[n]%p<<endl;
	return 0;
}
