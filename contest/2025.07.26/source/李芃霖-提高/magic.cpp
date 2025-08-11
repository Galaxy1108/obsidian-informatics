#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
struct question{
	ll time;
	ll l;
	ll id;
}qs[111111];
bool cmp(question x,question y){
	return x.time<=y.time;
}
ll maxa=-1;
ll zz=1;
ll s[11111];
ll ans[111111];
void f(ll time,ll *s){
	if(time>maxa) return ;
	ll c[111111];
	ll l=1,r=n/2+1;
	ll cnt=0;
	while(l<=n/2&&r<=n){
		if(s[l]<=s[r]){
			c[++cnt]=s[l];
			l++;
		}else{
			c[++cnt]=s[r];
			r++;
		}
	}while(l<=n/2){
		c[++cnt]=s[l];
		l++;
	}while(r<=n){
		c[++cnt]=s[r];
		r++;
	}
	while(qs[zz].time==time){
		ans[qs[zz].id]=c[qs[zz].l];
		zz++;
	}f(time+1,c);
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>s[i];
	for(ll i=1;i<=m;i++){
		cin>>qs[i].time>>qs[i].l;
		qs[i].id=i;
		maxa=max(maxa,qs[i].time);
	}
	sort(qs+1,qs+m+1,cmp);
	while(qs[zz].time==0){
		ans[qs[zz].id]=s[qs[zz].l];
		zz++;
	}f(1,s);
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}return 0;
}
