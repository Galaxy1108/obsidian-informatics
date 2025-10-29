#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
vector<ll> ans;
inline ll read(){
	ll x=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=gc();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		pc('-');
		x=-x;
	}
	if(x>9)
		write(x/10);
	pc(x%10+'0');
}
inline ll gcd(ll x,ll y){
    ll r;
    while(x%y!=0){
        r=x%y;
        x=y;
        y=r;
    }
    return y;
}
inline pair<ll,ll> minu(ll a_son,ll a_mom,ll b_son,ll b_mom){
	ll n_son=a_son*b_mom-a_mom*b_son,n_mom=a_mom*b_mom;
	if(n_son<0)
		return {-1,-1};
	if(n_son==0)
		return {0,0};
	ll g=gcd(n_son,n_mom);
	n_son/=g;
	n_mom/=g;
	return {n_son,n_mom};
}
inline void dfs(ll son,ll mom){
	for(ll i=2;;i++){
		auto tmp=minu(son,mom,1,i);
		if(tmp.first==-1)
			continue;
		else if(tmp.first==0){
			ans.push_back(i);
			write(ans.size());
			pc('\n');
			for(auto i:ans){
				write(i);
				pc(' ');
			}
			exit(0);
		}
		else{
			ans.push_back(i);
			dfs(tmp.first,tmp.second);
			ans.pop_back();
		}
	}
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	ll a=read(),b=read();
	ll g=gcd(a,b);
	a/=g,b/=g;
	if(a==1){
		pc('1'),pc('\n');
		write(b);
		return 0;
	}
	dfs(a,b);
	return 0;
}