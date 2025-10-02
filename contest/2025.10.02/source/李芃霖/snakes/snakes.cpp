#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;

template<class T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 

ll n,t,cnt,ans=1;
bool vis[N];

struct node{
	ll val;
	ll id;
}s[N];

bool compare(node x,node y){
	if(x.val!=y.val) return x.val>y.val;
	else return x.id>y.id;
}

bool dfs(ll last,ll cnt){
	node mina={INT_MAX,0};
	node maxa={0,0};
	for(ll i=1;i<=n;i++){
		if(vis[i]==1) continue ;
		if(compare(mina,s[i])) mina=s[i];
		if(compare(s[i],maxa)) maxa=s[i];
	}
	if(cnt==2){
		if(mina.id==last) return 0;
		else return 1;
	}
	vis[mina.id]=1;
	s[maxa.id].val-=s[mina.id].val;
	if(dfs(maxa.id,cnt-1)){
		if(mina.id==last) return 0;
		else return dfs(last,cnt-1);
	}else{
		ans=max(cnt,ans);
		vis[mina.id=0];
		s[maxa.id].val+=s[mina.id].val;
		return 1;
	}
}

void init(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read<ll>();
	n=read<ll>();
	t--;
	for(ll i=1;i<=n;i++){
		s[i].val=read<ll>();
		s[i].id=i;
	}
	return ;
}

int main(){
	init();
	dfs(0,n);
	cout<<ans<<endl;
	while(t--){
		ll k;
		k=read<ll>();
		for(ll i=1;i<=k;i++){
			ll x,y;
			x=read<ll>();
			y=read<ll>();
			s[x].val=y;
		}
		memset(vis,0,sizeof(vis));
		ans=1;
		dfs(0,n);
		cout<<ans<<endl;
	}
	return 0;
}
