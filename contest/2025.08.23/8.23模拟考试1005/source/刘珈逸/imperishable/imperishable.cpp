#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=998244353;
int n,m,a[N],p2[N],sp[N];
typedef long long ll;
ll sum[N<<2];
typedef pair<int,int> pii;
#define fi first
#define se second
int maxn[N<<2];
pii minn[N<<2];
void pushup(int p){
	sum[p]=sum[p<<1]+sum[p<<1|1];
	maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
	minn[p]=min(minn[p<<1],minn[p<<1|1]);
}
void build(int p,int l,int r){
	if(l==r){
		sum[p]=a[l];
		maxn[p]=a[l];
		minn[p]={a[l],l};
		return;
	}int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
void change(int p,int l,int r,int k){
	if(l==r){
		sum[p]=a[l];
		maxn[p]=a[l];
		minn[p]={a[l],l};
		return;
	}int mid=l+r>>1;
	if(k<=mid)change(p<<1,l,mid,k);
	else change(p<<1|1,mid+1,r,k);
	pushup(p);
}
ll query_sum(int p,int l,int r,int l1,int r1){
	if(l1>r1)return 0;
	if(l1<=l&&r<=r1)return sum[p];
	int mid=l+r>>1;ll ans=0;
	if(l1<=mid)ans+=query_sum(p<<1,l,mid,l1,r1);
	if(r1>mid)ans+=query_sum(p<<1|1,mid+1,r,l1,r1);
	return ans;
}
pii query_mn(int p,int l,int r,int l1,int r1){
	if(l1>r1)return{0x3f3f3f3f,0};
	if(l1<=l&&r<=r1)return minn[p];
	int mid=l+r>>1;pii ans={0x3f3f3f3f,0};
	if(l1<=mid)ans=min(ans,query_mn(p<<1,l,mid,l1,r1));
	if(r1>mid)ans=min(ans,query_mn(p<<1|1,mid+1,r,l1,r1));
	return ans;
}
int query_mx(int p,int l,int r,int l1,int r1){
	if(l1>r1)return 0;
	if(l1<=l&&r<=r1)return maxn[p];
	int mid=l+r>>1,ans=0;
	if(l1<=mid)ans=max(ans,query_mx(p<<1,l,mid,l1,r1));
	if(r1>mid)ans=max(ans,query_mx(p<<1|1,mid+1,r,l1,r1));
	return ans;
}
int gets(int l,int r){
	return(sp[r]-sp[l-1]+mod)%mod;
}
int query1(int p,int l,int r,int st,int&mx,ll&s){//第一个不满足条件的位置 
	if(l>st)return 0;
	if(r<=st){
		if(s-sum[p]>=max(mx,maxn[p])){
			s-=sum[p];
			mx=max(mx,maxn[p]);
			return 0;
		}
		if(l==r)return l;
	}int mid=l+r>>1;
	int x=query1(p<<1|1,mid+1,r,st,mx,s);
	if(x)return x;
	return query1(p<<1,l,mid,st,mx,s);	
}
int query2(int p,int l,int r,int st,int mx,pii&mn,int s){
	if(l>st)return 0;
	if(r<=st){
		if(s-min(mn,minn[p]).fi<mx){
			mn=min(mn,minn[p]);
			return 0;
		}if(l==r)return l;
	}int mid=l+r>>1;
	int x=query2(p<<1|1,mid+1,r,st,mx,mn,s);
	if(x)return x;
	return query2(p<<1,l,mid,st,mx,mn,s);
}
int query(){
	int mx=0,now=n,ans=0;ll sum=0;
	while(now){
		ll s=query_sum(1,1,n,1,now-1);
		if(sum+s>=max(mx,a[now])){//可以不选 
			s+=a[now]+sum;
			int u=query1(1,1,n,now,mx,s)+1;
			now=u-1;
		}else{//必须选 
			s+=a[now]+sum;pii mn={0x3f3f3f3f,0};int mx1=max(mx,query_mx(1,1,n,1,now));
			int u=query2(1,1,n,now,mx1,mn,s)+1;
			sum+=query_sum(1,1,n,u,now);
			ans=(ans+gets(u,now))%mod;
			now=u-1;
		}
	}return ans;
}
void read(int&x){
	x=0;char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
}
int main(){
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	int id;read(id),read(n);
	p2[0]=1;
	for(int i=1;i<=n;i++)p2[i]=p2[i-1]*2%mod,sp[i]=(sp[i-1]+p2[i])%mod;
	for(int i=1;i<=n;i++)read(a[i]);
	build(1,1,n);
	printf("%d\n",query());
	read(m);
	while(m--){
		int x,y;read(x),read(y);a[x]=y;
		change(1,1,n,x);
		printf("%d\n",query());
	}
	return 0;
}
/*
不会有两个集合的f值相等
我们描述这一个过程
从大往小考虑一个集合能否不被选
考虑a[x]互不相同
选的数的个数只有O(sqrt(n))种,可以暴力枚举
不选的数的max要<=选的数的总和
猜测选的数的连续段是很少的 
连续的一段能不选的 即 后缀max<=前缀sum
连续的一段必须选的 即 max(num,mx other) > 其他sum-num
0
4
4 1 2 3
2
1 1
1 2 
*/
