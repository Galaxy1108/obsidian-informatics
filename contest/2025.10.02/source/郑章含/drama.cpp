#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,h[2000010];
__int128 ans;
struct Node{
	int l,r,minn,maxn;
}t[4000010];
void print(__int128 x){
	if(x==0){
		printf("0");
		return ;
	}
	if(x<0){
		printf("-");
		x=-x;
	}
	int cl=0,c[1000];
	memset(c,0,sizeof(c));
	while(x){
		c[++cl]=x%10;
		x/=10;
	}
	for(int i=cl;i>=1;i--) printf("%d",c[i]);
}
void build(int u,int l,int r){
	t[u].l=l;
	t[u].r=r;
	if(l==r){
		t[u].minn=t[u].maxn=h[l];
		return ;
	}
	int mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	t[u].maxn=max(t[u*2].maxn,t[u*2+1].maxn);
	t[u].minn=min(t[u*2].minn,t[u*2+1].minn);
}
int query_min(int u,int l,int r){
	int ul=t[u].l,ur=t[u].r;
	if(l<=ul&&ur<=r) return t[u].minn;
	int mid=(ul+ur)/2,minn=100000000000; 
	if(l<=mid) minn=min(query_min(u*2,l,r),minn);
	if(mid+1<=r) minn=min(query_min(u*2+1,l,r),minn);
	return minn;
}
int query_max(int u,int l,int r){
	int ul=t[u].l,ur=t[u].r;
	if(l<=ul&&ur<=r) return t[u].maxn;
	int mid=(ul+ur)/2,maxn=0; 
	if(l<=mid) maxn=max(query_max(u*2,l,r),maxn);
	if(mid+1<=r) maxn=max(query_max(u*2+1,l,r),maxn);
	return maxn;
}
signed main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	build(1,1,n);
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			__int128 cnt;
			cnt=(__int128)query_min(1,l,r);
			cnt*=(__int128)query_max(1,l,r);
			cnt*=(__int128)(r-l+1);
			ans=max(ans,cnt);
		}
	}
	print(ans);
	return 0;
} 
