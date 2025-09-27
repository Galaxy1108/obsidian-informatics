#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+50;
template<class T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 

ll xr[4*N],ma[4*N],s[N],n,cnt=0,ls[4*N],rs[4*N];

void build(ll now,ll l,ll r){
	ls[now]=l;
	rs[now]=r;
	if(l==r){
		xr[now]=s[l];
		ma[now]=s[l];
		return ;
	}
	ll mid=(l+r)>>1;
	build(2*now,l,mid);
	build(2*now+1,mid+1,r);
	ma[now]=max(ma[now*2],ma[now*2+1]);
	xr[now]=xr[2*now]^xr[2*now+1];
	return ;
}

ll askxor(ll now,ll l,ll r){
//	cout<<now<<" "<<l<<" "<<r<<" "<<ls[now]<<" "<<rs[now]<<endl;
	if(l<=ls[now]&rs[now]<=r){
		return xr[now];
	}
	ll mid=(ls[now]+rs[now])>>1,ret=0;
	if(l<=mid) ret=ret^askxor(now*2,l,r);
	if(r>mid) ret=ret^askxor(2*now+1,l,r);
	return ret ;
}

ll askmax(ll now,ll l,ll r){
//	cout<<now<<" "<<l<<" "<<r<<" "<<ls[now]<<" "<<rs[now]<<endl;
	if(l<=ls[now]&&rs[now]<=r){
		return ma[now];
	}
	ll mid=(ls[now]+rs[now])>>1,ret=0;
	if(l<=mid) ret=max(ret,askmax(2*now,l,r));
	if(r>mid) ret=max(ret,askmax(2*now+1,l,r));
	return ret ;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read<ll>();
	for(ll i=1;i<=n;i++) s[i]=read<ll>();
	build(1,1,n);
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(askmax(1,i,j)>=askxor(1,i,j)) cnt++;
		}
	} 
	cout<<cnt<<endl;
	return 0;
}
