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

ll vis[N],b[N],s[N],n,m,q,mina;
void dfs(ll last,ll now,ll score){
	if(score>mina) return ;
	if(now==n+1){
		mina=min(mina,score);
		return ;
	}
	if(b[now]){
		if(now!=1) score+=(last%2!=s[b[now]]%2);
		dfs(s[b[now]],now+1,score);
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]!=1){
			vis[i]=1;
			if(now!=1) dfs(s[i],now+1,score+(s[i]%2!=last%2));
			else dfs(s[i],now+1,score) ;
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read<ll>();
	m=read<ll>();
	q=read<ll>();
	for(ll i=1;i<=n;i++){
		s[i]=read<ll>();
	} 
	for(ll i=1;i<=m;i++){
		ll x=read<ll>();
		ll y=read<ll>();
		ll tmp;
		for(ll k=1;k<=n;k++){
			if(s[k]==y&&vis[k]!=1){
				tmp=k;
				break ; 
			}
		}
		b[x]=tmp;
		vis[tmp]=1;
	}
	while(q--){
		ll op,x,y;
		op=read<ll>();
		x=read<ll>();
		if(op==1){
			vis[b[x]]=0;
			b[x]=0;
			m--;
		}
		if(op==2){
			ll y=read<ll>();
			ll tmp;
			for(ll k=1;k<=n;k++){
				if(s[k]==y&&vis[k]!=1){
					tmp=k;
					break ; 
				}
			}
			b[x]=tmp;
			vis[tmp]=1;
			m++;
		}
		mina=INT_MAX;
		dfs(0,1,0);
		cout<<mina<<endl;
	}
}
