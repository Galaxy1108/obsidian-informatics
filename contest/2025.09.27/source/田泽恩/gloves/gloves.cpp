#include <bits/stdc++.h>
using namespace std;
int n,m,a[114514],b[114514],ans;
bool check(int mid){
	int i=1,j=1,cnt=0;
	while(i<=n&&j<=m){
		if(abs(a[i]-b[j])>mid){
			if(a[i]<b[j]) ++i;
			else if(a[i]>b[j]) ++j;
		}
		else{
			++i;
			++j;
			++cnt;
		}
	}
	return cnt==min(n,m);
}
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int j=1;j<=m;++j) cin>>b[j];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int l=0,r=1e9,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans;
	return 0;
} 
