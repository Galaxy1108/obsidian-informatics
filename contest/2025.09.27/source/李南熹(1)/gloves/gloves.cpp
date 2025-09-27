#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010],b[100010],vis[100010],n,m,ans=0x3f;
signed main(){
	freopen("gloves","r",stdin);
	freopen("gloves","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	stable_sort(a+1,a+1+n);
	stable_sort(b+1,b+m+1);
	if(m>=n){
		for(int i=1;i<=m-n+1;i++){
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			int k=abs(a[1]-b[i]);
			for(int j=2;j<=n;j++){
				int l=lower_bound(b+1,b+1+m,a[j])-b;
				int r=abs(b[l]-a[j]);
				if(abs(b[l-1]-a[j])<=r&&vis[l-1]==0) l=l-1;
				else if(vis[l]==1) l=l+1;
				vis[l]=1;
				k=max(k,abs(b[l]-a[j]));
			}
			ans=min(k,ans);
		}
	}
	else{
		for(int i=1;i<=n-m+1;i++){
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			int k=abs(b[1]-a[i]);
			for(int j=2;j<=m;j++){
				int l=lower_bound(a+1,a+1+n,b[j])-a;
				int r=abs(a[l]-b[j]);
				if(abs(a[l-1]-b[j])<=r&&vis[l-1]==0) l=l-1;
				else if(vis[l]==1) l=l+1;
				vis[l]=1;
				k=max(k,abs(a[l]-b[j]));
			}
			ans=min(k,ans);
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
