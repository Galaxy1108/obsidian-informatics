#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[100001],sum=0;
bool check(int x){
	int t=1;
	for(int i=1;i<=m;i++){
		if(abs(b[i]-a[t])<=x) t++;
		if(t==n) return true;
	}
	return false;
}
int f(){
	int l=0,r=sum,mid,ans=sum;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(check(r)) ans=min(r,ans);
	if(check(l)) ans=min(l,ans);
	return ans;
}
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	if(n>m){
		for(int i=1;i<=m;i++){
			swap(a[i],b[i]);
		}
		swap(n,m);
	} 
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	sum=max(a[n],b[m]);
	cout<<f()<<endl;
	return 0;
} 
/*
5 5 
7 6 1 2 10 
9 11 6 3 12
*/
