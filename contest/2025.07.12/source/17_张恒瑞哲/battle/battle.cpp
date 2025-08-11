#include<bits/stdc++.h>
using namespace std; 

#define ll long long

const int MAXN = 150005;

struct pp{
	ll d,i;
};

pp mx[MAXN],my[MAXN],mz[MAXN];
ll tx[MAXN],ty[MAXN],tz[MAXN];


int main(){
	
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%lld%lld%lld",&mx[i].d,&my[i].d,&mz[i].d);
		tx[i] = mx[i].d;ty[i] = my[i].d;tz[i] = mz[i].d;
		mx[i].i = i;my[i].i = i;mz[i].i = i;
	}
	sort(mx+1,mx+1+n,[](pp a,pp b){return a.d > b.d;});
	sort(my+1,my+1+n,[](pp a,pp b){return a.d > b.d;});
	sort(mz+1,mz+1+n,[](pp a,pp b){return a.d > b.d;});
	
	int cnti,cntj,cntk;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			for(int k = 1;k <= n;++k){
				int a = mx[i].i,b = my[j].i,c = mz[k].i;
				if(a == b||a == c||b == c) continue;
				if(tx[b] >= tx[a] || tx[c] >= tx[a]) continue;
				if(ty[a] >= ty[b] || ty[c] >= ty[b]) continue;
				if(tz[a] >= tz[c] || tz[b] >= tz[c]) continue;
				printf("%lld",tx[a]+ty[b]+tz[c]);
				return 0;
			}
		}
	}
	printf("-1");
	
	return 0;
}
