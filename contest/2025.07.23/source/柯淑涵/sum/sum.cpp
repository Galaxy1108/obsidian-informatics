#include <bits/stdc++.h>
using namespace std;
long long n,m,k,mod,ans=0,sum1=0;
long long a[20],b[20];
void dfs(int x,int y){
	if(x==n+1){
		sum1=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				sum1*=min(a[i],b[j]);
			}
		}
		ans+=sum1;
		ans%=mod;
		return;
	}
	int xx=x,yy=y+1,aa=a[x],bb=b[x];
	if(y==m) xx++,yy=1;
	for(long long i=1;i<=k;i++){
		a[x]=min(a[x],i);
		b[y]=min(b[y],i);
		dfs(xx,yy);
		a[x]=aa;
		b[y]=bb;
	}
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n>>m>>k>>mod;
	for(int i=1;i<=max(n,m);i++) a[i]=1e9+10;
	for(int i=1;i<=max(n,m);i++) b[i]=1e9+10;
	if(k==1) cout<<n*m<<endl;
	else if(k==2){
		dfs(1,1);
		cout<<ans<<endl;
	}
	else cout<<0<<endl;
	return 0; 
} 
