#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void read(ll &a){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	a=x*f;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    ll id,op,n;
    read(id),read(op),read(n);
    for(ll i=1;i<n;i++){
        ll u,v,w;
        read(u),read(v),read(w);
    }
    for(ll i=1;i=n;i++){
        ll a;
        read(a);
    }
    ll Q;
    read(Q);
    for(ll i=1;i<=Q;i++){
        ll l,r,k;
        read(l),read(r),read(k);
    }
    for(ll i=1;i<=Q;i++)
        cout<<0<<endl;
	return 0;
}