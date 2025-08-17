#include<bits/stdc++.h>
#define F(i,a,b) for(int i(a),i##i##end(b);i<=i##i##end;++i)
#define R(i,a,b) for(int i(a),i##i##end(b);i>=i##i##end;--i)
#define ll unsigned long long
#define lowbit(i) (i&(-i))
using namespace std;
int n,Q;
ll ans;
ll s1,s2;
ll my_rand(){
	ll s3=s1,s4=s2;
	s1=s2^774527;
	s3^=(s3<<47)^(s3>>13);
	s2^=s3^(s4<<31)^(s4>>17);
	return s2+s4;
}
void get_query(int &op,ll &num1,ll &num2){
	op=my_rand()%2+1;
	if(op==1){
		num1=my_rand()%n+1;
		num2=my_rand()%n+1;
	}else{
		num1=my_rand()%n+1;
		num2=my_rand()%n+1;
		if(num1>num2) swap(num1,num2);
	}
}
struct tree_array{
	ll c[10000001]={};
	inline void add(int x,ll k){
		for(int cnt(k);x<=n;x+=lowbit(x),cnt+=k) c[x]+=cnt;
		return;
	}
	inline ll query(int x){
		ll res(0);
		for(;x;x-=lowbit(x)) res+=c[x];
		return res;
	}
}qwq;
int main(){
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>Q>>s1>>s2;
	F(i,1,Q){
		int op;
		ll x,y;
		get_query(op,x,y);
		if(op==1) qwq.add(x,y);
		else ans^=i*(qwq.query(y)-qwq.query(x-1));
	}
	cout<<ans;
	return 0;
} 
