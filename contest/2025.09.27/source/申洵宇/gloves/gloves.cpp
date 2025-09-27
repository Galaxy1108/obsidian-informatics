#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,lg[N],rg[N];
bool check(int x){
	int lst=0,now;
	for(int i=1;i<=n;i++){
		now=lower_bound(rg+1,rg+m+1,lg[i]-x)-rg;
		now=max(now,lst+1);
		if(now>m)return false;
		if(abs(rg[now]-lg[i])>x)return false;
		lst=now;
	}
	return true;
}
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>lg[i];
	}	
	for(int i=1;i<=m;i++){
		cin>>rg[i];
	}
	if(n>m){
		swap(lg,rg);
		swap(n,m);
	}
	sort(lg+1,lg+n+1);
	sort(rg+1,rg+m+1);
	int l=0,r=1000000000,mid,ans=1000000000;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}