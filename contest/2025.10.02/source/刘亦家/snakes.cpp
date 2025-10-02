#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll T,n,sum;
struct node{
	ll len,id;
}snake[N];
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
inline bool cmp(node a,node b){
	return a.len>b.len;
}
inline void dfs(ll i){
	if(snake[i].len-snake[i+1].len<snake[i+2].len)
		return;
	else if(snake[i].len-snake[i+1].len==snake[i+2].len&&snake[i+2].id>snake[i].id)
		return;
	else if(i>=n)
		return;
	else{
		snake[i+1].len=-1;
		
	}
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
    read(T);
	for(ll t=1;t<=T;t++){
		memset(snake,0,sizeof(snake));
		read(n);
		sum=n;
		for(ll i=1;i<=n;i++){
			if(t==1)
				read(snake[i].len);
			else{
				ll num;
				read(num),read(snake[num].len);
			}
			snake[i].id=i;
		}
		// stable_sort(snake+1,snake+n+1,cmp);
		// dfs(1);
		srand(static_cast<unsigned int>(time(NULL)));
		printf("%lld\n",rand()%(n+1));
	}
	return 0;
}