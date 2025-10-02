#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l,r,val1,val2;
}s[4000005];
int n,a[1000005];
int m,m1;
inline void build(int t,int l,int r){
	s[t].l=l,s[t].r=r;
	if(l==r){
		s[t].val1=s[t].val2=l;
		return;
	}
	int mid=(l+r)/2;
	build(t*2,l,mid);
	build(t*2+1,mid+1,r);
	if(a[s[t*2].val1]<=a[s[t*2+1].val1]) s[t].val1=s[t*2].val1;
	else s[t].val1=s[t*2+1].val1;
	if(a[s[t*2].val2]>=a[s[t*2+1].val2]) s[t].val2=s[t*2].val2;
	else s[t].val2=s[t*2+1].val2;
}
inline node query1(int t,int l,int r){
	//cout<<s[t].l<<" "<<s[t].r<<endl;
	if(l<=s[t].l&&r>=s[t].r){
		return s[t];
	}
	int mid=(s[t].l+s[t].r)/2;
	node ma;
	if(l<=mid) ma=query1(t*2,l,r);
	if(r>mid){
		if(l>mid) return query1(t*2+1,l,r);
		else{
			node b=query1(t*2+1,l,r);
			if(a[b.val1]<a[ma.val1]) ma.val1=b.val1;
			if(a[b.val2]>a[ma.val2]) ma.val2=b.val2;
		}
	}
	return ma;
}
inline int f(int l,int r){
	
	if(l>r) return -1;
	if(l==r){
	//	cout<<l<<" "<<r<<" "<<a[l]<<endl;
		return a[l]*a[l];
	}
	
	int ma=0;
	node mid=query1(1,l,r);
	ma=a[mid.val1]*a[mid.val2]*(r-l+1);
	ma=max(ma,f(l,mid.val1-1));
	ma=max(ma,f(mid.val1+1,r));
//	ma=max(ma,f(l,mid));
//	ma=max(ma,f(mid,r));
//	cout<<l<<" "<<r<<" "<<mid<<" "<<query2(1,l,r)<<" "<<ma<<endl;
	return ma;
}
signed main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	build(1,1,n);
//	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	cout<<f(1,n)<<endl;
	return 0;
}
/*
9 
5 11 15 17 19 3 19 9 4 
10
5 11 15 17 19 3 19 9 4 7 

*/
