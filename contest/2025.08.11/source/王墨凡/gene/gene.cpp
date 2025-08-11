#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,l,r,a[1000086],vis[1000086],lp,rp,ans=1e9;
map<pair<int,int>,int> m;
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	cin >> n >> l >> r;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=l;i<=r;i++)vis[a[i]]++;	
	for(int i=r+1;i<=n;i++){
		if(vis[a[i]])continue;
		for(int j=l-1;j>=1;j--){
			if(vis[a[j]]==0 and a[j]<a[i]){
				m[{a[j],a[i]}]++;
			} 
		}
	}
	for(int i=r+1;i<=n;i++){
		for(int j=l-1;j>=1;j--){
			if(m[{a[j],a[i]}]==1){
				ans=min(ans,i-j+1);
			}
		}
	}
	if(ans==1e9){
		cout << -1;
	}
	else cout << ans;
	return 0;
} 
